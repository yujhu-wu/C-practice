# RationalNumber

> C/C++程式設計練習 · [回到目錄](../README.md)

- **主題**：運算子多載
- **語言**：C++
- **程式碼**：[main.cpp](main.cpp)、[RationalNumber.cpp](RationalNumber.cpp)、[RationalNumber.h](RationalNumber.h)

## 題目

Rational numbers are a set of numbers which can be expressed as p/q, where p is known as numerator, q is known as denominator, and both of p and q are integers. Four basic operations on rational numbers are addition, subtraction, multiplication, and division. It is quite easy and common for human to perform these operations on rational numbers For computers, it is not straightforward to represent rational numbers as well as to perform the four operations on them. In fact, rational number is not a built-in type of C++. Nevertheless, you can build your own class with overloaded operators for relational numbers. Your goal is to write a program to deal with the operations of rational numbers through a user-defined class RationalNumber with the following capabilities:

1. Two private data members for p and q.
2. A constructor with two arguments for p and q with default values p = 0, and q = 1.
3. Overloaded stream extraction operator for inputting a rational number.
4. Overloaded stream insertion operator for outputting a rational number in irreducible fraction format p/q, where p and q > 0 are unique integer numbers. Reduce the output to p in cases of q = 1.
5. Overloaded addition (+), subtraction (-), multiplication (*), and division (/) operators. Throw a runtime_error exception for division when q = 0.
6. Applicable to the sample main file.

**Input**

Each case contains four integers representing 𝑝 , 𝑞 , 𝑝 , and 𝑞 , respectively. 1 1 2 2

**Output**

For each case, output the results of 𝑟 {+,-,*,/} 𝑟 as irreducible fractions. 1 2

**Sample Input**

```
1 2 -3 -4
5 -6 -7 8
```

**Sample Output**

```
1/2 + 3/4 = 5/4
1/2 - 3/4 = -1/4
1/2 * 3/4 = 3/8
1/2 / 3/4 = 2/3

-5/6 + -7/8 = -41/24
-5/6 - -7/8 = 1/24
-5/6 * -7/8 = 35/48
-5/6 / -7/8 = 20/21
```

## 程式碼

### main.cpp

```cpp
#include <iostream>
#include "RationalNumber.h"

using namespace std;

int main()
{
    RationalNumber rn(3,4), zero;
    cout << "Default constructor: " << zero << endl;
    cout << "==========Test operations with zero==========" << endl;
    try
    {
        cout << rn + zero << endl;
        cout << rn - zero << endl;
        cout << rn * zero << endl;
        cout << rn / zero << endl;
    }
    catch(runtime_error& e)
    {
        cout << e.what() << endl;
    }

    cout << endl;

    try
    {
        cout << zero + rn << endl;
        cout << zero - rn << endl;
        cout << zero * rn << endl;
        cout << zero / rn << endl;
    }
    catch(runtime_error& e)
    {
        cout << e.what() << endl;
    }
    cout << "==================Test ends==================" << endl;
    cout << endl;

    for ( size_t n = 0; n < 500; ++n )
    {
        RationalNumber rn1, rn2;
        cin >> rn1 >> rn2;

        cout << rn1 << " + " << rn2 << " = " << rn1 + rn2 << endl;
        cout << rn1 << " - " << rn2 << " = " << rn1 - rn2 << endl;
        cout << rn1 << " * " << rn2 << " = " << rn1 * rn2 << endl;
        cout << rn1 << " / " << rn2 << " = " << rn1 / rn2 << endl;

        cout << endl;
    }

    return 0;
}
```

### RationalNumber.cpp

```cpp
#include "RationalNumber.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

RationalNumber::RationalNumber ( int p1, int q1 )
    :p ( p1 ), q ( q1 )
{

}


ostream &operator<< ( ostream &output,  RationalNumber &ther1 )
{
    int n1 = ther1.p;
    int n2 = ther1.q;

    if ( n1 < 0 )
    {
        n1 *= -1;
    }
    if ( n2 < 0 )
    {
        n2 *= -1;
    }

    double maxnum = n1;
    if ( n2 > maxnum )
    {
        maxnum = n2;
    }


    for ( int i = 2; i <= maxnum/2 ; ++i )
    {
        if ( (ther1.p != 0) && (ther1.q  != 0 ))
        {
            while ( ((ther1.p % i) == 0 )&& ((ther1.q % i) == 0 ))
            {
                ther1.p /=  i;
                ther1.q /=  i;
            }
        }
    }
    if ( ther1.p == 0 )
    {
        output << 0;
    }
    else if ( ther1.p % ther1.q == 0 )
    {
        output << ther1.p / ther1.q;

    }
    else
    {
        if ( ther1.p < 0 && ther1.q < 0 )
        {
            output << ther1.p * -1 << "/" << ther1.q * -1;
        }
        else if ( ther1.p > 0 && ther1.q < 0 )
        {
            output << ther1.p * -1 << "/" << ther1.q * -1;
        }
        else
        {
            output << ther1.p  << "/" << ther1.q ;
        }

    }
    return output;

}

istream &operator >> ( istream &input,  RationalNumber &ther2 )
{
    int a, b;
    input >> a >> b;
    ther2.p = a;
    ther2.q = b;
    return input;

}

std::string operator + ( const RationalNumber &rn1, const RationalNumber&rn2 )
{
    int thep, theq;
    theq = rn1.q * rn2.q;
    thep = ( rn1.p * rn2.q ) + ( rn2.p * rn1.q );

    int n1 = thep;
    int n2 = theq;

    if ( n1 < 0 )
    {
        n1 *= -1;
    }
    if ( n2 < 0 )
    {
        n2 *= -1;
    }

    double maxnum = n1;
    if ( n2 > maxnum )
    {
        maxnum = n2;
    }


    for ( int i = 2; i <= maxnum  ; ++i )
    {
        if ( (thep != 0) && (theq  != 0 ))
        {
            while ( ((thep % i) == 0 )&& ((theq % i) == 0 ))
            {
                thep /=  i;
                theq /=  i;
            }
        }
    }



    if ( thep == 0 )
    {
        string s3 = "0";
        return s3;
    }
    else if ( thep % theq == 0 )
    {
        int n = thep / theq;
        string s1 = to_string(n);
        return s1;

    }
    else
    {
        if ( thep < 0 && theq < 0 )
        {
            int n1 = thep * -1;
            int n3 = theq * -1;
            string s1 = to_string(n1);
            string s2 = to_string(n3);
            string s3;
            s3.append ( s1 ).append( "/" ).append ( s2 );
            return s3;
        }
        else if ( thep > 0 && theq < 0 )
        {
            int n1 = thep * -1;
            int n3 = theq * -1;
            string s1 = to_string(n1);
            string s2 = to_string(n3);
            string s3;
            s3.append ( s1 ).append( "/" ).append ( s2 );
            return s3;
        }
        else
        {
            int n1 = thep ;
            int n3 = theq ;
            string s1 = to_string(n1);
            string s2 = to_string(n3);
            string s3;
            s3.append ( s1 ).append( "/" ).append ( s2 );
            return s3;
        }

    }


}

std::string operator - ( const RationalNumber &rn1, const RationalNumber&rn2 )
{
    int thep, theq;
    theq = rn1.q * rn2.q;
    thep = ( rn1.p * rn2.q ) - ( rn2.p * rn1.q );

    int n1 = thep;
    int n2 = theq;

    if ( n1 < 0 )
    {
        n1 *= -1;
    }
    if ( n2 < 0 )
    {
        n2 *= -1;
    }

    double maxnum = n1;
    if ( n2 > maxnum )
    {
        maxnum = n2;
    }


    for ( int i = 2; i < maxnum/2 ; ++i )
    {
        if ( n1 != 0 && n2  != 0 )
        {
            while ( thep % i == 0 && theq % i == 0 )
            {
                thep /= i;
                theq /= i;
            }
        }
    }




    if ( thep == 0 )
    {
        string s3 = "0";
        return s3;
    }
    else if ( thep % theq == 0 )
    {
        int n = thep / theq;
        string s1 = to_string(n);
        return s1;

    }
    else
    {
        if ( thep < 0 && theq < 0 )
        {
            int n1 = thep * -1;
            int n3 = theq * -1;
            string s1 = to_string(n1);
            string s2 = to_string(n3);
            string s3;
            s3.append ( s1 ).append( "/" ).append ( s2 );
            return s3;
        }
        else if ( thep > 0 && theq < 0 )
        {
            int n1 = thep * -1;
            int n3 = theq * -1;
            string s1 = to_string(n1);
            string s2 = to_string(n3);
            string s3;
            s3.append ( s1 ).append( "/" ).append ( s2 );
            return s3;
        }
        else
        {
            int n1 = thep ;
            int n3 = theq ;
            string s1 = to_string(n1);
            string s2 = to_string(n3);
            string s3;
            s3.append ( s1 ).append( "/" ).append ( s2 );
            return s3;
        }

    }
}

std::string operator * ( const RationalNumber &rn1, const RationalNumber&rn2 )
{
    int thep, theq;
    theq = rn1.q * rn2.q;
    thep = ( rn1.p * rn2.p );

    int n1 = thep;
    int n2 = theq;

    if ( n1 < 0 )
    {
        n1 *= -1;
    }
    if ( n2 < 0 )
    {
        n2 *= -1;
    }

    double maxnum = n1;
    if ( n2 > maxnum )
    {
        maxnum = n2;
    }


    for ( int i = 2; i < maxnum/2 ; ++i )
    {
        if ( n1 != 0 && n2  != 0 )
        {
            while ( thep % i == 0 && theq % i == 0 )
            {
                thep /= i;
                theq /= i;
            }
        }
    }




    if ( thep == 0 )
    {
        string s3 = "0";
        return s3;
    }
    else if ( thep % theq == 0 )
    {
        int n = thep / theq;
        string s1 = to_string(n);
        return s1;

    }
    else
    {
        if ( thep < 0 && theq < 0 )
        {
            int n1 = thep * -1;
            int n3 = theq * -1;
            string s1 = to_string(n1);
            string s2 = to_string(n3);
            string s3;
            s3.append ( s1 ).append( "/" ).append ( s2 );
            return s3;
        }
        else if ( thep > 0 && theq < 0 )
        {
            int n1 = thep * -1;
            int n3 = theq * -1;
            string s1 = to_string(n1);
            string s2 = to_string(n3);
            string s3;
            s3.append ( s1 ).append( "/" ).append ( s2 );
            return s3;
        }
        else
        {
            int n1 = thep ;
            int n3 = theq ;
            string s1 = to_string(n1);
            string s2 = to_string(n3);
            string s3;
            s3.append ( s1 ).append( "/" ).append ( s2 );
            return s3;
        }

    }
}

std::string operator / ( const RationalNumber &rn1, const RationalNumber&rn2 )
{
    if ( rn2.p != 0 )
    {
        int thep, theq;
        theq = rn1.q * rn2.p;
        thep = ( rn1.p * rn2.q );

        int n1 = thep;
        int n2 = theq;

        if ( n1 < 0 )
        {
            n1 *= -1;
        }
        if ( n2 < 0 )
        {
            n2 *= -1;
        }

        double maxnum = n1;
        if ( n2 > maxnum )
        {
            maxnum = n2;
        }


        for ( int i = 2; i < maxnum/2 ; ++i )
        {
            if ( n1 != 0 && n2  != 0 )
            {
                while ( thep % i == 0 && theq % i == 0 )
                {
                    thep /= i;
                    theq /= i;
                }
            }
        }




        if ( thep == 0 )
        {
            string s3 = "0";
            return s3;
        }
        else if ( thep % theq == 0 )
        {
            int n = thep / theq;
            string s1 = to_string(n);
            return s1;

        }
        else
        {
            if ( thep < 0 && theq < 0 )
            {
                int n1 = thep * -1;
                int n3 = theq * -1;
                string s1 = to_string(n1);
                string s2 = to_string(n3);
                string s3;
                s3.append ( s1 ).append( "/" ).append ( s2 );
                return s3;
            }
            else if ( thep > 0 && theq < 0 )
            {
                int n1 = thep * -1;
                int n3 = theq * -1;
                string s1 = to_string(n1);
                string s2 = to_string(n3);
                string s3;
                s3.append ( s1 ).append( "/" ).append ( s2 );
                return s3;
            }
            else
            {
                int n1 = thep ;
                int n3 = theq ;
                string s1 = to_string(n1);
                string s2 = to_string(n3);
                string s3;
                s3.append ( s1 ).append( "/" ).append ( s2 );
                return s3;
            }

        }
    }
    else
    {
        throw runtime_error ( "Divide by zero." );
    }

}
```

### RationalNumber.h

```cpp
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
```

