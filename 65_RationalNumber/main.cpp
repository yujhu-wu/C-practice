#include <iostream>
#include "RationalNumber.h"

using namespace std;

int main()
{
    RationalNumber rn(3,4), zero;
    cout << "Default constructor: " << zero << endl;
    cout << "==========Test operations with zero==========" << endl;
    try
    {
        cout << rn + zero << endl;
        cout << rn - zero << endl;
        cout << rn * zero << endl;
        cout << rn / zero << endl;
    }
    catch(runtime_error& e)
    {
        cout << e.what() << endl;
    }

    cout << endl;

    try
    {
        cout << zero + rn << endl;
        cout << zero - rn << endl;
        cout << zero * rn << endl;
        cout << zero / rn << endl;
    }
    catch(runtime_error& e)
    {
        cout << e.what() << endl;
    }
    cout << "==================Test ends==================" << endl;
    cout << endl;

    for ( size_t n = 0; n < 500; ++n )
    {
        RationalNumber rn1, rn2;
        cin >> rn1 >> rn2;

        cout << rn1 << " + " << rn2 << " = " << rn1 + rn2 << endl;
        cout << rn1 << " - " << rn2 << " = " << rn1 - rn2 << endl;
        cout << rn1 << " * " << rn2 << " = " << rn1 * rn2 << endl;
        cout << rn1 << " / " << rn2 << " = " << rn1 / rn2 << endl;

        cout << endl;
    }

    return 0;
}
