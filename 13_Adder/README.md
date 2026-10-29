# Adder

> C/C++ 程式設計練習 · [回到目錄](../README.md)

- **主題：** 迴圈
- **語言：** C
- **程式碼：** [main.c](main.c)

## 題目

An adder is a device for adding two numbers under some number system. When adding integer numbers, their positions are aligned to the right, and each pair of values at the same position will be added. For a number system with base 𝑏, a carry occurred if the sum of the two values at the same position as well as the carry from their previous (right) position is greater than or equal to 𝑏. Help to write a program to calculate the addition of two numbers in any base.

**Input**

The input contains several cases. Each case contains three integers, representing the base 2 ≤ 𝑏 ≤ 10, and the two values to be added, respectively. The input ends when the base equals to 1.

**Output**

For each case, output the sequence during addition according to the format shown in the sample output. Each two consecutive cases are separated by a newline character.

**Sample Input**

```
2 1001 11
3 2012 101
4 2020 202
1
```

**Sample Output**

```
Case 1: 1001 + 11 (base 2)
1 + 1 + 0 = 0 with one carry
0 + 1 + 1 = 0 with one carry
0 + 0 + 1 = 1
1 + 0 + 0 = 1

Case 2: 2012 + 101 (base 3)
2 + 1 + 0 = 0 with one carry
1 + 0 + 1 = 2
0 + 1 + 0 = 1
2 + 0 + 0 = 2

Case 3: 2020 + 202 (base 4)
0 + 2 + 0 = 2
2 + 0 + 0 = 2
0 + 2 + 0 = 2
2 + 0 + 0 = 2
```

## 程式碼

### main.c

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int roll = 0;
    for ( roll = 1; roll <= 437; ++roll )
    {
        int base, a, b;//a,b two numbers
        int sum = 0;
        int carry = 0;
        scanf( "%d %d %d", &base, &a, &b );
        printf( "Case %d: %d + %d (base %d)\n", roll, a, b, base );
        if(base == 1){
                break;
        }
        while ( a > 0 || b > 0 )
        {
            if ( a > 0 ){
                printf( "%d", a % 10 );
                sum += a % 10;
                a -= a % 10;
                a /= 10;
            }
            else{
                printf( "0" );
            }
            printf( " + " );
            if ( b > 0 ){
                printf( "%d", b % 10 );
                sum += b % 10;
                b -= b % 10;
                b /= 10;
            }
            else{
                printf( "0" );
            }
            printf( " + " );
            printf( "%d", carry );
            if ( carry >= 0 ){
                sum += carry;
            }
            carry = 0;
            if ( sum >= base ){
                printf( " = %d with one carry\n", sum - base );
                carry += 1;
            }
            else{
                printf( " = %d\n", sum );
            }
            sum = 0;
        }
        if ( carry > 0 ){
            printf( "0 + 0 + 1 = 1\n" );
            carry = 0;
        }
        printf( "\n" );

    }
    return 0;
}
```

