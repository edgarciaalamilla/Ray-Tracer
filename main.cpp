#include "Scene.hpp"


int main(int argc, char * argv[]) {

    srand(time(NULL)); //set random time seed

    if (argc != 2){
        fprintf(stderr, "Usage: ./main <destination/filename.ppm>\n");
        exit(1);
    }

    Scene scene = Scene(argv[1]);
    scene.createImage();

    return 0;
}
