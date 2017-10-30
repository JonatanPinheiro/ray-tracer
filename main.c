#include <stdio.h>
#include <stdlib.h>
#include "objects.c"


// #define INPUT_SCENE_NAME "cenário.txt"
#define OUTPUT_IMAGE_NAME "imagem.pgm"
#define DEFAULT_IMAGE_WIDTH 640
#define DEFAULT_IMAGE_HEIGHT 480
#define DEFAULT_ANTIALIASING 3


int main(int argc, char *argv[]){
    int image_width = DEFAULT_IMAGE_WIDTH;
    int image_height = DEFAULT_IMAGE_HEIGHT;
    int antialiasing = DEFAULT_ANTIALIASING;
    FILE *output_image = fopen(OUTPUT_IMAGE_NAME, "w");


    if(output_image == NULL){
        printf("Houve um erro ao criar o aquivo \"%s\"\n", OUTPUT_IMAGE_NAME);
        return 1;
    }
    fprintf(output_image, "P3\n%i %i\n255\n", image_width, image_height);


    Sphere obj = {{0, 0, 51}, 50};


    for(int y = image_height/-2; y < image_height/2; y++){
        for(int x = image_width/-2; x < image_width/2; x++){

            Color pixel = {0, 0, 0};

            for(float j = 0; j < 1; j += 1.0 / antialiasing){
                for(float i = 0; i < 1; i += 1.0 / antialiasing){

                    Vector raio = {{0, 0, 0}, {x+i, y+j, image_width/2}};

                    if(sphere_collision(obj, raio)){
                        pixel.r += 0; // 44
                        pixel.g += 0; // 62
                        pixel.b += 0; // 80
                    } else{
                        pixel.r += 52;
                        pixel.g += 152;
                        pixel.b += 219;
                    }
                }
            }

            pixel.r /= (antialiasing*antialiasing);
            pixel.g /= (antialiasing*antialiasing);
            pixel.b /= (antialiasing*antialiasing);
            fprintf(output_image, "%i %i %i ", pixel.r, pixel.g, pixel.b);
        }
    }


    fclose(output_image);
    return 0;
}
