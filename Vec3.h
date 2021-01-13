#ifndef VEC3
#define VEC3

class Vec3 {
    private:
        long double x_,y_,z_;
    public:
        Vec3(long double x, long double y, long double z);
        Vec3();
        static long double dot (Vec3 a, Vec3 b);
        void normalise();
        long double length();
        long double* getVals(); 
};

#endif

