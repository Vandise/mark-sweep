#include "common/garbage_collect.h"

VM* vm = new VM(0,0,8);
GC* gc = new GC(vm);

void clearVmStack() {
  vm->stackSize = 0;
  gc->collect();
}

Object*
newObject(ObjectType type) {
  if (vm->numObjects == vm->maxObjects) gc->collect();

  Object* object = new Object(type);
  object->type = type;
  object->next = vm->firstObject;
  object->marked = 0;

  vm->firstObject = object;
  vm->numObjects++;

  return object;
}

void
pushInt(int value) {
  Object* object = newObject(OBJ_INT);
  object->value = value;

  vm->push(object);
}

int
main( const int argc, const char **argv )
{
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 20; j++) {
      pushInt(i);
    }
    for (int k = 0; k < 20; k++) {
      vm->pop();
    }
  }
  clearVmStack();
  delete(gc);
  delete(vm);
  return 0;
}