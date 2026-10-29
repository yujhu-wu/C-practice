#include <iostream>
#include "TheFiveElements.h"
using namespace std;

TheFiveElements::TheFiveElements (int state)
    :nown (state){}
ostream &operator<< (ostream &output, const TheFiveElements &e)
{
    static string elements[5] = {"Wood", "Fire", "Earth", "Metal", "Water"};
    output << elements[e.nown];
    return output;
}
istream &operator>> (istream &input, TheFiveElements &e2)
{
    input >> e2.nown;
    return input;
}
TheFiveElements &TheFiveElements::operator++ ()
{
    helpIncrement ();
    return *this;
}
TheFiveElements TheFiveElements::operator++ (int)
{
    TheFiveElements temp=*this;
    helpIncrement();
    return temp;
}
TheFiveElements &TheFiveElements::operator--()
{
    helpDecrement();
    return *this;
}
TheFiveElements TheFiveElements::operator--(int)
{
    TheFiveElements temp=*this;
    helpDecrement();
    return temp;
}
bool operator < (const TheFiveElements &thef ,const TheFiveElements &thes)
{
    if(thef.nown==0||thef.nown==2){
        if((thef.nown - thes.nown)==-2){
            return true;
        }
        else{
            return false;
        }
    }
    else if(thef.nown == 4||thef.nown == 3){
        if((thef.nown - thes.nown)==3){
            return true;
        }
        else{
            return false;
        }
    }
    else if(thef.nown==1 ){
        if((thef.nown - thes.nown)==-2){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

bool operator > (const TheFiveElements &thef ,const TheFiveElements &thes)
{
    if((thef.nown - thes.nown)==-1){
        if((thef.nown < thes.nown)){
            return true;
        }
        else{
            return false;
        }
    }
    else if(thef.nown==4 && thes.nown==0){
        return true;
    }
    else{
        return false;
    }
}

 void TheFiveElements::helpIncrement ()
 {
     if (nown<4){
         ++nown;
     }
     else{
         nown=0;
     }
 }
 void TheFiveElements::helpDecrement ()
 {
     if(nown>0){
         --nown;
     }
     else{
         nown=4;
     }
 }
