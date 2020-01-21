#include "Scene.hpp"
#include <vector>

Scene::Scene(const char *destination) : destination{destination} {
    lightSource = Vector(500,500,5);
    direction = Vector(0, 0, -1);

}

Scene::~Scene(){}

// void Scene::addSpheres(Image image, vector<Sphere> &spheres){
//     for (int i = 50; i < image.getHeight(); i+=100){
//         for (int j = 50; j < image.getWidth(); j+=100){
//             Sphere sphere = Sphere(i,j,-500, 50);
//             spheres.push_back(sphere);
//         }
//     }
// }

Color Scene::calcPixelColor(Sphere sphere, float discriminant, Vector origin){
    discriminant = sqrt(discriminant);  //take square root of discriminant
                    
    float t1 = sphere.calculate_T(discriminant, direction, origin);    //get smallest t
    
    //good ol' vector calculations
    Vector pixel = (origin + direction*t1);
    Vector vertex_to_light = lightSource - pixel;
    Vector bisector = ((origin - pixel) + vertex_to_light).normalize();
    Vector normalized_normal = ((pixel - sphere.get_center()) / sphere.get_radius()).normalize();
    Vector normalized_vertex_to_light = vertex_to_light.normalize();
    Vector normalized_vertex_to_eye = (origin - pixel).normalize();
    
    //calculate diffuse and specular terms
    float diffuseTerm = max((float)0.0,normalized_normal.dot(normalized_vertex_to_light));
    float specularTerm = max((float)0.0, bisector.dot(normalized_normal));
    
    //diffuse and specular colors
    Color diffuse = sphere.get_diffuse() * diffuseTerm;
    Color specular = sphere.get_specular() * pow(specularTerm,sphere.get_shininess());
    
    //clamp diffuse and specular
    diffuse.clamp();
    specular.clamp();
    
    //light color calculated here
    Color color = sphere.get_ambient() + diffuse + specular;
    color.clamp();

    //pixel color calculated here
    color = color * 0.7 + sphere.get_color() * 0.3;
    color.clamp();
    
    return color;
}

void Scene::createImage(){

    Image image = Image();
    vector<Sphere> spheres;

    for (int i = 50; i < image.getHeight(); i+=100){
        for (int j = 50; j < image.getWidth(); j+=100){
            Sphere sphereOne = Sphere(i,j,-500, 50);
            spheres.push_back(sphereOne);
        }
    }

    //addSpheres(image, spheres);

    while (spheres.size() > 0){

        Sphere sphere = spheres.back();

        int x = (int) sphere.get_center().getX();
        int y = (int) sphere.get_center().getY();
        int radius = (int) sphere.get_radius();

        for(int i = x - radius; i < x + radius; i++){
            for(int j = y - radius; j < y + radius; j++){
                
                Vector origin = Vector(i, j, 0);
                float discriminant = sphere.calculate_Discriminant(direction, origin);
                
                if (discriminant > 0){
                    Color color = calcPixelColor(sphere, discriminant, origin); 
                    image.setColor(i, j, color);
                }
            }
        }
        spheres.pop_back();
    }

    image.writeImage(destination);

}