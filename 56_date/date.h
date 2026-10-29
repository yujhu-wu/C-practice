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
