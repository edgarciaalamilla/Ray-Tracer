#include <stdlib.h>
#include "Sphere.hpp"

Sphere::Sphere(float x, float y, float z, float r) :    center{Vector{x,y,z}}, 
                                                        radius{r},
                                                        ambient{Color(.1,.1,.1)},
                                                        specular{Color(1,1,1)}
                                                        {
    color = Color(  (float) rand() / (RAND_MAX + 1.0), 
                    (float) rand() / (RAND_MAX + 1.0), 
                    (float) rand() / (RAND_MAX + 1.0));
    diffuse = color;

    diffuse = color;
    shininess = (float) (rand() % 128) + 1;
}

Sphere::~Sphere(){ }

Vector Sphere::get_center(){
    return center;
}

Color Sphere::get_ambient(){
    return ambient;
}

Color Sphere::get_diffuse(){
    return diffuse;
}

Color Sphere::get_specular(){
    return specular;
}

Color Sphere::get_color(){
    return color;
}

float Sphere::get_radius(){
    return radius;
}

float Sphere::get_shininess(){
    return shininess;
}

float Sphere::calculate_Discriminant(Vector d, Vector o){
    return (d.dot(o-center) * d.dot(o-center)) - d.dot(d) * ((o - center).dot(o - center) - (radius * radius));
}

float Sphere::calculate_T(float discriminant,Vector d, Vector o){
    float t1, t2;
    Vector negDirection = Vector(0.0, 0.0, 1.0);
    
    t1 = (negDirection.dot(o-center) + discriminant) / d.dot(d);
    t2 = (negDirection.dot(o-center) - discriminant) / d.dot(d);
    
    return (t1 > t2) ? t2 : t1;
}