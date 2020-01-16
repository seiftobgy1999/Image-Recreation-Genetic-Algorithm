#include "a4.h"
#include <stdlib.h>
#include <stdio.h>

void mutate(Individual *individual, double rate){

  int sizeImage =  (individual->image.height)*(individual->image.width);

  int max_color = individual->image.max_color;

  int numberPixel = (int) (rate/100*(sizeImage));

  int n;

  for (int i = 0; i < numberPixel; i++){
    n = rand () % (sizeImage);
    individual->image.data[n].r = rand () % (max_color);
    individual->image.data[n].g = rand () % (max_color);
    individual->image.data[n].b = rand () % (max_color);

  }

}

void mutate_population (Individual *individual, int population_size, double rate){

  int index = (population_size/4);

  for(int i = index; i < population_size; i++){
    mutate((individual + i), rate);
  }
}
    
