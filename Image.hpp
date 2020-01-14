//
//  Image.h
//  ppmReaderWriter
//
//  Created by Peck, Tabitha on 9/18/14.
//  Copyright (c) 2014 Davidson College. All rights reserved.
//

#ifndef Image_hpp
#define Image_hpp

#include <stdio.h>
#include <iostream>
#include <stdlib.h>

#include "Color.hpp"

//default dimensions
#define DEFAULT_DIM 1000
#define DEFAULT_DEPTH 255

using namespace std;

class Image{
public:
    Image();
    Image(int w, int h, int max);
    ~Image();

    void writeImage(const char* file_name);
    int getWidth();
    int getHeight();
    
    void setColor(int, int, Color);
    void addColor(int, int, Color);

    Color** getImage();

private:
    int width;
    int height;
    int depth; 

    Color** m_image;

    void init_m_image();
};

#endif /* Image_hpp */
