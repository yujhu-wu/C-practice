# SolveNQueens

> C/C++程式設計練習 · [回到目錄](../README.md)

- **主題**：回溯
- **語言**：C++
- **程式碼**：[main.cpp](main.cpp)、[NQueens.cpp](NQueens.cpp)、[NQueens.h](NQueens.h)、[Permutation.cpp](Permutation.cpp)、[Permutation.h](Permutation.h)

## 題目

A generalization of the eight queen puzzle is the n queen puzzle in which the number n can be an arbitrary value. Solution of in the n-queen puzzle can be represented as a permutation, where the index is the x coordinate and the value of the element is the y coordinate for the n queens. For example, a permutation 0 2 3 1 represents the following four-queen matrix: 1 0 0 0 0 0 1 0 0 0 0 1 0 1 0 0 If any two queens will not reside in the same row and column, then an attack only occurs when the difference of x coordinate equals to the difference of y coordinate. Thus, in the above example we have one attack. Your goal is to write a program with a class permutation with the following capabilities:

1. Two private data members include the length and the numbers without any limitation on the length.
2. Overloaded stream insertion and extraction operators (cf. sample input and output).
3. A copy constructor, destructor, and assignment operator for the dynamically allocated memory.
4. Overloaded prefix and postfix increment operators.
5. Proper accessors, mutators and utility functions. and a class Nqueens with the following capabilities:
1. Three private data members include the number of queens as an unsigned integer, the number of attacks as an unsigned integer, and a user defined class object permutation.
2. Overloading stream insertion and extraction operators (cf. sample input and output).
3. Proper accessors, mutators and utility functions.
4. A solve function to solve the problem by incrementing the permutation. The process ends if there is no better solution found in the last n iterations, where n is the number of queens.
5. Applicable to the sample main file.

**Input**

The first number indicates the number of cases. Each case contains an integer n, representing the number of queens, and n integers, denoting the permutation, follow.

**Output**

For each case, use the permutation to construct the class object, and output the permutation and the number of attacks before and after optimization. The permutation numbers are separated by space and end with a colon, followed by a space, the number of attacks, and an end line stream manipulator.

**Sample Input**

```
1
9 8 4 6 3 7 0 5 2 1
```

**Sample Output**

```
Before: 8 4 6 3 7 0 5 2 1 = 6 Attacks
After  : 8 4 6 3 7 2 0 5 1 = 3 Attacks
```

## 程式碼

### main.cpp

```cpp
#include <iostream>
#include "NQueens.h"

using namespace std;

int main()
{
    unsigned int nCases = 0;
    cin >> nCases;

    for ( unsigned int i = 1; i <= nCases; ++i)
    {
        NQueens nQueensObject;
        cin >> nQueensObject;

        cout << "Case " << i << ":" << endl;
        cout << "Before: " << nQueensObject.calculateAttacks();
        cout << "After : " << nQueensObject.solve() << endl;
    }

    return 0;
}
```

### NQueens.cpp

```cpp
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
```

### NQueens.h

```cpp
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
```

### Permutation.cpp

```cpp
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
```

### Permutation.h

```cpp
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
```

