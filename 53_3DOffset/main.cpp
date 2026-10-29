#include <iostream>
#include "three_dimension_object.h"

using namespace std;

int main()
{
    unsigned int num_cases;
    cin >> num_cases;

    for ( unsigned int i = 1; i <= num_cases; ++i )
    {
        int x, y, z, xv, xa, yv, ya, zv, za;
        unsigned int num_par, t;
        input(num_par, t, x, y, z, xv, yv, zv, xa, ya, za); // implement input function

        ThreeDimensionObject object; // implement class ThreeDimensionObject
        switch(num_par) // implement overloaded member function initialize
        {
            case 2:
                object.initialize(x);
                break;
            case 3:
                object.initialize(x, y);
                break;
            case 4:
                object.initialize(x, y, z);
                break;
            case 5:
                object.initialize(x, y, z, xv);
                break;
            case 6:
                object.initialize(x, y, z, xv, yv);
                break;
            case 7:
                object.initialize(x, y, z, xv, yv, zv);
                break;
            case 8:
                object.initialize(x, y, z, xv, yv, zv, xa);
                break;
            case 9:
                object.initialize(x, y, z, xv, yv, zv, xa, ya);
                break;
            case 10:
                object.initialize(x, y, z, xv, yv, zv, xa, ya, za);
                break;
            default:
                break;
        }
        if ( num_par ) // implement member function output_position with default value
        {
            object.output_position(t);
        }
        else
        {
            object.output_position();
        }
    }

    return 0;
}
