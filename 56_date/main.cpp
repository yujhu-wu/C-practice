#include <iostream>
#include <stdexcept>
#include "date.h"
#include "date.h"

using namespace std;

int main()
{
    const Date date1; // default constructor: set elapsed days to zero
    date1.printDate(); // 01/01/1970 Thursday

    const Date date2(3652);  // constructor: with one argument of elapsed days
    date2.printDate(); // 01/01/1980 Tuesday

    try
    {
        const Date date3("02/29/2022");  // constructor: with one argument of string
        date3.printDate();
    }
    catch(invalid_argument &e)
    {
        cout << e.what() << endl;
    }

    try
    {
        const Date date4("02/29/2024");  // constructor: with one argument of string
        date4.printDate();
    }
    catch(invalid_argument &e)
    {
        cout << e.what() << endl;
    }

    cout << endl;

    unsigned int type;
    cin >> type;
    while ( type < 2 ) // end with input type == 2
    {
        Date date;

        if ( type ) // type 1: string as input
        {
            string str;
            getline(cin, str);
            try
            {
                date.setDate(str.substr(1));
                date.printElapsedDays(); // output the elapsedDays
            }
            catch(invalid_argument &e)
            {
                cout << e.what() << endl;
            }
        }
        else // type 0: integer as input
        {
            unsigned int elapsedDays;
            cin >> elapsedDays;
            date.setElapsedDays(elapsedDays);
            date.printDate(); // output the date
        }

        cin >> type;
    }

    return 0;
}
