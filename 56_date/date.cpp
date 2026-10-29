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
