/********************************
* DO NOT MODIFY any declaration *
*********************************/

#ifndef STATISTICS_H
#define STATISTICS_H

#include <iostream>

using namespace std;

//Return the largest value stored in A
//Return the smallest value stored in A through reference argument min
//A is an array storing n ints
int max_min (const int A[], int n, int& min);


//Return the average of the values stored in array A
//A is an array storing n ints
double mean (const int A[], int n);


//Return the median of the values stored in A
//A is a sorted array storing n ints
//Median is the middle value in the sorted array, if n is odd
//Otherwise, the median is the average of the two middle values
double median (const int A[], int n);


//Returns the standard deviation of n integers stored in array A
double standard_deviation(const int A[], int n);

#endif
