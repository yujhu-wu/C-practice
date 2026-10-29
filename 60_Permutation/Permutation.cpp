#include <iostream>
#include "Permutation.h"
using namespace std;

Permutation::Permutation (int x) :number (x)
{
    for(int i=0; i<number; ++i){
        a[i]=i;
    }
}
istream &operator >> (istream &input, Permutation &ther)
{
    input >> ther.number;
    for(int j=0; j<ther.number;++j){
        input >> ther.a[ j ];
    }
    return input;
}
ostream &operator << ( ostream &output, const Permutation &ther2 )
{
    for ( int k=0;k<ther2.number; ++k ){
        output << ther2.a[k];
        if (k<(ther2.number-1))
        {output << " ";}
    }
    return output;
}
unsigned int operator - ( const Permutation &compare, const Permutation &compare2 )
{
    int k, hold;
    int flag = 0;
    unsigned int thecount = 0;
    int b[compare.number];
    for (int q = 0;q<compare2.number;++q )
    {
        b [q]=compare2.a[q];
    }
    while(flag!=compare2.number)
    {
        flag=0;
        for(int p=0; p<compare2.number; ++p){
            if (b[p]==compare.a[p]){
                flag += 1;
            }
        }
        ++thecount;
        k = compare2.number - 1;
        while(k>0 && b[k-1] >=b[k]){
            --k;
        }
        if(k<=0){
            double len=(double)compare2.number/2;
            for(int l=0;l<len ;++l){
                hold=b[l];
                b[l] =b[compare.number-l- 1];
                b[compare.number-l- 1]=hold;
            }
            continue;
        }
        int j = compare2.number - 1;
        while(b[j] <= b[k-1]){
            --j;}
        int temp=b[k-1];
        b [k-1]=b[j];
        b [j]=temp;
        j=compare2.number-1;
        while (k<j)
        {
            temp=b[k];
            b [k] = b [j];
            b [j]=temp;
            ++k;
            --j;
        }
    }
    return thecount-1;
}
Permutation &Permutation::operator++()
{
    help();
    return *this;
}
Permutation Permutation::operator++ (int)
{
    Permutation temp = *this;
    help ();
    return temp;
}
void Permutation::help()
{
    int k, hold;
    for(int o=0; o<1; ++o){
        k=number-1;
        while(k>-1 && a[k-1]>= a[k]){
            --k;
        }
        if(k<0){
            double len =(double)number/2;
            for(int l=0; l<len; ++l){
                hold=a[l];
                a[l] = a [number-l-1];
                a[number-l-1]=hold;
            }
            continue;
        }
        int j=number-1;
        while(a[j] <= a[k-1])
        {--j;}
        int temp =a[k-1];
        a[k-1]=a [j];
        a[j]=temp;
        j=number-1;
        while(k<j){
            temp=a[k];
            a[k]=a[j];
            a[j]=temp;
            ++k;
            --j;
        }
    }
}
