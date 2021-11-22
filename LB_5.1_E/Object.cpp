#include "Object.h"
double Object::count = 0;
Object::Object() { count++; }
double Object::Counter() { return count; }
