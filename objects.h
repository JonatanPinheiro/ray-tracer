typedef struct point Point;
typedef struct sphere Sphere;
typedef struct vector Vector;
typedef struct color Color;

double module(Point v);
Point cross_product(Point a, Point b);
int sphere_collision(Sphere sphere, Vector ray);
