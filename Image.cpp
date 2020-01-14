//
//  Image.cpp
//  RayTracer
//
//  Created by Peck, Tabitha on 10/15/16.
//  Copyright © 2016 Davidson College. All rights reserved.
//

#include "Image.hpp"

//
//  ImageProcessor.cpp
//  Resolution
//
//  Created by Tabitha Peck on 7/23/13.
//  Copyright (c) 2013 Tabitha Peck. All rights reserved.
//  based on code from stack overflow: http://stackoverflow.com/questions/2693631/read-ppm-file-and-store-it-in-an-array-coded-with-c


/*
 Create a new blank image
 */
//default constructor

Image::Image(){
    width = DEFAULT_DIM;
    height = DEFAULT_DIM;
    depth = DEFAULT_DEPTH;

    init_m_image();
}

//parameterized constructor
Image::Image(int width, int height, int depth) : width{width}, height{height}, depth{depth}{ init_m_image(); }

void Image::init_m_image(){
    m_image = new Color* [width];

    for(int i = 0; i < width; i++){
        m_image[i] = new Color[height];

        for(int j = 0; j < height; j++){
            m_image[i][j] = Color();
        }
    }
}

Image::~Image(){
    for(int i = 0; i < width; i++) delete [] m_image[i];
    delete [] m_image;
}

void Image::setColor(int x, int y, Color color){
    m_image[x][y] = color;
}

void Image::addColor(int x, int y, Color color){
    m_image[x][y] = m_image[x][y] + color;
    m_image[x][y].clamp();
}

int Image::getWidth(){
    return width;
}

int Image::getHeight(){
    return height;
}

Color** Image::getImage(){
    return m_image;
}

void Image::writeImage(const char* file_name){
    FILE* file;

    
    if(!(file = fopen(file_name, "w"))){
        fprintf(stderr, "Unable to open file %s\n", file_name);
        exit(1);
    }

    fprintf(file, "P3\n");
    fprintf(file, "# CREATOR: Eddie Garcia-Alamilla\n");
    fprintf(file, "%d %d\n%d\n", width, height, depth);

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            Color color = m_image[j][i] * depth;
            fprintf(file, "%d %d %d\n", (int)color.get_r(), (int)color.get_g(), (int)color.get_b());
        }
    }
    
    fclose(file);
}