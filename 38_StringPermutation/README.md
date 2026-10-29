# StringPermutation

> C/C++ 程式設計練習 · [回到目錄](../README.md)

- **主題：** 字串 / 排列
- **語言：** C
- **程式碼：** [main.c](main.c)

## 題目

Permutation is quite common in combinatorial problems. To enumerate each permutation for a set of symbols, we can define the order of permutations by their lexicographical order. For example, the next permutation of ‘abcd’ is ‘abdc’, and the next permutation of ‘abdc’ is ‘acbd’. Hence, the ‘acbd’ is the next 2- permutation of ‘abcd’. Your goal is to build a program to generate the next n-permutation from some sources. Note that the next permutation of the one with largest lexicographical order is the one with smallest lexicographical order. That is, the next permutation of ‘dcba’ is ‘abcd’.

**Input**

The input starts from an integer T, indicating the number of cases. Each case includes a string of symbols and an integer n, separated by a newline character.

**Output**

For each case, print its n-permutation. You should separate each case by a newline character.

**Sample Input**

```
3
hqgu
2
yps
4
dpoef
3
```

**Sample Output**

```
hugq
spy
edfpo
```

## 程式碼

### main.c

```c
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int roll;
    scanf ( "%d", &roll );
    int order;
    int n;
    char c [ 100 ];
    char c1;
    int k;
    char hold;

    for ( int i = 0; i < ( roll * 2 ); ++i ){
        if ( i > 0 &&  ( i % 2 ) == 0 ){
            printf ( "\n" );
        }
        order = 0;
        n = 0;
        gets(c);

        while ( c [ n ] != 0 ){
            n++;
        }
        n -= 1;
        scanf ( "%d", &order );

        for ( int o = 0; o < order; ++o ){
            k = n;
            while ( k > 0 && c [ k - 1 ] >= c [ k ] ){
                --k;
            }
            if ( k <= 0 ){
                double len = ( double ) n / 2;
                for ( int l = 0; l < len ; ++l ){
                    hold = c [ l ];
                    c [ l ] = c [ n - l ];
                    c [ n - l ] = hold;
                }
                continue;
            }

            int j = n;
            while ( c [ j ] <= c [ k - 1 ] ){
                --j;
            }

            char temp = c [ k - 1 ];
            c [ k - 1 ] = c [ j ];
            c [ j ] = temp;

            j = n;
            while ( k < j ){
                temp = c [ k ];
                c [ k ] = c [ j ];
                c [ j ] = temp;
                ++k;
                --j;
            }
        }
        for ( int m = 0; m <= n; ++m ){
            printf ( "%c", c [ m ] );
        }
    }
    return 0;
}
```

