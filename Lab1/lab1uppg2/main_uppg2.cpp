
#include <iostream>
#include <iomanip>
#include <fstream>
#include "diver.h"

//missed istream??
//#include <istream>

using namespace std;

/******************************
* 1. Functions declarations   *
*******************************/

//Read divers data from stream in and
//If correct diver's data then store a diver's record in array V
//If incorrect diver's data then write diver's name in log file
//Return number of divers read and stored in V
//V has n slots
//overloaded operator>> should be used in this function
int read_divers(istream& in, Diver V[], int n, ostream& log);


//Display all divers stored in array V to cout
//V stores n divers
//overloaded operator<< should be used in this function
void display(const Diver V[], int n);


//Sort V decreasingly by divers final score
//V stores n divers
//operator< should be used in this function
void sort_divers(Diver V[], int n);


/******************************
* 2. Main function            *
*******************************/



int main ()
{
    const int MAX_NR_OF_DIVERS = 50;
    int numberOfDivers = 0;

    //ADD CODE

    //an array with the divers
    Diver theDivers[MAX_NR_OF_DIVERS];

    //the in-file
    //ifstream inFile ("H:/C++/Code1/Uppg2/diver_data4.txt");
    ifstream inFile ("C:/Users/Jinwoo.Arsle/Desktop/TNG033 labbar offline/lab1 complete 151111/lab1uppg2/diver_data2.txt");


    //the out file
    //ofstream outFile ("H:/C++/Code1/Uppg2/test_out.txt");
    ofstream outFile ("C:/Users/Jinwoo.Arsle/Desktop/TNG033 labbar offline/lab1 complete 151111/lab1uppg2/test_out.txt");


    if(!inFile)
    {
        cout << "Could not open file";
    }
    else
    {
        //get number of divers
        numberOfDivers = read_divers(inFile, theDivers, MAX_NR_OF_DIVERS, outFile);
    }

    //Calculate final score for each diver
    for (int i = 0; i < numberOfDivers; i++ )
    {
        calculate_final_score(theDivers[i]);
    }

    //Sort divers decreasingly by final score
    sort_divers(theDivers, numberOfDivers);

    //Display divers
    cout << "\nDivers Results" << endl;
    cout << "=======================================" << endl;
    display(theDivers, numberOfDivers);

    return 0;
}


/******************************
* 3. Functions definitions    *
*******************************/


//Read divers data from stream in and
//If correct diver's data then store a diver's record in array V
//If incorrect diver's data then write diver's name in log file
//Return number of divers read and stored in V
//V has n slots
//overloaded operator>> should be used in this function
int read_divers(istream& in, Diver V[], int n, ostream& log)
{
    //ADD CODE

    int howMany = 0;

    while((howMany < n) && (in >> V[howMany])) //calls the overloaded operator >>.
    {
        if(V[howMany].difficulty != -1)
        {
            howMany++;
        }
        else
            log << V[howMany]; // Divers with an error in the input. Also overloaded << is called and outputs to a textfile.
    }

    return howMany;
}


//Display all divers stored in array V to cout
//V stores n divers
//overloaded operator<< should be used in this function
void display(const Diver V[], int n)
{
   //ADD CODE

   for(int i=0; i<n; i++)
    {
        cout << right << setw(3) << i+1 << ". ";
        cout << V[i]; //calls the overloaded << operator.
    }
}

//To be used by sort function
void swap(Diver& a, Diver& b)
{
    Diver temp = a;
    a = b;
    b = temp;
}



//Sort V decreasingly by divers final score
//V stores n divers
//operator< should be used in this function
void sort_divers(Diver V[], int n)
{
    //ADD CODE

    for (int i=0; i<(n-1); i++)
        {
        for (int k=0; k<(n-i-1); k++)
        {
            if (V[k] < V[k+1])
            {
                swap(V[k], V[k+1]);
            }
        }
    }
}



