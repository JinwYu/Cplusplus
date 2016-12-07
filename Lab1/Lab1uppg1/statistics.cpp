#include <iostream>
#include <cmath>

#include "statistics.h"


//Return the largest value stored in A
//Return the smallest value stored in A through reference argument min
//A is an array storing n ints
int max_min (const int A[], int n, int& min)
{
    //ADD CODE

    int max = A[0];
    min = max; //very large number

    for(int k=1; k<n; k++)
    {
        if(A[k] > max)  //if value in array is bigger than max, make it max
            max = A[k];

        if(A[k] < min)  //if value in array is smaller than min, make it min
            min = A[k];
    }

	return max;
}

//Return the average of the values stored in array A
//A is an array storing n ints
double mean (const int A[], int n)
{
    //ADD CODE

    float sum = 0;

    for(int k=0; k<n; k++)
    {
        sum += A[k];
    }

	return sum/n;
}


//Return the median of the values stored in A
//A is a sorted array storing n ints
//Median is the middle value in the sorted array, if n is odd
//Otherwise, the median is the average of the two middle values
double median (const int A[], int n)
{
    //ADD CODE

    double theMedian = 0.0;

    //check if n is odd or even
    if(n%2 == 0)
        theMedian = (double(A[n/2]) + double(A[(n/2)-1]))/2.0;
    else
        theMedian = A[(n-1)/2];

	return theMedian;
}


//Returns the standard deviation of n integers stored in array A
double standard_deviation(const int A[], int n)
{
    //ADD CODE

    double numSum = 0.0;
    double meanValue = mean(A, n);

    for(int k=0; k<n; k++)
    {
        numSum += pow( (double(A[k]) - meanValue), 2); // pow, raise the base number by 2.
    }

    double stdDev = sqrt(numSum/n);

    return stdDev;
}

