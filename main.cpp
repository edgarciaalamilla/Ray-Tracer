#include <math.h>
#include <vector>
#include "Image.hpp"
#include "Vector.hpp"
#include "Sphere.hpp"
#include "Color.hpp"
#include "raycaster.hpp"
#include "plane.hpp"

#define width 1000   //width 1000

vector<Sphere> spheres;
vector<Sphere> allSpheres;
float** depthBuffer;  //for depth


Image image = Image(width, width, 255);   //image 1000 by 1000

Color lightColor;
Vector lightSource, cameraLocation, direction, origin, planePoint, planeNormal;      //cameraLocation for perspective projection -> see raycaster vector equations

void initDepthBuffer(){     //initialize depth buffer to specified number
    depthBuffer = new float*[width];
    
    for (int i = 0; i < width; i++) {
        depthBuffer[i] = new float[width];
    }
    
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < width; j++) {
            depthBuffer[i][j] = (float)INFINITY; //set depth buffer to large number, will be changed later
        }
    }
}


void freeDepthBuffer(){     //freeeee
    for (int i = 0; i < width; i++) {
        free(depthBuffer[i]);
    }
    free(depthBuffer);
}

int main(int argc, const char * argv[]) {
    srand(static_cast<unsigned int>(time(NULL)));
    
    initDepthBuffer();
        
    lightSource = Vector(500,450,150);  //light source
    //direction = Vector(0, 0, -1);     //direction of rays, used only for finding pixel
    //direction needs to be from origin to pixel, 
    lightColor = Color(0,0,0);        //light color will be added to image later
    cameraLocation = Vector(500,500,500);   //create camera location, pass onto raycaster
    
    Raycaster raycaster = Raycaster(lightSource, cameraLocation, lightColor);  //raycaster defaults
    Plane plane = Plane(500,600,-100);
    
//    for (int i = 50; i < image.getWidth(); i+=100){  //add spheres to scene
//        for (int j = 50; j < image.getHeight(); j+=100){
//            Sphere sphereOne = Sphere(i,j,-500, 50);
//            spheres.push_back(sphereOne);
//        }
//    }
    
    Sphere sphereOne = Sphere(500, 500, -200, 100);
    Sphere sphereTwo = Sphere(365, 520, -100, 80);
    Sphere sphereThree = Sphere(575, 550, -100, 50);
    spheres.push_back(sphereOne);
    spheres.push_back(sphereTwo);
    spheres.push_back(sphereThree);
    
    for (int i = 0; i < spheres.size(); i++){
        Sphere sphere = spheres[i]; //get sphere
        for(int j = 0; j < image.getWidth(); j++){
            for(int k = 0; k < image.getHeight(); k++){
                /*  we might need to initialize the plane first to make things easier?
                 after plane is set, we can just add the spheres to the scene
                 to make sure that they're sitting on the plane and not
                 floating in space
                 we could add shadows in the raycaster, would require equation for a plane
                 so the idea would be that both descriminants for plane and sphere would
                 have to be > 0 for a pixel to be colored black, but not sure how shadows
                 on spheres would work.
                 */
                
                raycaster.color_pixel(j,k, sphere, &image, depthBuffer, plane, spheres, i); //pass in vector array of spheres
            }
        }
    }

    //objects use similar stuff
    
    freeDepthBuffer();  //free depth buffer
    image.writeImage("/Users/eddiegarcia-alamilla/desktop/tst/test-no_shadows.ppm");
    return 0;

}
