#include <iostream>
#include <iomanip>

#include "statistics.h"

using namespace std;

/******************************
* 1. Functions declarations   *
*******************************/

//Read a sequence of values from cin and store them in array a
//Array a has n slots
//Return how many values were read and stored in a
int read_seq(int A[], int size);


//Display all values stored in array a to cout
//array a stores n integers
//At most, 10 values per line should be displayed
void display(const int A[], int n);


//Copy n values from array *from* into array *to*
void copy_list(int to[], int from[], int n);


//Sort array a
//a is an array storing n values
//Use a sorting algorithm different from bubblesort, e.g. selection sort, insertion sort
void sort_list(int A[], int n);


//swap the values of parameters a and b
//to be used by sort function
void swap(int& a, int& b);



/******************************
* 2. Main function            *
******************************/


int main ()  //DO NOT MODIFY
{
    const int SIZE = 1000;

	int theNumbers[SIZE], theCopy[SIZE];

	int howMany = read_seq(theNumbers, SIZE);

	if (!howMany)
	{
	    cout << "No data given!!" << endl;
	    return 0;
	}

	cout << "Sequence size = " << howMany << endl;

	copy_list(theCopy, theNumbers, howMany);
	sort_list(theCopy, howMany);

	cout << "\nList of values not sorted" << endl;
	display(theNumbers, howMany);
	cout << endl;

	cout << "\nList of sorted values" << endl;
	display(theCopy, howMany);
	cout << endl;

	int max = 0, min = 0;

	max = max_min(theNumbers, howMany, min);
	cout << "\n\nMax = " << max
	     << " and Min = " << min << endl;

	double theMean = mean(theNumbers, howMany);
	cout << "Average = " << theMean << endl;

	double theMedian = median (theCopy, howMany);
	cout << "Median = " << theMedian << endl;

	double theStandardDev = standard_deviation(theNumbers, howMany);
	cout << "Standard deviation = " << theStandardDev << endl;

	return 0;
}


/******************************
* 3. Functions definitions    *
*******************************/


//Read a sequence of values from cin and store them in array a
//Array a has n slots
//Return how many values were read and stored in a
int read_seq(int A[], int size)
{
    //ADD CODE

    int x;
    int counter = 0;

    //while there is an int to  read, read it to A
    //else check that the array has space left
    while(cin >> x && counter <= size)
    {
        A[counter] = x;
        counter++;
    }

	return counter;
}


//Display all values stored in array a to cout
//array a stores n integers
//At most, 10 values per line should be displayed
void display(const int A[], int n)
{
    //ADD CODE

    cout << "the array: ";
    for(int k=0; k<n; k++)
    {
        cout << A[k] << " ";
    }
}


//Copy n values from array *from* into array *to*
void copy_list(int to[], int from[], int n)
{
    //ADD CODE

    for(int k=0; k<n; k++)
    {
        to[k] = from[k];
    }
}


//Sort array a
//a is an array storing n values
//Use a sorting algorithm different from bubblesort
void sort_list(int A[], int n) //selection sort
{
   //ADD CODE

    for(int i=1; i<=n; i++)
    {
        for (int j=0; j<(n-1); j++)
        {
            if(A[j+1] < A[j]) //swap to ascending order
            {
                swap(A[j], A[j+1]);
            }
        }
    }
}

//swap the values of parameters a and b
//to be used by sort function
void swap(int& a, int& b)
{
    int temp = a;

	a = b;
	b = temp;
}


