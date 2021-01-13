#include <cstdlib> 
#include <cstdio> 
#include <cmath> 
#include <fstream> 
#include <vector> 
#include <iostream> 
#include <cassert> 

#include "sphere.h"
#include "Vec3.h"

float screen[500][500];

void render(std::vector<sphere>* scene) {    
    std::ofstream ofs("./image.ppm", std::ios::out | std::ios::binary); 
    ofs << "P6\n" << 500 << " " << 500 << "\n255\n"; 
    Vec3 eye(250,-250,250);
    long double* eyearr = eye.getVals();
    for (int i = 0; i < 500; i++) {
        for (int j = 0; j < 500; j++) {
            Vec3 screenpt((float(i)/500*500), ((float(j)/500)*-500), 0); 
            long double* screenptarr = screenpt.getVals();
            Vec3 ray(screenptarr[0]-eyearr[0], screenptarr[1]-eyearr[1], screenptarr[2]-eyearr[2]);
            ray.normalise();
            sphere* closestSphere = NULL;
            for (auto object : (*scene)) {
               closestSphere = &object;
               Vec3 center = object.getPosition();
               long double* centerarr = center.getVals();
               Vec3 L(centerarr[0]-eyearr[0], centerarr[1]-eyearr[1], centerarr[2]-eyearr[2]);
               long double Tca = Vec3::dot(L,ray);
               long double d = sqrt(Vec3::dot(L,L) - pow(Tca,2));
               float radius = object.getRadius();                   
               if (Tca < 0 || d < 0 || d > radius) {
                closestSphere = NULL;  
               };
            }
            if (closestSphere) {
                Vec3 color = (*closestSphere).getColor(); 
                long double* colorarr = color.getVals();
                ofs << (unsigned char)(colorarr[0]) <<
                       (unsigned char)(colorarr[1]) << 
                       (unsigned char)(colorarr[2]); 
            }
            else {
                 ofs << (unsigned char)(0) <<     
                       (unsigned char)(0) << 
                       (unsigned char)(0); 
            }
        }
    }
    ofs.close(); 
}

int main () {
    std::vector<sphere> scene;
    Vec3 pos(250, -250, -500);
    Vec3 color(150,66,66);
    sphere s(pos, 50, color);
    scene.push_back(s);
    
    render(&scene);
}
