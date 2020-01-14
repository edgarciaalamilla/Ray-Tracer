#include "Scene.hpp"

Scene::Scene(const char *destination) : destination{destination} {}

void Scene::createScene(){
    Vector lightSource, direction, origin;
    Color lightColor;
    vector<Sphere> spheres;

    Image image = Image();
    
    lightSource = Vector(500,500,5);
    direction = Vector(0, 0, -1);
    lightColor = Color(0,0,0);  //diffuse + specular + ambient will be added to this later
    
    //add spheres to scene
    for (int i = 50; i < image.getHeight(); i+=100){
        for (int j = 50; j < image.getWidth(); j+=100){
            Sphere sphereOne = Sphere(i,j,-500, 50);
            spheres.push_back(sphereOne);
        }
    }
    
    //above should be constructor

    while (spheres.size() > 0){
        Sphere sphere = spheres.back(); //get sphere
        for(int i = 0; i < image.getWidth(); i++){
            for(int j = 0; j < image.getHeight(); j++){
                
                origin = Vector(i, j, 0);
                
                float discriminant = sphere.calculate_Discriminant(direction, origin);
                
                if (discriminant > 0){
                    
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
                    
                    //calculate and clamp lightcolor
                    lightColor = (sphere.get_ambient() + diffuse + specular);
                    lightColor.clamp();
                    Color mixColor = (lightColor * 0.8 + sphere.get_color() * 0.2);
                    mixColor.clamp();
                    
                    //set color in image
                    image.setColor(i, j,mixColor);
                }
            }
        }
        lightColor = Color(0,0,0);
        spheres.pop_back();
    }
    
    image.writeImage(destination);
}