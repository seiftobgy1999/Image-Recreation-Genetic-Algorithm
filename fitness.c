#include "a4.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double comp_distance(const PIXEL *A, const PIXEL *B, int image_size){
  double distanceBetweenPixels = 0;
  double distance = 0;

  for (int i = 0; i < image_size; i++){
    distanceBetweenPixels = (A[i].r-B[i].r)*(A[i].r-B[i].r) + (A[i].g-B[i].g)*(A[i].g-B[i].g) + (A[i].b-B[i].b)*(A[i].b-B[i].b);
    distance += distanceBetweenPixels;
  }
  distance = sqrt(distance);
  return distance;
}


void comp_fitness_population(const PIXEL *image, Individual *individual, int population_size){

  for (int i = 0; i < population_size; i++){
    individual[i].fitness = comp_distance(image, individual[i].image.data, (individual[i].image.height*individual[i].image.width));
  }

}
