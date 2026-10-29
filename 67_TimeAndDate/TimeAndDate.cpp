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
