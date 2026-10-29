# nQueen

> C/C++ 程式設計練習 · [回到目錄](../README.md)

- **主題：** 回溯
- **語言：** C
- **程式碼：** [main.c](main.c)

## 題目

N queens problem is a generalization of eight queens problem. In the chess board game, a queen can move to anyplace vertical, horizontal, or diagonal to it. The N queens problem is to find an arrangement of N queens in an N-by-N chess board so that none of queens is attacked by the others. Since the number of possible arrangements is huge, it is common to use the randomized algorithms to solve the N queens problem. In such kind of algorithms, it is important to figure out the number of attacks for a given arrangement. You have to write a program to calculate the number of attacks.

**Input**

Each case contains an integer 1 ≤ 𝑁 ≤ 20 indicating the number of queens and a newline character follows. Following the number N, an N-by-N matrix is given. Each column is separated by a space, and each row ends with a newline character. There is also a newline character between two consecutive cases. The input ends with a ‘0’.

**Output**

For each case, print one of the three following statements: ‘There is no attack.’, ‘There is 1 attack.’, and ‘There are p attacks.’, where p represents the number of attacks. Each case should end with a newline character.

**Sample Input**

```
11
0 0 0 0 0 0 0 0 0 1 0
0 0 0 0 0 1 0 0 0 0 0
0 0 0 0 0 0 1 0 0 0 0
0 0 0 0 1 0 0 0 0 0 0
0 0 1 0 0 0 0 0 0 0 0
0 1 0 0 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0 0 0 0
0 0 0 1 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 1
0 0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 0 1 0 0 0

4
1 0 0 0
0 0 1 0
0 1 0 0
0 0 0 1

0
```

**Sample Output**

```
There are 9 attacks.
There are 2 attacks.
```

## 程式碼

### main.c

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int chess [ 30 ];
    int queen;
    int range;
    int x;
    int y;
    int attack;
    int pass = 0;
    while ( scanf ( "%d", &range ) )
    {
        if ( pass > 0 ){
            printf ( "\n" );
        }
        if ( range == 0 ){
            break;
        }
        for ( int m = 0; m < range; ++m ){
            chess [ m ] = 0;
        }

        for ( int i = 0; i < range; ++i ){
            for ( int j = 0; j < range; ++j ){
                scanf ( "%d", &queen );
                if ( queen == 1 ){
                    chess [ i ] = j;
                }
            }
        }
        attack = 0;

        for ( int k = 0; k < range - 1; ++k ){
            for ( int l = k + 1; l < range; ++l ){
                x = l - k;
                y = chess [ l ] - chess [ k ];
                if ( y < 0 ){
                    y *= -1;
                }
                if ( x == y ){
                    attack += 1;
                }
            }
        }

        if ( attack == 1 ){
            printf ( "There is 1 attack.\n" );
        }
        else if ( attack == 0 ){
            printf ( "There is no attack.\n" );
        }
        else{
            printf ( "There are %d attacks.\n", attack );
        }
    }
}
```

