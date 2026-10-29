#include <iostream>
#include "NQueens.h"
using namespace std;
NQueens::NQueens ( int n )
    : Permutation ( n ){}
ostream &operator << ( std::ostream &output, const NQueens &theout )
{
    theout.call(  );
    return output;
}
istream &operator >> ( std::istream &input, NQueens &thein )
{
    int thenum;
    input >>  thenum ;
    thein.Permutation::setptr ( thenum );
    return input;
}
NQueens &NQueens::calculateAttacks()
{
    int x, y;
    Permutation::countattack();
    return *this;
}
NQueens &NQueens::solve ()
{
    Permutation::help();
    Permutation::countattack();
    return *this;
}
unsigned int NQueens::getNumAttacks()
{return attack;}
void NQueens::call(  )const
{
    Permutation::print( );
    cout << " = " << Permutation::returnattack(  ) << " Attacks" << endl;
}
