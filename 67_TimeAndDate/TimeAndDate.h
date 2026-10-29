#ifndef TIMEANDDATE_H
#define TIMEANDDATE_H
#include <string>

class TimeAndDate
{
public:
    explicit TimeAndDate(unsigned long int);
    void cal();
    void print();

private:
    unsigned long int data;
    unsigned long int year;
    int month, day;
    unsigned long int hour;
    unsigned long int minute;
    int second;
    bool leap;
    int count;
};
#endif // TIMEANDDATE_H
