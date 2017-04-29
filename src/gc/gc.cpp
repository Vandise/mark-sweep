#include "gc/gc.h"

GC::GC(VM* vm) {
  this->vm = vm;
}

void
GC::mark(Object *object) {
  if (object->marked) return;
  object->marked = 1;
}

void
GC::markAll() {
  for (int i = 0; i < this->vm->stackSize; i++) {
    this->mark(this->vm->stack[i]);
  }
}

void
GC::sweep() {
  Object** object = &this->vm->firstObject;
  while(*object) {
    if (!(*object)->marked) {
      Object* unreached = *object;
      *object = unreached->next;
      delete(unreached);
      this->vm->numObjects--;
    } else {
      (*object)->marked = 0;
      object = &(*object)->next;
    }
  }
}

void
GC::collect() {
  int numObjects = this->vm->numObjects;

  this->markAll();
  this->sweep();

  this->vm->maxObjects = this->vm->numObjects * 2;

  std::cout << "Collected " << (numObjects - this->vm->numObjects) << " " << this->vm->numObjects << " remaining." << std::endl;
}

GC::~GC() {
  this->vm = nullptr;
}