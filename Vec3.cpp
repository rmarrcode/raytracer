#include "Vec3.h"
#include <cmath>

Vec3::Vec3() {
    x_ = 0;
    y_ = 0;
    z_ = 0;
}

Vec3::Vec3(long double x, long double y, long double z) {
    x_ = x;
    y_ = y;
    z_ = z;
}

long double Vec3::dot(Vec3 a, Vec3 b) {
    long double ans = 0;
    ans += a.x_ * b.x_;
    ans += a.y_ * b.y_;
    ans += a.z_ * b.z_;
    return ans;       
}

long double Vec3::length() {
    return sqrt(pow(x_,2) + pow(y_,2) + pow(z_,2));
}

void Vec3::normalise() {
    long double l = this->length();
    x_/=l; y_/=l; z_/=l;
}

long double* Vec3::getVals() {
    long double* temp = new long double[3];
    temp[0] = x_; temp[1] = y_; temp[2] = z_;
    return temp;
}
