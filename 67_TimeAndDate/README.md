# TimeAndDate

> C/C++ 程式設計練習 · [回到目錄](../README.md)

- **主題：** 繼承
- **語言：** C++
- **程式碼：** [main.cpp](main.cpp)、[TimeAndDate.cpp](TimeAndDate.cpp)、[TimeAndDate.h](TimeAndDate.h)

## 題目

The time function calculates the number of seconds passed since 1970/01/01. It is efficient for memory to record time by an integer values. To show the time in a friendly way for human beings, we can translate the value back to the universal time format. Your goal is to write a program to do such a translation. You have to write a class to store passed seconds since 1970/01/01 as an unsigned long integer value by using its constructor. The class also has to provide a method to print the time in universal time format as follows: MM/DD/YYYY HH:MM:SS Note that there are 29 days in February in a leap year, and 28 day in a normal year. The leap years occur every four years, do not occur every one hundred years, and do occur every four hundred years. Write a class TimeAndDate with the following capabilities:

1. A constructor with one argument as the elapsed time from 1970/01/01 00:00:00.
2. Proper accessor and mutator for the data members.
3. Overloaded stream insertion and extraction operator.
4. Applicable to the sample main file.

**Input**

The input has 500 cases. Each case contains an integer in a single line.

**Output**

For each case, output the time with the format mentioned above.

**Sample Input**

```
3359615270
2933630948
21414038
1043013166
```

**Sample Output**

```
06/17/2076 10:27:50
12/18/2062 01:29:08
09/05/1970 20:20:38
01/19/2003 21:52:46
```

## 程式碼

### main.cpp

```cpp
#include <iostream>
#include "TimeAndDate.h"

using namespace std;

int main()
{
    for ( unsigned int n = 1; n <= 500; ++n )
    {
        TimeAndDate tdObj;
        cin >> tdObj;
        cout << tdObj << endl;
    }

    return 0;
}
```

### TimeAndDate.cpp

```cpp
#include <iostream>
#include<iomanip>
#include "TimeAndDate.h"

using namespace std;

TimeAndDate::TimeAndDate(unsigned long int d):data(d),year(1970).month(1),day(0)
,hour(0),minute(0),second(0),leap(false),count(0)
{
}
void TimeAndDate::cal()
{
    unsigned long int x = data%86400;
    unsigned long int y = data/86400;

    hour=x/3600;
    x-=(3600*hour);
    minute=x/60;
    x-=(60*minute);
    second = x;

    while(y>=365){
        if(count>=30 && ((count-30)%400)==0){
            y-=366;
            ++count;
            continue;
        }
        if(count>=40 && ((count-30)%100)==0){
            y-=365;
            ++count;
            continue;
        }
        if(count%4==2){
            y-=366;
            ++count;
        }
        else{
            y-=365;
            ++count;
        }
    }
    year += count;
    if(((year%4)==0 && (year%100)!=0)||(year%400)==0){
        leap = true;
    }
    y++;
    while(y>=31){
        if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12){
                if(y==31){
                    break;
                }
                y-=31;
            }
        else if(month==4 || month==6 || month==9 || month==11){
            if(y==30){
                    break;
                }
                y-=30;
        }
        else if(month==2){
            if(leap){
                y-=29;
            }
            else{
                y-=28;
            }
        }
        ++month;
    }
    day=y;
    if(month==2){
        if(day>=29 && !leap){
            ++month;
            day-=28;
        }
    }
}
void TimeAndDate::print()
{
    cal();
    cout<<setfill('0')<<setw('2')<<month<<"/"<<setfill('0')<<setw('2')<<day<<"/"<<setfill('0')<<setw('2')<<year<<" ";
    cout<<setfill('0')<<setw('2')<<hour<<"."<<setfill('0')<<setw('2')<<minute<<"."<<setfill('0')<<setw('2')<<second<<end;
}
```

### TimeAndDate.h

```cpp
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
```

