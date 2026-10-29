#include <iostream>
#include "Permutation.h"

using namespace std;

int main()
{
    Permutation permutation;
    cout << permutation++ << endl;
    cout << ++permutation << endl;
    cout << endl;

    Permutation permutationFirst, permutationSecond;

    cin >> permutationFirst;
    while ( cin.good() )
    {
        cin >> permutationSecond;

        cout << "The difference from " << permutationFirst << " to " << permutationSecond << " is " << permutationSecond - permutationFirst << "." << endl;
        cout << "The next permutation of " << permutationFirst << " is ";
        cout << ++permutationFirst << "." << endl;
        cout << "The next permutation of " << permutationSecond++ << " is ";
        cout << permutationSecond << "." << endl;
        cout << endl;

        cin >> permutationFirst;
    }

    return 0;
}
