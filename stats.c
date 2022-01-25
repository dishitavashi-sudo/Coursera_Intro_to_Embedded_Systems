/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c 
 * @brief c file for statistic calculation
 *
 * This file contains functions to calculate mean, median, maximum, minimum
 * and print these statistics.
 *
 * @author Dishita Vashi
 * @date 01/22/2022
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */

  unsigned char min = find_minimum(test, SIZE);
  unsigned char max = find_maximum(test, SIZE);
  float mean = find_mean(test, SIZE);
  float median = find_median(test, SIZE);
  print_statistics(mean, median, min, max);
  printf("Sorted array : \n");
  sort_array(test, SIZE);  
  print_array(test, SIZE);
}

/* Add other Implementation File Code Here */
void print_statistics(float mean, float median, unsigned char min, unsigned char max) {
	printf("Minimum is %u\n", min);
	printf("Maximum is %u\n", max);
	printf("Mean is %f\n", mean);
	printf("Median is %f\n", median);
	return;
}

void print_array(unsigned char *ptr, unsigned int size){
	int i;

	for(i = 0; i < size; i++) {
		printf("%u \t", ptr[i]);	
	}
	return;
}

static void sort_array_ascending(unsigned char *ptr, unsigned int size){
	unsigned char temp;
	int i, j;

	for(i = 0; i < size - 2; i++) {
		for(j = 0; j < size - 1; j++) { 
			if(ptr[j] > ptr[j+1]) {
				temp = ptr[j];
				ptr[j] = ptr[j+1];
				ptr[j+1] = temp;			
			}		
		}	
	}
	return;

}

/* This function calculates the median of all members of the given array */
float find_median(unsigned char *ptr, unsigned int size){
	
	sort_array_ascending(ptr, size);
	if(size % 2 == 0) {
		return (ptr[size/2] + ptr[(size/2) - 1]) / 2;	
	}
	else
		return ptr[size/2];
}

/* This function calculates the mean of all members of the given array */
float find_mean(unsigned char *ptr, unsigned int size){
	float sum = 0.0;
	int i;

	for(i = 0; i < size; i++)
		sum += ptr[i];

	return sum / size;
}

unsigned char find_minimum(unsigned char *ptr, unsigned int size){
	unsigned char min = ptr[0];
	int i;

	for(i = 1; i < size; i++) {
		if(ptr[i] < min)
			min = ptr[i];	
	}
	return min;
}

unsigned char find_maximum(unsigned char *ptr, unsigned int size){
	unsigned char max = ptr[0];
	int i;
	
	for(i = 1; i < size; i++) {
		if(ptr[i] > max)
			max = ptr[i];	
	}
	return max;
}

void sort_array(unsigned char *ptr, unsigned int size){
	sort_array_ascending(ptr, size);
	unsigned int size_var = size;
	int i;
	unsigned char temp;

	for(i = 0; i < (size/2) - 1; i++) {
		temp = ptr[i];
		ptr[i] = ptr[size_var - 1];
		ptr[size_var - 1] = temp;
		size_var--;
	}
	return;
}
