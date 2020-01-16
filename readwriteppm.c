#include "a4.h"
#include <stdlib.h>
#include <stdio.h>

PPM_IMAGE *read_ppm(const char *file_name){

  PPM_IMAGE *imageReturn = malloc(sizeof(PPM_IMAGE));

  int maxColor;
  int height;
  int width;

  /* Opens the file and checks if it is openable */

  FILE *file = fopen(file_name,"r");

  if (file == NULL){
    printf("Error! opening file");
    exit(1);
  }

  /* Gets the width, height, and maxColor */

  fscanf(file,"%*s \n %d %d \n %d \n", &width, &height, &maxColor);

  imageReturn->height = height;
  imageReturn->width = width;
  imageReturn->max_color = maxColor;

  /* This part of the code enters all the values into an array */

  PIXEL *arrayPixel = malloc(sizeof(PIXEL)*width*height);

  int red;
  int green;
  int blue;
  int widthCounter = 0;

  PIXEL *dataPointer = arrayPixel;

  for (int i = 0; i < height*width; i++){

    fscanf(file,"%u %u %u", &red, &green, &blue);

    arrayPixel[i].r = red;
    arrayPixel[i].g = green;
    arrayPixel[i].b= blue;

    widthCounter++;

    if (widthCounter == width){
      fscanf(file, "\n");
      widthCounter = 0;
    }
  }

  imageReturn->data = dataPointer;

  fclose(file);

  return imageReturn;

}

void write_ppm(const char *file_name, const PPM_IMAGE *image){

  FILE *file = fopen(file_name, "w");

  fprintf(file, "P3\n%d %d\n%d\n", image->width, image->height,image->max_color);

  int imageWidth = image->width;

  int imageHeight = image->height;

  PIXEL *dataPoint = image->data;

  int widthCounter = 0;

  for (int i = 0; i < imageHeight*imageWidth; i++){

    fprintf(file,"%d %d %d ", (dataPoint[i].r), (dataPoint[i].g), (dataPoint[i].b));

    widthCounter++;

    if (widthCounter == imageWidth){
      fprintf(file, "\n");
      widthCounter = 0;
    }
  }

  fclose(file);

}
