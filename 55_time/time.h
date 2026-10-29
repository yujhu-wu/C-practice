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
