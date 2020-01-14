#ifndef Vector_hpp
#define Vector_hpp

#include <stdio.h>
#include <iostream>
#include <stdlib.h>

class Vector{
private:
    float m_vector[3];
    
public:
    Vector();
    Vector(float, float, float);
    ~Vector();
    Vector operator+(const Vector& v);
    Vector operator-(const Vector& v);
    Vector operator*(const Vector& v);
    Vector operator/(const Vector& v);
    Vector operator*(float f);
    Vector operator/(float f);
    float dot(Vector v2);
    Vector normalize();
    float getX();
    float getY();
    float getZ();
};


#endif /* Vector_hpp */
