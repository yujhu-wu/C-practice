# displayBits

> C/C++ 程式設計練習 · [回到目錄](../README.md)

- **主題：** 位元運算
- **語言：** C
- **程式碼：** [main.c](main.c)

## 題目

C provides bitwise operators for fast processing integers as binary patterns. To make sure the operations are correct, we have to display the bits of integers as binary patterns. Your goal is to write a program to show the bits of input integers. Requirement: Use bitwise operators and mask to manipulate bits. Use CHAR_BIT to make you results portable.

**Input**

The input has several cases and ends with EOF. Each case is an unsigned integer in the range of 0 to 32767.

**Output**

For each case, output its binary pattern as the sample output. Only present the least significant 16 bits, and keep a space for every 8 bits. Each two consecutive cases should be separated by a newline.

**Sample Input**

```
41
18467
6334
```

**Sample Output**

```
      41 = 00000000 00101001
18467 = 01001000 00100011
  6334 = 00011000 10111110
```

## 程式碼

### main.c

```c
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    unsigned int n;
    int flag = 0;
    int t;
    t = sizeof ( n );

    while ( scanf ( "%d", &n ) != EOF )
    {
        if ( flag > 0 )
        {
            putchar ( '\n' );
        }
        printf ( "%5d = ", n );
        unsigned int displayMask = 1 << 31;
        for ( unsigned int roll = 1; roll <= t * CHAR_BIT ; ++roll )
        {
            if ( ( ( t * CHAR_BIT ) - roll ) < 16 )
            {
                putchar ( n & displayMask ? '1' : '0' );
                if ( roll == 24 )
                {
                    putchar ( ' ' );
                }
            }
            n <<= 1;
        }
        flag += 1;
    }
}
```

