#ifndef __GC_H__
#define __GC_H__ 1

#include <iostream>

#include "vm/vm.h"
#include "object/object.h"

class GC {

  private:
    VM* vm;

  public:
    GC(VM* vm);
    void mark(Object *object);
    void markAll();
    void sweep();
    void collect();
    ~GC();

};

#endif