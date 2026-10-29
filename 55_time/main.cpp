#include <iostream>
#include <stdexcept>
#include "time.h"
#include "time.h"

using namespace std;

int main()
{
    const Time time1; // default constructor: set time to 00:00:00
    time1.getUniversalTime(); // 00:00:00

    const Time time2(12, 34, 59);  // constructor: with thee arguments of hour, minute, and second
    time2.getUniversalTime(); // 12:34:59

    const Time time3(86024);  // constructor: with one argument of elapsed seconds
    time3.getStandardTime(); // 11:53:44 PM

    cout << endl;

    unsigned int type;
    cin >> type;
    while ( type < 2 )
    {
        Time time;
        if ( type )
        {
            unsigned int elapsedSeconds;
            cin >> elapsedSeconds;

            time.setElapsedSeconds(elapsedSeconds);
            time.getStandardTime();
        }
        else
        {
            try
            {
                unsigned int hour, minute, second;
                cin >> hour >> minute >> second;
                time.setHourMinuteSecond(hour, minute, second);
                cout << time.getElapsedSeconds() << "s passed before ";
                time.getUniversalTime();
            }
            catch(invalid_argument &e)
            {
                cout << e.what() << endl;
            }
        }

        cin >> type;
    }

    return 0;
}
