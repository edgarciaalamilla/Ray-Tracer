#ifndef Scene_hpp
#define Scene_hpp

#include <math.h>
#include <vector>
#include "Image.hpp"
#include "Vector.hpp"
#include "Sphere.hpp"
#include "Color.hpp"

class Scene{
private:
    const char *destination;
    Vector lightSource;
    Vector direction;

    //void addSpheres(Image, std::vector<Sphere> &);
    Color calcPixelColor(Sphere, float, Vector);

public:
    Scene(const char* destination);
    ~Scene();
    void createImage();
};
#endif /* Color_hpp */
