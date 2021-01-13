#ifndef SPHERE
#define SPHERE

#include "Vec3.h"

class sphere { 
    private: 
        Vec3 position_;
        float radius_;
        Vec3 color_;
    public: 
        sphere(Vec3 position, float radius, 
               Vec3 color);
        float getRadius();
        Vec3 getPosition();
        Vec3 getColor();
}; 

 
#endif 
