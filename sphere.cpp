#include "sphere.h"
#include "Vec3.h"

sphere::sphere(Vec3 position, float radius, Vec3 color) {
    position_ = position;
    radius_ = radius;
    color_ = color;
}

float sphere::getRadius() {
    return radius_;
}

Vec3 sphere::getPosition() {
    Vec3 temp = position_;
    return temp;
} 

Vec3 sphere::getColor() {
    Vec3 temp = color_;
    return temp;
}






