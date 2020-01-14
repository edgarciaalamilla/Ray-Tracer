//
//  Color.cpp
//  RayTracer
//
//  Created by Peck, Tabitha on 10/15/16.
//  Copyright © 2016 Davidson College. All rights reserved.
//

#include "Color.hpp"

//C++11 Constructors using initializer lists
Color::Color() : m_color{0.0, 0.0, 0.0} {}
Color::Color(float r, float g, float b) : m_color{r,g,b} {}

Color::~Color(){}

//operator overloaders
Color Color::operator+(const Color& other){
    return Color(   m_color[0] + other.m_color[0], 
                    m_color[1] + other.m_color[1],
                    m_color[2] + other.m_color[2]);
}

Color Color::operator-(const Color& other){
    return Color(   m_color[0] - other.m_color[0], 
                    m_color[1] - other.m_color[1], 
                    m_color[2] - other.m_color[2]);
}
Color Color::operator*(const Color& other){
    return Color(   m_color[0] * other.m_color[0], 
                    m_color[1] * other.m_color[1], 
                    m_color[2] * other.m_color[2]);
}

Color Color::operator/(const Color& other){
    return Color(   m_color[0] / other.m_color[0], 
                    m_color[1] / other.m_color[1], 
                    m_color[2] / other.m_color[2]);
}


Color Color::operator*(float f){
    return Color(   m_color[0] * f,    
                    m_color[1] * f, 
                    m_color[2] * f);
}

Color Color::operator/(float f){
    return Color(   m_color[0] / f, 
                    m_color[1] / f, 
                    m_color[2] / f);
}

float Color::get_r(){
    return m_color[0];
}

float Color::get_g(){
    return m_color[1];
}

float Color::get_b(){
    return m_color[2];
}

void Color::clamp(){
    for(int i = 0; i < 3; i++){
        if(m_color[i] > 1.0) m_color[i] = 1.0;
        else if(m_color[i] < 0.0) m_color[i] = 0.0;
    }
}
