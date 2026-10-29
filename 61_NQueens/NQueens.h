#ifndef NQUEEN_H
#define NQUEEN_H
#include <iostream>

class NQueens
{
    friend std::ostream &operator << ( std::ostream &, const NQueens & );
    friend std::istream &operator >> ( std::istream &, NQueens & );
    public:
    operator unsigned int * () const;
    explicit NQueens ( int = 8 );
    NQueens ( const NQueens & );
    ~NQueens();
    const NQueens &operator = ( const NQueens & );
    unsigned int getNumQueens ();
    unsigned int getNumAttacks();
    NQueens &calculateAttacks();
    private:
    unsigned int number;
    unsigned int attack = 0;
    unsigned int* ptr;};
#endif
