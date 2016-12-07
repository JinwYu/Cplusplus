#include <iomanip>
#include <ios>
#include <sstream>

#include "diver.h"


//Test if scores line has correct format
//Accepted line format: difficulty, followed by 7 scores, and (possibly) some text
//The 7 scores should be stored in array scores and
//difficulty should be stored in dif
//If the line has correct format then return true
//stringstreams are used, see sec. 11.9 of course book
//Reads the difficulty and scores.
bool test_scores_line(string line, double scores[], double &dif)
{
    //ADD CODE

    // Stream buffer.
    istringstream is(line);

    //1. First try to read the difficulty. If can't read. (btw difficulty is the first number in the line.)
    if(!(is >> dif))
    {
        return false;
    }
    //2. Read the scores.
    for(int i=0; i<NR_OF_REF; i++)
    {
        if(!(is >> scores[i])) //Read in the scores.
        {
            return false; // If there's not enough judges then return false.
        }
    }

    return true;
}



//Overload operator>> to read data for a diver d from stream in
//If errors were encountered while reading the data for a diver d
//then d.difficulty is set to a negative value
//Return the stream in
istream& operator>>(istream& in, Diver& d){
    //ADD CODE

    string line;

    //skip white spaces before and after name
    in >> ws;
    getline(in, d.name);    //read the first line into the name slot
    in >> ws;

    if(!d.name.empty()) //no need to continue if it's an empty line
    {
        getline(in,line); // Takes all of the numbers and adds into the string "line".

        //checks the correct format and reads in all of the data.
        if(!test_scores_line(line, d.points, d.difficulty))
        {   //if the format is wrong, set diff to -1. This item is then later skipped and written to log in read_divers in main
            d.difficulty = -1;
        }
    }
    return in;
}


//Calculate final score for diver d
//and store it in d.final_score
void calculate_final_score(Diver& d)
{
    //ADD COODE

    double temp = 0;

    //sort the points in the d.points[] array
    for (int i=0; i<(NR_OF_REF-1); i++)
        {
        for (int k=0; k<(NR_OF_REF-i-1); k++)
        {
            if (d.points[k] > d.points[k+1]) /* For decreasing order use < */
            {
                temp          = d.points[k];
                d.points[k]   = d.points[k+1];
                d.points[k+1] = temp;
            }
        }
    }

    float sum = 0;

    //calculate the sum
    for(int i=1; i<NR_OF_REF-1; i++) // starts at i = 1 to not include the lowest score. Also skips the highest (last) score.
    {
        sum += d.points[i];
    }
    sum /= 5; //average
    sum *= 3;
    sum *= d.difficulty;

    d.final_score = sum;
}


//Overload operator<< to write data for diver d
//to stream out: name and final score
ostream& operator<<(ostream& out, const Diver& d)
{
    //ADD CODE

    out << left << setw(25) << d.name;
    out << fixed << setprecision(1) << d.final_score << endl;

    return out;
}


//Overload comparison operator
//Return true if d1.final_score < d2.final_score
bool operator<(const Diver& d1, const Diver& d2)
{
    //ADD COODE

    if(d1.final_score < d2.final_score)
    {
        return true;
    }

    return false;
}

