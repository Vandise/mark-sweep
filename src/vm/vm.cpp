#include "vm/vm.h"

VM::VM(int stackSize, int numObjects, int maxObjects)
{
  this->stackSize = stackSize;
  this->numObjects = numObjects;
  this->maxObjects = maxObjects;
  this->firstObject = nullptr;
}

void
VM::push(Object* value) {
  this->stack[this->stackSize++] = value;
}

Object*
VM::pop() {
  return this->stack[--this->stackSize];
}

VM::~VM() {

}