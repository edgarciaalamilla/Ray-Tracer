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

public:
    Scene(const char* destination);
    void createScene();
};
#endif /* Color_hpp */
