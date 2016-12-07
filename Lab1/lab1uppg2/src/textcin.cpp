#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main ()
{
    int k = 0;
    int tsize = 10;
    int  a[tsize];

    while(k < 10){
        if(!(cin >> a[k])){
            cout << "japp";
        }
        k++;
    }




    return 0;
}
