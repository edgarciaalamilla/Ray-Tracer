/*
 Authors: Eddie Garcia-Alamilla and Tucker Craig
 Time Spent: 12 hours
 */

#include "Scene.hpp"


int main(int argc, char * argv[]) {
    srand( static_cast<unsigned int>(time(NULL)));  //set random time seed

    if (argc != 2){
        fprintf(stderr, "Usage: ./main <destination/filename.ppm>\nExample: ./main /Users/camille/desktop/image.ppm\n");
        exit(1);
    }

    Scene scene = Scene(argv[1]);
    scene.createScene();

    return 0;
}
