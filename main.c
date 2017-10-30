#include <stdio.h>
#include <stdlib.h>
#include "objects.c"


// #define INPUT_SCENE_NAME "cenário.txt"
#define OUTPUT_IMAGE_NAME "imagem.pgm"
#define DEFAULT_IMAGE_WIDTH 640
#define DEFAULT_IMAGE_HEIGHT 480


int main(int argc, char *argv[]){
    int image_width = DEFAULT_IMAGE_WIDTH;
    int image_height = DEFAULT_IMAGE_HEIGHT;

    FILE *output_image = fopen(OUTPUT_IMAGE_NAME, "w");

    if(output_image == NULL){
        printf("Houve um erro ao criar o aquivo \"%s\"\n", OUTPUT_IMAGE_NAME);
        return 1;
    }

    Sphere obj = {{image_width/2, image_height/2, 10}, 50};


    fprintf(output_image, "P3\n%i %i\n255\n", image_width, image_height);

    for(int y = 0; y < image_height; y++){
        for(int x = 0; x < image_width; x++){
            Vector raio = {{x, y, 0}, {0, 0, 1}};

            if(sphere_collision(obj, raio)){
                fprintf(output_image, "0 0 0 ");
            } else{
                fprintf(output_image, "255 0 0 ");
            }

        }
    }


    fclose(output_image);
    return 0;
}
