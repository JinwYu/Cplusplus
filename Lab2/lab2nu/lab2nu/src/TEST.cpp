#include <iostream>
#include <iomanip>


using namespace std;


void visahurochfunkar(int term1, int term2, int &svar){

    svar = term1 + term2;
}


int main()
{
    int svar = 0;
    int a = 5;
    int b = 10;

    cout << "Variabeln svar is likamed: " << svar << " innan funktionen har runned" << endl;

    visahurochfunkar(a, b, svar);

    cout << "Svaret �r: " << svar << endl;
    return 0;
}
