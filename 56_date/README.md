# date

> C/C++ 程式設計練習 · [回到目錄](../README.md)

- **主題：** 類別
- **語言：** C++
- **程式碼：** [main.cpp](main.cpp)、[date.cpp](date.cpp)、[date.h](date.h)

## 題目

The date is a common attribute in real world. A date consists of month, day, and year. A simple method to record a date in computer is to use string. String is a class provided in c++ standard library. The use of string to record a date is the simplicity of input and output. Alternatively, we can store a date by checking the elapsed days from a given day, e.g., the well-known 01/01/1970. Use the elapsed days is efficient considering the memory usage. For the sake of convenience to humans, we can establish a class to store a date by its elapsed days, and provide it the capabilities of input from and output as elapsed days and string through constructor, accessor, mutator, and utility functions. Your goal is to write a class Date to provide the following capabilities:

1. A constructor to input from an integer as elapsed days with default value 0.
2. A constructor to input from a string in the format MM/DD/YYYY.
3. Proper mutators to set the elapsed days from integer and string with the ability to check invalid argument of string to distinguish where the input month, day, or year is invalid.
4. Proper member functions to print the elapsed days and the date in the format MM/DD/YYYY

Weekday.

5. The class must be applicable to the sample main file.

Prohibited: Use any C-style input/output.

**Input**

The input contains several cases in a single line and ends with 2. In each line, the first integer represents the type of the input. For type 0 an integer follows, while for type 1 a string of format MM/DD/YYYY follows.

**Output**

For each case, output the elapsed days for string input, and output the date in the format MM/DD/YYYY Weekday for integer input.

**Sample Input**

```
0 30333
0 12382
0 1842
1 01/01/1997
1 02/29/1981
1 13/07/1993
2
```

**Sample Output**

```
01/18/2053 Saturday
11/26/2003 Wednesday
01/17/1975 Friday
The elapsed days are 9862.
Invalid input day.
Invalid input month.
```

## 程式碼

### main.cpp

```cpp
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
```

### date.cpp

```cpp
#include <iomanip>
#include <stdexcept>
#include <iostream>
#include "date.h"
//add empty file name as date.cpp
using namespace std;


const unsigned int Date::monthsPerYear = 12;
Date::Date ( unsigned int ed, int mn, int dy, int yr  )
    : edays ( ed ), month ( mn ), day ( dy ), year ( yr )
{

}
void Date::printDate () const
{
    if ( month < 10 )
    {
        cout << 0 << month << '/';
    }
    else
    {
        cout << month << '/';
    }
    if ( day < 10 )
    {
        cout << 0 << day << '/';
    }
    else
    {
        cout << day << '/';
    }
    cout <<  year ;
    if ( theday == 0 )
    {
        cout << " Thursday" << endl;
    }
    else if ( theday == 1)
    {
        cout << " Friday" << endl;
    }
    else if ( theday == 2)
    {
        cout << " Saturday" << endl;
    }
    else if ( theday == 3)
    {
        cout << " Sunday" << endl;
    }
    else if ( theday == 4)
    {
        cout << " Monday" << endl;
    }
    else if ( theday == 5)
    {
        cout << " Tuesday" << endl;
    }
    else if ( theday == 6)
    {
        cout << " Wednesday" << endl;
    }

}
void Date::printElapsedDays ()
{
    cout << "The elapsed days are " << edays << "." << endl;

}

Date::Date ( string input )
{
    s = input;
    unsigned int mn, dy, yr;
    int daysPerMonth  [13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } ;

    mn = s [ 0 ] - '0';
    mn *= 10;
    mn += s[ 1 ] - '0';
    if ( mn > 0 && mn <= monthsPerYear )
    {
        month = mn;
    }
    else
    {
        throw invalid_argument ( "Invalid input month." );
    }

    dy = s [ 3 ] - '0';
    dy *= 10;
    dy += s[ 4 ] - '0';
    yr = s [ 6 ] - '0';
    yr *= 10;
    yr += s[ 7 ] - '0';
    yr *= 10;
    yr += s[ 8 ] - '0';
    yr *= 10;
    yr += s[ 9 ] - '0';
    year = yr;
    if ( month == 2 && dy == 29  && ( year % 400 == 0 ||
        year % 4 == 0 && year % 100 != 0 ) )
    {
        day = dy;
    }
    else if ( dy > 0 && dy <= daysPerMonth [ month ] )
    {
        day = dy;
    }
    else
    {
        throw invalid_argument ( "Invalid input day." );
    }



}
Date::Date ( int n )
{
    unsigned int sum = 0;
    unsigned int d;

    int daysPerMonth  [13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } ;
    year = 1970;

    while ( sum <= n )
    {
        if (  ( year % 400 == 0 || year % 4 == 0 && year % 100 != 0 ) )
        {
            sum += 366;
            year += 1;
        }
        else
        {
            sum += 365;
            year += 1;
        }
    }

    if (  ( year % 400 == 0 || year % 4 == 0 && year % 100 != 0 ) )
    {
        sum -= 366;
    }
    else
    {
        sum -= 365;
    }
    year -= 1;

    d = n - sum + 2 ;
    //std::cout << "d=" << d << std::endl;
    sum = 0;
    month = 1;
    while ( day > sum )
    {
        sum += daysPerMonth [ month ];
        month += 1;
    }
    sum -= daysPerMonth [ month + 1 ];
    day = d;

    theday = n % 7;

    edays = n;


}
void Date::setDate ( string input2)
{
    s = input2;
    unsigned int mn, dy, yr;
    unsigned int sum;

    mn = s [ 0 ] - '0';
    mn *= 10;
    mn += s[ 1 ] - '0';

    if ( mn > 0 && mn <= monthsPerYear )
    {
        month = mn;
    }
    else
        throw invalid_argument ( "Invalid input month." );
    dy = s [ 3 ] - '0';
    dy *= 10;
    dy += s[ 4 ] - '0';
    year = s [ 6 ] - '0';
    year *= 10;
    year += s[ 7 ] - '0';
    year *= 10;
    year += s[ 8 ] - '0';
    year *= 10;
    year += s[ 9 ] - '0';


    int daysPerMonth  [13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } ;

    if ( month == 2 && dy == 29  && ( year % 400 == 0 ||
        year % 4 == 0 && year % 100 != 0 ) )
    {
        day = dy;

    }
    else if ( dy > 0 && dy <= daysPerMonth [ month ] )
    {
        day = dy;
        //std::cout << "dy=" << dy << std::endl;

    }
    else
    {
        throw invalid_argument ( "Invalid input day." );
    }



    for ( int i = 1970; i < year ; ++i )
    {
        if (  ( i % 400 == 0 || i % 4 == 0 && i % 100 != 0 ) )
        {
            sum += 366;
        }
        else
        {
            sum += 365;
        }
    }

    for ( int j = 1; j < month; ++j )
    {
        if ( j == 2 )
        {
            if (  ( year % 400 == 0 || year % 4 == 0 && year % 100 != 0 ) )
            {
                sum += 29;
            }
            else
            {
                sum += 28;
            }
        }
        else
        {
            sum += daysPerMonth [ j ];
        }

    }
    sum += day;
    edays = sum -1;


}
void Date::setElapsedDays ( unsigned int elapsedDays )
{
    unsigned int sum = 0;
    unsigned int d;
    unsigned int ds = elapsedDays;

    int daysPerMonth  [13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } ;
    year = 1970;

    while ( sum <= ds )
    {
        if (  ( year % 400 == 0 || ( year % 4 == 0 && year % 100 != 0 ) ) )
        {
            sum += 366;
            year += 1;
        }
        else
        {
            sum += 365;
            year += 1;
        }
    }
    year -= 1;
    if (  ( year % 400 == 0 || year % 4 == 0 && year % 100 != 0 ) )
    {
        sum -= 366;
    }
    else
    {
        sum -= 365;
    }

    d = ds - sum  ;

    sum = 0;
    month = 1;

    while ( d >= sum )
    {
        if ( month == 2 )
        {
            if (  ( year % 400 == 0 || year % 4 == 0 && year % 100 != 0 ) )
            {
                sum += 29;
                month += 1;
            }
            else
            {
                sum += 28;
                month += 1;
            }
        }
        else
        {
            sum += daysPerMonth [ month ];
            month += 1;
        }

    }
    //std::cout << "sum=" << sum << std::endl;
    month -= 1;
    //std::cout << "sum=" << daysPerMonth [ month ] << std::endl;
    if ( month == 2 )
    {
        if (  ( year % 400 == 0 || year % 4 == 0 && year % 100 != 0 ) )
        {
            day = d - sum + 29 + 1;
        }
        else
        {
            day = d - sum + 28  + 1;
        }
    }
    else
    {
        day = d - sum + daysPerMonth [ month ] + 1 ;
    }






    theday = elapsedDays % 7;



}
```

### date.h

```cpp
#include <iomanip>
#include <stdexcept>
#include <iostream>

#ifndef DATE_H
#define DATE_H

class Date
{
public:
    static const unsigned int monthsPerYear;
    explicit Date ( unsigned int  = 0, int = 1, int = 1, int  = 1970 );

    void printDate () const;

    void printElapsedDays ();

    Date ( std::string input );


    Date ( int n );

    void setDate ( std::string input2);

    void setElapsedDays ( unsigned int elapsedDays );

private:
    unsigned int month;
    unsigned int day;
    unsigned int year;

    unsigned int theday;
    unsigned int edays;
    std::string s;


};

#endif // DATE_H
```

