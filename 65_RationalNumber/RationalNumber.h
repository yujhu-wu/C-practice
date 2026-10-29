#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
#include <string>

class RationalNumber
{
    friend std::ostream &operator << ( std::ostream &, RationalNumber & );
    friend std::istream &operator >> ( std::istream &,  RationalNumber & );
    friend std::string operator + ( const RationalNumber &, const RationalNumber& );
    friend std::string operator - ( const RationalNumber &, const RationalNumber& );
    friend std::string operator * ( const RationalNumber &, const RationalNumber& );
    friend std::string operator / ( const RationalNumber &, const RationalNumber& );
public:
    RationalNumber ( int = 0, int = 1);
private:
    int p;
    int q;

};

#endif // RATIONAL_H
