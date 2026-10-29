#include <iostream>
#include "NQueens.h"

using namespace std;

void test_conversion1(unsigned int* p, size_t length);
void test_conversion2(NQueens nqObj);

int main()
{
    NQueens nQueensObject1; // default constructor as eight queens
    test_conversion1(nQueensObject1, nQueensObject1.getNumQueens()); // invoke conversion operator
    test_conversion2(nQueensObject1); // invoke copy constructor

    NQueens nQueensObject2(5); // constructor with one argument as number of queens
    nQueensObject1 = nQueensObject2; // invoke assignment operator
    nQueensObject1.calculateAttacks(); // calculate number of attacks
    cout << nQueensObject1; // overloaded stream insertion operator


    unsigned int nQueens = 0;
    cin >> nQueens;

    while( nQueens > 0 )
    {
        NQueens nQueensObject(nQueens); // constructor with one argument as number of queens
        cin >> nQueensObject; // overloaded stream extraction operator

        nQueensObject.calculateAttacks(); // calculate number of attacks
        cout << nQueensObject; // overloaded stream insertion operator

        cin >> nQueens;
    }

    return 0;
}

void test_conversion1(unsigned int* p, size_t length)
{
    for ( size_t i = 0; i < length - 1; ++i )
    {
        cout << p[i] << " ";
    }
    cout << p[length - 1] << ": ";
}

void test_conversion2(NQueens nqObj)
{
    cout << nqObj.calculateAttacks().getNumAttacks() << " Attacks" << endl;
}
