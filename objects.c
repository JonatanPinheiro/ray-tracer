#include <stdio.h>
#include <math.h>


typedef struct point{
    float x, y, z;        // Coordinates
} Point;

typedef struct vector{
    Point o;            // Origin
    Point d;            // Direction
} Vector;

typedef struct sphere{
    Point c;            // Center
    double r;           // Radius
} Sphere;

typedef struct color{
    int r, g, b;      // Red, Green, Blue
} Color;



double module(Point v){
    return sqrt(v.x*v.x + v.y*v.y + v.z+v.z);
}

Point cross_product(Point a, Point b){
    Point answer = {a.y*b.z - b.y*a.z, a.x*b.z - b.x*a.z, a.x*b.y-b.x*a.y};
    return answer;
}

int sphere_collision(Sphere sphere, Vector ray){
    Point c = {sphere.c.x-ray.o.x, sphere.c.y-ray.o.y, sphere.c.z-ray.o.z};
    sphere.c = c;

    double distance = module(cross_product(ray.d, sphere.c)) / module(ray.d);

    if(distance < sphere.r){
        return 0;
    }
    return 1;
}
