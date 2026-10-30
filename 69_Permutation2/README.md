# Permutation2

> C/C++程式設計練習 · [回到目錄](../README.md)

- **主題**：運算子多載
- **語言**：C++
- **程式碼**：[main.cpp](main.cpp)、[Permutation.cpp](Permutation.cpp)、[Permutation.h](Permutation.h)

## 題目

Permutation is common concept in real world. An n-permutation 𝑃 can be represented as any combination of 0 to n-1 such that all numbers appearing once. For example, “0 2 3 1” can be a possible 4-permutation. The use of permutation is usually accompanied by the next permutation operation, which finds the smallest permutation larger than the original one. The next permutation operator can be divided into four steps: 𝑃[𝑖..𝑛]

1. Find the first decreasing place (from right to left) that 𝑃 < 𝑃 𝑖−1 𝑖 4 1 3 2 0
2. Find the smallest number 𝑃 𝑗 in subsequence 𝑃[𝑖. . 𝑛] satisfying 𝑃 𝑗

> 𝑃 𝑖−1 𝑃𝑖−1 𝑃𝑖 𝑃𝑗 𝑃[𝑖..𝑛]

3. Swap 𝑃 and 𝑃 𝑖−1 𝑗 4 2 3 1 0
4. Make subsequence 𝑃[𝑖. . 𝑛] ascending

If we change the direction of comparisons, we can get the previous permutation operator. 4 2 0 1 3 To utilize the concept of permutation for computation, we can build a class Permutation. To ease the use of object of such class, we can override the decrement operator to get the previous permutation, and the subtraction operator to get the difference of two permutations. Your goal is to provide a class Permutation with the following capabilities:

1. A default constructor to initialize the object as the smallest 5-permutation
2. Overloaded stream insertion and extraction operators (cf. Sample I/O)
3. Overloaded prefix and postfix decrement operators
4. Overloaded subtraction operator
5. Applicable to the sample main file

**Input**

The input contains several cases and ends with EOF. Each case contains two lines as two permutations, each of which is formatted as 𝑛 𝑃 𝑃 … 𝑃 . 1 2 𝑛

**Output**

Each case leads to three lines of output. The first line is the result of subtraction from the second permutation to the first permutation. The second and third lines are the results of the previous permutation of the first and the second permutation, respectively. Consecutive cases are separated by a newline stream manipulator.

**Sample Input**

```
5 1 0 4 2 3
5 4 2 1 0 3
```

**Sample Output**

```
The difference from 1 0 4 2 3 to 4 2 1 0 3 is 82.
The previous permutation of 1 0 4 2 3 is 1 0 3 4 2.
The previous permutation of 4 2 1 0 3 is 4 2 0 3 1.
```

## 程式碼

### main.cpp

```cpp
#include <iostream>
#include "Permutation.h"
#include <limits>

using namespace std;

int main()
{
    Permutation permutation1;
    cout << permutation1-- << endl;
    cout << --permutation1 << endl;
    cout << endl;

    Permutation permutationFirst, permutationSecond;

    cin >> permutationFirst;
    while ( cin.good() )
    {
        cin >> permutationSecond;

        cout << "The difference from " << permutationFirst << " to " << permutationSecond << " is " << permutationSecond - permutationFirst << "." << endl;
        cout << "The previous permutation of " << permutationFirst << " is ";
        cout << --permutationFirst << "." << endl;
        cout << "The previous permutation of " << permutationSecond-- << " is ";
        cout << permutationSecond << "." << endl;
        cout << endl;

        cin >> permutationFirst;
    }

    return 0;
}
```

### Permutation.cpp

```cpp
#include <iostream>
#include "Permutation.h"

using namespace std;

Permutation::Permutation(int roll)
    :number(roll)
{
    for(int i=0; i<number; ++i)
    {
        a[i]=i;
    }
}
istream &operator>>(istream &input, Permutation &ther)
{
    input >> ther.number;
    for(int j=0; j<ther.number; ++j)
    {
        input >> ther.a[j];
    }
    return input;
}
ostream &operator<<(ostream &output, Permutation &ther2)
{
    for ( int k = 0; k< ther2.number; ++k )
    {
        output<< ther2.a[k];
        if(k< ther2.number -1)
        {
            output << " ";
        }
    }
    return output;
}
unsigned int operator - (const Permutation &compare, const Permutation &compare2)
{
    int k, hold;
    int flag=0;
    unsigned int thecount =0;
    int b[compare.number];
    for(int q=0; q<compare2.number; ++q)
    {
        b[q] = compare2.a[q];
    }

    while(flag != compare2.number)
    {
        flag =0;
        for(int p=0; p<compare2.number; ++p)
        {
            if(b[p] == compare2.a[p])
            {
                flag += 1;
            }
        }
        ++thecount;
        k=compare2.number -1;

        while(k>0 && b[k-1] >= b[k])
        {
            --k;
        }
        if(k<=0)
        {
            double len = (double)compare2.number/2;
            for(int l=0; l<len; ++l)
            {
                hold = b[l];
                b[l] = b[compare.number-1-1];
                b[compare.number-1-1]=hold;
            }
            continue;
        }
        int j= compare2.number-1;
        while(b[j]<=b[k-1])
        {
            --j;
        }
        int temp = b[k-1];
        b[k-1] = b[j];
        b[j] = temp;
        j= compare2.number-1;

        while(k<j)
        {
            temp = b[k];
            b[k] = b[j];
            b[j] = temp;
            ++k;
            --j;
        }
    }
    return thecount-1;

}
Permutation &Permutation::operator++()
{
    help ();
        return *this;
}
Permutation Permutation::operator++(int)
{
    Permutation temp = *this;
    help();
    return temp;
}
void Permutation::help()
{
    int k, hold;
    for(int o=0; o<1; ++o)
    {
        k = number-1;
        while(k>-1 && a[k-1]>= a[k])
        {
            --k;
        }
        if(k<0)
        {
            double len = (double) number/2;
            for(int l=0; l<len; ++l)
            {
                hold = a[l];
                a[l] = a[number-1-1];
                a[number-1-1]=hold;
            }
            continue;
        }
        int j= number-1;
        while(a[j]<=a[k-1])
        {
            --j;
        }
        int temp = a[k-1];
        a[k-1] = a[j];
        a[j] = temp;
        j= number-1;

        while(k<j)
        {
            temp = a[k];
            a[k] = a[j];
            a[j] = temp;
            ++k;
            --j;
        }
    }
}
```

### Permutation.h

```cpp
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
```

