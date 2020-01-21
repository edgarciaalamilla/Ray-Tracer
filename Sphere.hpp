#ifndef Sphere_hpp
#define Sphere_hpp

#include <stdio.h>
#include "Color.hpp"
#include "Vector.hpp"

class Sphere{
private:
    float radius;
    Vector center;
    Color ambient;
    Color specular;
    Color color;
    Color diffuse;
    float shininess;
    
public:
    Sphere(float, float, float, float);
    ~Sphere();
    Vector get_center();
    Color get_ambient();
    Color get_diffuse();
    Color get_specular();
    Color get_color();
    float get_shininess();
    float get_radius();
    float calculate_Discriminant(Vector, Vector);
    float calculate_T(float discriminant, Vector d, Vector o);
};

#endif /* Sphere_hpp */
