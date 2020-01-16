#include "a4.h"
#include <stdlib.h>
#include <stdio.h>


PIXEL *generate_random_image(int width, int height, int max_color){

  PIXEL *arrayPixel = malloc(sizeof(PIXEL)*width*height);

  for (int i = 0; i < height*width; i++){

      arrayPixel[i].r = rand() % (max_color + 1);
      arrayPixel[i].g = rand() % (max_color + 1);
      arrayPixel[i].b = rand() % (max_color + 1);
  }

  return arrayPixel;
}


Individual *generate_population(int population_size, int width, int height, int max_color){

  Individual *arrayIndividual = malloc(sizeof(Individual)*population_size);

  for (int i = 0; i < population_size; i++){
    arrayIndividual[i].image.data = generate_random_image(width, height, max_color);
    arrayIndividual[i].image.width = width;
    arrayIndividual[i].image.height = height;
    arrayIndividual[i].image.max_color = max_color;
  }

  return arrayIndividual;
}
