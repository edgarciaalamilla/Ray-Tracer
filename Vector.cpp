#include "Vector.hpp"
#include <math.h>

Vector::Vector(): m_vector{0.0, 0.0, 0.0} { }
Vector::Vector(float x, float y, float z) : m_vector{x, y , z}{ }

Vector::~Vector(){ }

Vector Vector::operator+(const Vector& other){
    return Vector(  m_vector[0] + other.m_vector[0], 
                    m_vector[1] + other.m_vector[1], 
                    m_vector[2] + other.m_vector[2]);
}

Vector Vector::operator-(const Vector& other){
    return Vector(  m_vector[0] - other.m_vector[0], 
                    m_vector[1] - other.m_vector[1], 
                    m_vector[2] - other.m_vector[2]);
}

Vector Vector::operator*(const Vector& other){
    return Vector(  m_vector[0] * other.m_vector[0], 
                    m_vector[1] * other.m_vector[1], 
                    m_vector[2] * other.m_vector[2]);
}

Vector Vector::operator/(const Vector& other){
    return Vector(  m_vector[0] / other.m_vector[0], 
                    m_vector[1] / other.m_vector[1], 
                    m_vector[2] / other.m_vector[2]);
}

Vector Vector::operator*(float f){
    return Vector(  m_vector[0] * f, 
                    m_vector[1] * f, 
                    m_vector[2] * f);
}

Vector Vector::operator/(float f){
    return Vector(  m_vector[0] / f, 
                    m_vector[1] / f, 
                    m_vector[2] / f);
}

float Vector::dot(Vector v2){
    return  (m_vector[0] * v2.m_vector[0]) + 
            (m_vector[1] * v2.m_vector[1]) + 
            (m_vector[2] * v2.m_vector[2]);
}

Vector Vector::normalize(){
    Vector normal = Vector();
    float v1 = sqrt(pow(m_vector[0], 2) + pow(m_vector[1], 2) + pow(m_vector[2], 2));
    normal.m_vector[0] = m_vector[0] / v1;
    normal.m_vector[1] = m_vector[1] / v1;
    normal.m_vector[2] = m_vector[2] / v1;
    return normal;
}

float Vector::getX(){
    return m_vector[0];
}

float Vector::getY(){
    return m_vector[1];
}

float Vector::getZ(){
    return m_vector[2];
}