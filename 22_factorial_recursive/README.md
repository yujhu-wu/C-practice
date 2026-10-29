# factorial_recursive

> C/C++ 程式設計練習 · [回到目錄](../README.md)

- **主題：** 遞迴
- **語言：** C
- **程式碼：** [main.c](main.c)

## 題目

Factorial is a common example to show the recursion. The recursive equation for factorial can be given as follows: 𝑎 = 𝑛𝑎 𝑛 𝑛−1 𝑎 = 1 1 As the factorial number increases rapidly, the maximum factorial number is 20 if we use the built-in type of integer in C. For overcome this circumstances, a simplest remedy is to use multiple integers for representing a single factorial number. An integer of type unsigned long long int can be used to represent 8 digits, and therefore five integers can be used to represent a value with maximum 40 digits. Write a program which is able to show factorial numbers up to 40th (𝑎 ). The calculation of factorial 40 number should be in a recursive function. There is no point if you didn’t use recursive function.

**Input**

The input has several cases and with EOF. Each case contains a number 𝑥.

**Output**

For each case, output the xth factorial number in the following format: The xth factorial number is y. For the representation of y, please add a space for every eight digits.

**Sample Input**

```
1
2
3
40
```

**Sample Output**

```
The 1st factorial number is 1.
The 2nd factorial number is 2.
The 3rd factorial number is 6.
The 4th factorial number is 24.
The 40th factorial number is 81591528 32478977 34345611 26959611 58942720 00000000.
```

## 程式碼

### main.c

```c
#include <stdio.h>
#include <stdlib.h>
long long int array [ 6 ] = { };//make array empty
int recursive ( int x );
int main ( void )
{

    int n = 0;
    for ( int j = 1; j <= 40; ++j )
    {
        for ( int l = 0; l <= 5; l++ )
        {
            array [ l ] = 0;
        }
        scanf ( "%d", &n );
        recursive ( n );


        if ( n == 1 )
        {
            printf ( "The 1st factorial number is 1.\n" );
        }
        else if ( n == 2 )
        {
            printf ( "The 2nd factorial number is 2.\n" );
        }
        else if ( n == 3 )
        {
            printf ( "The 3rd factorial number is 6.\n" );
        }
        else if ( n == 4 )
        {
            printf ( "The 4th factorial number is 24.\n" );
        }
        else if ( n > 4 )
        {
            printf ( "The %dth factorial number is", n );
            for ( int k = 0; k <= 5; ++k )
            {

                if ( array [ k ] == 0)
                {
                    if ( k == 5 )
                    {
                        printf ( " 00000000" );
                        continue;
                    }
                    continue;
                }
               if ( array [ k - 1 ] > 0 && array [ k ] <= 9999999 )
               {
                   if ( array [ k ] >= 1000000 )
                   {
                       printf ( " 0%lld", array [ k ] );
                       continue;
                   }

                   else if ( array [ k ] >= 100000 )
                   {
                       printf ( " 00%lld", array [ k ] );
                       continue;
                   }
               }
                printf ( " %lld", array [ k ] );
            }
            printf ( ".\n" );
        }

    }
    return 0;
}

int recursive ( int x )
{
    if ( x == 1)
    {
        array [ 5 ] = 1;
    }
    else
    {
        recursive ( x - 1 );
        for ( int i = 0; i <= 5; ++i )
        {
            array [i] *= x;
        }

        if ( array [ 5 ] > 99999999 )//shift if number over the limit
        {
            array [ 4 ] += array [ 5 ] / 100000000;
            array [ 5 ] %= 100000000;

        }
        if ( array [ 4 ] > 99999999 )
        {
            array [ 3 ] += array [ 4 ] / 100000000;
            array [ 4 ] %= 100000000;
        }
        if ( array [ 3 ] > 99999999 )
        {
            array [ 2 ] += array [ 3 ] / 100000000;
            array [ 3 ] %= 100000000;
        }
        if ( array [ 2 ] > 99999999 )
        {
            array [ 1 ] += array [ 2 ] / 100000000;
            array [ 2 ] %= 100000000;
        }
        if ( array [ 1 ] > 99999999 )
        {
            array [ 0 ] += array [ 1 ] / 100000000;
            array [ 1 ] %= 100000000;
        }


    }
}
```

