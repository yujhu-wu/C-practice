#include <iostream>
#include "TimeAndDate.h"

using namespace std;

int main()
{
    for ( unsigned int n = 1; n <= 500; ++n )
    {
        TimeAndDate tdObj;
        cin >> tdObj;
        cout << tdObj << endl;
    }

    return 0;
}
