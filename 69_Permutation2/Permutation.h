#include <iostream>
#ifndef Permutation_H
#define Permutation_H

class Permutation
{
    friend std::ostream &operator << (std::ostream &, const Permutation &);
    friend std::istream &operator >> (std::istream &, Permutation &);
    friend unsigned int operator - (const Permutation &, const Permutation &);
public:
    explicit Permutation(int = 5);
    Permutation &operator++();
    Permutation operator++(int);
    void help();

private:
    int a[11];
    int number;
};
#endif // Permutation_H
