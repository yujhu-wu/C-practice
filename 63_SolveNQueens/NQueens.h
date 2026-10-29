#ifndef NQUEEN_H
#define NQUEEN_H
#include <iostream>
#include "Permutation.h"
class NQueens : public Permutation
{
    friend std::ostream &operator << ( std::ostream &, const NQueens & );
    friend std::istream &operator >> ( std::istream &, NQueens & );
    public:
    NQueens ( int = 0 );
    unsigned int getNumAttacks();
    NQueens &calculateAttacks();
    NQueens &solve ();
    void call()const;
    private:
    unsigned int attack = 0;
};
#endif
