# NQueens

> C/C++程式設計練習 · [回到目錄](../README.md)

- **主題**：類別 / 回溯
- **語言**：C++
- **程式碼**：[main.cpp](main.cpp)、[NQueens.cpp](NQueens.cpp)、[NQueens.h](NQueens.h)

## 題目

A generalization of the eight queen puzzle is the n queen puzzle in which the number n can be an arbitrary value. There are two common representations for the n queen puzzle: matrix and permutation. In the matrix representation, 0 as empty and 1 as queen for each cell. As for the representation of permutation, the index is the x coordinate and the value of the element is the y coordinate for the eight queens. For example, a four-queen matrix can be: 1 0 0 0 0 0 1 0 0 0 0 1 0 1 0 0 and its corresponding permutation is: 0 2 3 1 If any two queens will not reside in the same row and column, then an attack only occurs when the difference of x coordinate equals to the difference of y coordinate. Thus, in the above example we have one attack. Your goal is to write a program with a class NQueens with the following capabilities:

1. Three private data members include the number of queens as an unsigned integer, the number of attacks as an unsigned integer, and the permutation representation as a pointer to unsigned integer.
2. A default constructor to generate an eight-queen solution with the smallest permutation.
3. A conversion constructor with one argument as the number of queens generating am N-queen solution with the smallest permutation.
4. A copy constructor, destructor, and assignment operator for the dynamically allocated memory.
5. Conversion operator to cast the class object to a pointer of unsigned integer.
6. Overloading stream insertion and extraction operators (cf. sample input and output).
7. Proper accessors, mutators and utility functions.
8. Applicable to the sample main file.

**Input**

Each case contains an integer n, representing the number of queens, and an n-by-n matrix. The input ends with n = 0.

**Output**

For each case, use the matrix to construct the class object, and output the corresponding permutation and number of attacks. The permutation numbers are separated by space and end with a colon, followed by a space, the number of attacks, and an end line stream manipulator.

**Sample Input**

```
9
0 0 0 0 0 0 0 0 1
0 0 0 0 1 0 0 0 0
0 0 0 0 0 0 1 0 0
0 0 0 1 0 0 0 0 0
0 0 0 0 0 0 0 1 0
1 0 0 0 0 0 0 0 0
0 0 0 0 0 1 0 0 0
0 0 1 0 0 0 0 0 0
0 1 0 0 0 0 0 0 0
0
```

**Sample Output**

```
8 4 6 3 7 0 5 2 1: 6 Attacks
```

## 程式碼

### main.cpp

```cpp
#include <iostream>
#include "NQueens.h"

using namespace std;

void test_conversion1(unsigned int* p, size_t length);
void test_conversion2(NQueens nqObj);

int main()
{
    NQueens nQueensObject1; // default constructor as eight queens
    test_conversion1(nQueensObject1, nQueensObject1.getNumQueens()); // invoke conversion operator
    test_conversion2(nQueensObject1); // invoke copy constructor

    NQueens nQueensObject2(5); // constructor with one argument as number of queens
    nQueensObject1 = nQueensObject2; // invoke assignment operator
    nQueensObject1.calculateAttacks(); // calculate number of attacks
    cout << nQueensObject1; // overloaded stream insertion operator


    unsigned int nQueens = 0;
    cin >> nQueens;

    while( nQueens > 0 )
    {
        NQueens nQueensObject(nQueens); // constructor with one argument as number of queens
        cin >> nQueensObject; // overloaded stream extraction operator

        nQueensObject.calculateAttacks(); // calculate number of attacks
        cout << nQueensObject; // overloaded stream insertion operator

        cin >> nQueens;
    }

    return 0;
}

void test_conversion1(unsigned int* p, size_t length)
{
    for ( size_t i = 0; i < length - 1; ++i )
    {
        cout << p[i] << " ";
    }
    cout << p[length - 1] << ": ";
}

void test_conversion2(NQueens nqObj)
{
    cout << nqObj.calculateAttacks().getNumAttacks() << " Attacks" << endl;
}
```

### NQueens.cpp

```cpp
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
```

### NQueens.h

```cpp
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
```

