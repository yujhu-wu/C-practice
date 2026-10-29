#include <iostream>
#include "Permutation.h"
#include <limits>

using namespace std;

int main()
{
    Permutation permutation1;
    cout << permutation1-- << endl;
    cout << --permutation1 << endl;
    cout << endl;

    Permutation permutationFirst, permutationSecond;

    cin >> permutationFirst;
    while ( cin.good() )
    {
        cin >> permutationSecond;

        cout << "The difference from " << permutationFirst << " to " << permutationSecond << " is " << permutationSecond - permutationFirst << "." << endl;
        cout << "The previous permutation of " << permutationFirst << " is ";
        cout << --permutationFirst << "." << endl;
        cout << "The previous permutation of " << permutationSecond-- << " is ";
        cout << permutationSecond << "." << endl;
        cout << endl;

        cin >> permutationFirst;
    }

    return 0;
}
