#include <iostream>
#include "NQueens.h"

using namespace std;

int main()
{
    unsigned int nCases = 0;
    cin >> nCases;

    for ( unsigned int i = 1; i <= nCases; ++i)
    {
        NQueens nQueensObject;
        cin >> nQueensObject;

        cout << "Case " << i << ":" << endl;
        cout << "Before: " << nQueensObject.calculateAttacks();
        cout << "After : " << nQueensObject.solve() << endl;
    }

    return 0;
}
