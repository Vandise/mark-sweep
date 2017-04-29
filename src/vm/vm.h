#ifndef __VM_H__
#define __VM_H__ 1

#define STACK_MAX 256

#include "object/object.h"

class VM {

  public:
    Object* stack[STACK_MAX];
    int stackSize;
    Object* firstObject;
    int numObjects;
    int maxObjects;

  public:
    VM(int stackSize, int numObjects, int maxObjects);
    void push(Object* value);
    Object* pop();
    virtual ~VM();

};

#endif