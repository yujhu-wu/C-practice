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
