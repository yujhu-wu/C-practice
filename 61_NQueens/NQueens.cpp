#include <iostream>
#include "NQueens.h"
using namespace std;
NQueens::operator unsigned int * () const
{return ptr;}
NQueens::NQueens ( int n ): number ( n ), ptr ( new unsigned int [ n ] )
{
    for ( size_t i=0; i< number; ++i ){
        ptr [i] = (unsigned int )i;
    }
}
unsigned int NQueens::getNumQueens ()
{return number;}
NQueens::~NQueens (  )
{delete [] ptr;}
NQueens::NQueens ( const NQueens &thecopy ):number ( thecopy.number ),ptr ( new unsigned int [ number ] )
{
    for ( size_t i = 0; i < number; ++i ){
        ptr [ i ] = thecopy.ptr [ i ];
    }
}
const NQueens &NQueens::operator= ( const NQueens &right )
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
ostream &operator << ( std::ostream &output, const NQueens &theout )
{
    for ( size_t i = 0; i < theout.number - 1; ++i ){
        output << theout.ptr [ i ] << " ";
    }
    output << theout.ptr [ theout.number - 1 ] << ": ";
    output << theout.attack << " Attacks" << endl;
    return output;
}
istream &operator >> ( std::istream &input, NQueens &thein )
{
    for ( unsigned int i = 0; i < thein.number ; ++i ){
        for ( unsigned int j = 0; j < thein.number; ++j ){
            int queen;
            input >> queen;
            if ( queen == 1 ){
                thein.ptr [ i ] = j;
            }
        }
    }return input;
}
NQueens &NQueens::calculateAttacks()
{
    int a, b;
    for ( int k = 0; k < number - 1; ++k ){
        for ( int l = k + 1; l < number; ++l ){
            a = l - k;
            b = ptr [ l ] - ptr [ k ];
            if ( b < 0 ){
                b *= -1;
            }
            if ( a == b ){
                attack += 1;
            }
        }
    }return *this;
}
unsigned int NQueens::getNumAttacks()
{return attack;}
