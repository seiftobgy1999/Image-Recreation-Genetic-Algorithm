#include "a4.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int cmpfunc (const void * a, const void * b){
    const Individual *pA = a;
    const Individual *pB = b;

    double fitnessA = pA->fitness;
    double fitnessB = pB->fitness;

    if (fitnessA > fitnessB) return 1;
    if (fitnessA < fitnessB) return -1;
    return 0;
}

void progress(int totalGenerations, int current){

double currentPercentage = (current/totalGenerations)*100;

printf("Current Generations: %d\n", current);

}

static void helperfunction(Individual *individual, int population_size)
{
	for (int i = 0; i < population_size; i++)
	{
		free(individual[i].image.data);
	}
	free(individual);
}




PPM_IMAGE *evolve_image (const PPM_IMAGE *image, int num_generations, int population_size, double rate){

  srand(time(NULL));

  Individual *indPointer = generate_population(population_size, image->width, image->height, image->max_color);

  comp_fitness_population(image->data, indPointer, population_size);

  qsort(indPointer, population_size, sizeof(Individual),cmpfunc);

  printf("Total generations: %d\n\n", num_generations);

  for (int i = 0; i < num_generations; i++){
  	crossover (indPointer, population_size);
    mutate_population(indPointer, population_size, rate);
    comp_fitness_population(image->data, indPointer, population_size);
    qsort(indPointer, population_size, sizeof(Individual),cmpfunc);
    progress(num_generations, i);
  }

  PPM_IMAGE *copy = malloc(sizeof(PPM_IMAGE));
  PIXEL *copypixel = malloc(indPointer[0].image.width*indPointer[0].image.height* sizeof(PIXEL));
  copy->width = indPointer[0].image.width;
  copy->height= indPointer[0].image.height;
  copy->max_color = indPointer[0].image.max_color;
  int limit = indPointer[0].image.width*indPointer[0].image.height;
  int j = 0;
  while (j < limit)
  {	
	copypixel[j].r = indPointer[0].image.data[j].r;
        copypixel[j].g = indPointer[0].image.data[j].g;
	copypixel[j].b = indPointer[0].image.data[j].b;
	j++;
  }

  copy->data = copypixel;
  helperfunction(indPointer, population_size);	
  return copy;

}

void free_image(PPM_IMAGE *p){
	free(p -> data);  
	free(p);
  
}
