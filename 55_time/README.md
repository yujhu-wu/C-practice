# time

> C/C++程式設計練習 · [回到目錄](../README.md)

- **主題**：類別
- **語言**：C++
- **程式碼**：[main.cpp](main.cpp)、[time.cpp](time.cpp)、[time.h](time.h)

## 題目

To record the trajectory of dynamic object, we require not only the positions of the moving object but the time at each position. For simplification, we can build a class of time to use. Write a class time with the following capabilities:

1. A default constructor set the time to 00:00:00.
2. A constructor with one argument as the elapsed time from 00:00:00.
3. A constructor with three arguments as the given hour, minute, and second.
4. Proper accessor and mutator for the data members with validity checking which would throw corresponding exception.
5. A utility function to set the hour, minute, and second from elapsed seconds.
6. Print functions to out the time in standard and universal format.
7. The class must applicable to the sample main file.

Prohibited: Use ctime library, and C-style input/output.

**Input**

The input contains several cases in a single line and ends with 2. In each line, the first integer represents the type of the input. For type 0 three integers denoting hour, minute, and second follow, while for type 1 an integer as elapsed seconds follows.

**Output**

For each case, output the elapsed seconds from the input time for type 0 and output the time in the universal time format HH:MM:DD for type 1.

**Sample Input**

```
1 55402
0 0 15 47
0 3 48 60
0 17 60 59
0 24 26 23
2
```

**Sample Output**

```
3:23:22 PM
947s passed before 0:15:47
Invalid input second.
Invalid input minute.
Invalid input hour.
```

## 程式碼

### main.cpp

```cpp
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
```

### time.cpp

```cpp
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "time.h"
//this is time.cpp

using namespace std;




Time::Time (  unsigned int elapsedSeconds , int h , int m , int s  )
    :    total ( elapsedSeconds ), hour ( h ), minute ( m ), second ( s )
{


}
Time::Time ( int ss )
{
    total = ss;
    hour = total /  ( 60 * 60  );
    total -= hour * ( 60 * 60 );
    minute = total / ( 60  );
    total -= minute * ( 60  );
    second = total;

}
Time::Time  (  int h, int m , int s )
{
    hour = h;
    minute = m;
    second = s;
}




void Time::getUniversalTime (  ) const
{

    cout << setfill ( '0' ) << setw ( 1 ) << hour << ":"
        << setw ( 2 ) << minute << ":" << setw ( 2 ) << second << endl;

}

void Time::getStandardTime (   ) const
{


    cout << ( (   hour == 12 ) ? 0 : hour % 12 )
        << ":" << setfill ( '0' ) << setw ( 2 ) << minute << ":"
        << setw ( 2 ) << second << " " << ( hour < 12 ? "AM" : "PM" ) << endl;

}


unsigned int  Time::getElapsedSeconds ( )
{
    int sum = 0;
    sum += second;
    sum += minute * 60;
    sum += hour * 60 * 60;
    return sum;
}

void Time::setElapsedSeconds ( unsigned int elapsedSeconds )
{
    total = elapsedSeconds;
    hour = total /  ( 60 * 60  );
    total -= hour * ( 60 * 60 );
    minute = total / ( 60  );
    total -= minute * ( 60  );
    second = total;

}

void Time::setHourMinuteSecond ( int h, int m, int s )
{
    int h1 = h;

    int m1 = m;
    int s1 = s;

    if (  ( h1 >= 0 && h1 < 24 ) && ( m1 >= 0 && m1 < 60 ) && ( s1 >= 0 && s1 < 60 ) )
    {
        hour = h;
        minute = m;
        second = s;

    }
    if ( ( h1 < 0 || h1 >= 24 ) )
    {
        //std::cout << "h1 = " << h1 << std::endl;
        throw invalid_argument ( "Invalid input hour." );

    }
    if ( ( m1 < 0 || m1 >= 60 ) )
    {
        throw invalid_argument ( "Invalid input minute." );

    }
    if ( ( s1 < 0 || s1 >= 60 ) )
    {
        throw invalid_argument ( "Invalid input second." );

    }




}
```

### time.h

```cpp
#include <iostream>
#include <iomanip>
#include <stdexcept>

#ifndef TIME_H
#define TIME_H


class Time
{
public:
    explicit Time (  unsigned int s = 0, int  = 0, int  = 0, int  = 0 );

    Time ( int ss );

    Time  (  int h, int m , int s );


    void getUniversalTime (  ) const;

    void getStandardTime (   ) const;


    unsigned int  getElapsedSeconds ( );

    void setElapsedSeconds ( unsigned int elapsedSeconds );


    void setHourMinuteSecond ( int h, int m, int s );



private:
    int hour, minute, second;
    unsigned int total;

};

#endif
```

