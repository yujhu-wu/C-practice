#ifndef PERMUTATION_H
#define PERMUTATION_H
#include <iostream>
class Permutation
{
    public:
    void help ();
    Permutation ( const Permutation & );
    Permutation ( int );
    ~Permutation();
    const Permutation &operator = ( const Permutation & );
    unsigned int countattack ();
    unsigned int* print (  )const;
    void thecin ( );
    unsigned int returnattack ()const;
    void setptr ( int );
    private:
    unsigned int* ptr;
    int number;
    int theattack = 0;
};
#endif
