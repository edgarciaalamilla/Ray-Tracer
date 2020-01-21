# Ray-Tracer
A simple ray-tracer implemented in C++.

![Program output](https://raw.githubusercontent.com/edgarciaalamilla/Ray-Tracer/master/screenshot.jpg)

## How it works
A scene object is instantiated in main.cpp and calls its createImage() method. The scene object has a lightsource property that determines the light source location, and also has a direction property that indicates the direction that rays will go. When the scene object calls createImage(), a sphere vector is instantiated and spheres are added to the vector. Spheres are then taken from the array one by one. We then cast a ray from each pixel in the scene and determining whether the casted ray hits a sphere object on the scene. Lighting is then calculated by the phong lighting model, which takes into account the ambient color, diffuse color, and specular color. The phong lighting model requires that the light direction vector and the vector normal to the object be known. We utilize this information in calcPixelColor() and set the pixel color in the image.


## How to Compile/Run
To compile the program, use:
>g++ -std=c++11 -o raytrace Color.cpp Scene.cpp Sphere.cpp Vector.cpp Image.cpp main.cpp

To run the program, use:
>./raytrace <destination/imagename.ppm>
where destination is where you would like the image to appear and imagename is the name of the image.

### Developed in Computer Graphics 361
