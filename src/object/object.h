#ifndef __OBJECT_H__
#define __OBJECT_H__ 1

#include "common/types.h"

class Object {

  public:
    int value;
    ObjectType type;
    unsigned char marked;
    Object* next;
    Object(ObjectType type);
    virtual ~Object();

};

#endif