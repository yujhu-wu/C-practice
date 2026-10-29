# AtoM

> C/C++ 程式設計練習 · [回到目錄](../README.md)

- **主題：** 二維陣列
- **語言：** C
- **程式碼：** [main.c](main.c)

## 題目

A one-dimensional array with length 𝑙 can be used to store 𝑚 × 𝑛 two-dimensional arrays with arbitrary values for 𝑚 and 𝑛 in following manner: 𝐴 = 𝐵 ∀𝑖 ∈ 1, … , 𝑚 ∀𝑗 ∈ {1, … , 𝑛} 𝑘 𝑖,𝑗 where 𝐴 is the 𝑘th element of array 𝐴 and 𝐵 is the element of matrix 𝐵 in 𝑖th row and 𝑗th column. The 𝑘 𝑖,𝑗 index 𝑘 is a combination of index 𝑖 and index 𝑗. For a row-major matrix, we have 𝑘 = 𝑖 ∗ 𝑛 + 𝑗; for a column-major matrix, we have 𝑘 = 𝑗 ∗ 𝑚 + 𝑖. Write a program to transfer a one-dimensional array to the corresponding two-dimensional array, or transfer a two-dimensional array to the corresponding one-dimensional array. Your program must store the contents of input and output in two separate arrays.

**Input**

The input has several cases and ends with an asterisk symbol. Each case contains three integers 𝑚, 𝑛 and 𝑙, and two symbols. The first symbol indicates the direction of transfer (U for dimension up , D for dimension down), and the second symbol represents the form of the matrix (R for row-major, C for column major).

**Output**

For each case, output the corresponding one or two-dimensional array. Each row should be separated by a newline character and two neighboring columns should be separated by a space. Also, there must be a newline character to separate two consecutive cases.

**Sample Input**

```
3 10 30 U R
8 0 8 8 0 6 8 1 9 8 9 7 2 2 8 2 8 9 0 7 8 1 5 8 6 1 2 4 2 5

6 2 12 U C
6 6 7 6 7 7 1 9 1 6 2 7

2 4 D R
1 2 3 4
5 6 7 8

2 4 D C
1 3 5 7
2 4 6 8

*
```

**Sample Output**

```
8 0 8 8 0 6 8 1 9 8
9 7 2 2 8 2 8 9 0 7
8 1 5 8 6 1 2 4 2 5

6 1
6 9
7 1
6 6
7 2
7 7

1 2 3 4 5 6 7 8

1 2 3 4 5 6 7 8
```

## 程式碼

### main.c

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c;
    char up, method;
    int array [ 1000 ];
    int array2 [ 300 ] [ 300 ];
    int n;
    int pass = 0;

    while ( scanf ( "%d", &a ) ){
        if ( pass > 0 ){
            printf ( "\n" );
        }
        if ( a == '*' ){
            break;
        }
        else{
            scanf ( "%d %d %c %c", &b, &c, &up, &method );
            pass++;
        }

        if ( up == 'U' ){
            for ( int i = 0; i < c; ++i ){
                scanf ( "%d", &n );
                array [ i ] = n;
            }
            if ( method == 'R'){
                for ( int i = 0; i < a; ++i ){
                    for ( int j = 0; j < b; ++j ){
                        array2 [ i ] [ j ] = array [ ( i * b ) + j ];
                        printf ( "%d", array2 [ i ] [ j ] );
                        if ( j < b - 1 ){
                            printf ( " " );
                        }
                        if ( j == b - 1 ){
                            printf ( "\n" );
                        }
                    }
                }
            }
            else{
                for ( int k = 0; k < a; ++k ){
                    for ( int l = 0; l < b; ++l ){
                        array2 [ k ] [ l ] = array [ ( l * a ) + k ];
                        printf ( "%d", array2 [ k ] [ l ] );
                        if ( l < b - 1 ){
                            printf ( " " );
                        }
                        if ( l == b - 1 ){
                            printf ( "\n" );
                        }
                    }
                }
            }
        }
        else{
            for ( int i = 0; i < c; ++i ){
                scanf ( "%d", &n );
                array [ i ] = n;
            }
            if ( method == 'R' ){
                for ( int o = 0; o < c; ++o ){
                    printf ( "%d", array [ o ] );
                    if ( o < c - 1 ){
                        printf ( " " );
                    }
                    if ( o == c - 1 ){
                        printf ( "\n" );
                    }
                }
            }
            else{
                for ( int p = 0; p < b; ++p ){
                    for ( int q = 0; q < a; ++q ){
                        printf ( "%d", array [ ( q * b ) + p ] );
                        if ( p < b - 1 || q < ( a - 1 ) ){
                            printf ( " " );
                        }
                        if ( p ==  ( b - 1 ) && q == ( a - 1 ) ){
                            printf ( "\n" );
                        }
                    }
                }
            }
        }
    }
    return 0;
}
```

