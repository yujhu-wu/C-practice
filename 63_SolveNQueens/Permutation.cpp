#include <iostream>
#include "Permutation.h"
using namespace std;
void Permutation::setptr ( int all )
{
    number = all;
    delete [] ptr;
    ptr = new unsigned int [ number ];
    for ( int i = 0; i < number; ++i ){
        cin >> ptr [ i ];
    }
}
Permutation :: Permutation ( int thenum ):number ( thenum ), ptr ( new unsigned int [ number ] ){}
Permutation::~Permutation (  )
{delete [] ptr;}
Permutation::Permutation ( const Permutation &thecopy ):number ( thecopy.number ),
     ptr ( new unsigned int [ number ] )
{
    for ( size_t i = 0; i < number; ++i ){
        ptr [ i ] = thecopy.ptr [ i ];
    }
}
const Permutation &Permutation::operator= ( const Permutation &right )
{
    if ( &right != this ){
        if ( number != right.number ){
            delete [ ] ptr;
            number = right.number;
            ptr = new unsigned int [ number ];
        }
        for ( size_t i = 0; i < number; ++i ){
            ptr [ i ] = right.ptr[ i ];
        }
    }return *this;
}
void Permutation::thecin ( )
{
    cin >> number;
    for ( int j = 0; j < number; ++j ){
        cin >> ptr [ j ];
    }
}
unsigned int* Permutation::print (  )const
{
    for ( int k = 0; k < number; ++k ){
        cout << ptr [ k ];
        if ( k < ( number - 1 ) ){
            cout << " ";
        }
    }return ptr;
}
void Permutation::help()
{
    int k;
    int hold;
    int flag = 0;
    unsigned int  a [ number ];
    for ( size_t i = 0; i < number; ++i ){
        a [ i ] =  ptr[ i ];
    }
    theattack = 0;
    for ( int o = 0; o < number - 1; ++o ){
        for ( int m = o + 1; m < number; ++m ){
            int x = m - o;
            int y = ptr [ m ] - ptr [ o ];
            if ( y < 0 ){
                y *= -1;
            }
            if ( x == y ){
                theattack += 1;
            }
        }
    }
    while ( flag <= number ){
        int x, y;
        int thea = 0;
        for ( int o = 0; o < number - 1; ++o ){
            for ( int m = o + 1; m < number; ++m ){
                x = m - o;
                y = a [ m ] - a [ o ];
                if ( y < 0 ){
                    y *= -1;
                }
                if ( x == y ){
                    thea += 1;
                }
            }
        }
        if ( thea >= theattack ){
            if ( flag >= 1 ){
                flag += 1;
            }
            else{
                flag = 1;
            }
        }
        else{
            theattack = thea;
            for ( int j = 0; j < number; ++j ){
                ptr [ j ] = a [ j ];
            }
            if ( flag >= 1 ){
                flag = 0;
            }
        }
        k = number - 1;
        while ( k > -1 && a [k-1] >= a [ k ] ){
            --k;
        }

        if ( k < 0 ){
            double len = ( double ) number / 2;
            for ( int l = 0; l < len ; ++l ){
                hold = a [ l ];
                a [l] = a [ number-l-1];
                a [number-l-1] = hold;
            }
            continue;
        }
        int j = number - 1;
        while ( a [ j ] <= a[k-1]){
            --j;
        }
        int temp = a [k-1];
        a [k-1] = a [j];
        a [ j ] = temp;
        j = number - 1;
        while ( k < j ){
            temp = a [ k ];
            a [ k ] = a [ j ];
            a [ j ] = temp;
            ++k;
            --j;
        }
    }
}
unsigned int Permutation::countattack ()
{
    theattack = 0;
    for ( int k = 0; k < number - 1; ++k ){
        for ( int l = k + 1; l < number; ++l ){
            int x = l - k;
            int y = Permutation::ptr [ l ] - Permutation::ptr [ k ];
            if ( y < 0 ){
                y *= -1;
            }
            if ( x == y ){
                theattack += 1;
            }
        }
    }
}
unsigned int Permutation::returnattack ()const
{   return ( unsigned int ) theattack;}
