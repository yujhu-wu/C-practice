# Multiplication

> C/C++程式設計練習 · [回到目錄](../README.md)

- **主題**：巢狀迴圈
- **語言**：C
- **程式碼**：[main.c](main.c)

## 題目

For determining whether a number 𝑛 is a multiplication of the other number 𝑛 , a simplest way is to use the 1 2 mod operator. A faster way is to check if there is a constant 𝑐 so that 𝑛 = 𝑐𝑛 or 𝑛 − 𝑐𝑛 = 0. For every 1 2 1 2 positive integer 𝑐, the number of possible pairs of 𝑛 and 𝑛 is infinite. However, if we add some constraints 1 2 on the two numbers 𝑛 and 𝑛 , the number of pairs may be limited or even not exist. Now consider the 1 2 following three constraints: 1) 𝑛 has ten digits, 2) 𝑛 has at most ten digits, and 3) each number has no 1 2 repeated digits, i.e. no two digits having the same value. Write a program to search for all pairs of 𝑛 and 𝑛 1 2 for an arbitrary constant 𝑐.

**Input**

The input contains several cases and ends with EOF. Each case contains one integer value 𝑐.

**Output**

For each case, output all pairs of 𝑛 and 𝑛 for such 𝑐 with increasing 𝑛 in the following format: 1 2 1 𝑛 = 𝑐 ∗ 𝑛 1 2 Each two consecutive cases should be separated by a newline character. Output “Solution Not found for c = 𝑐.“ if no such 𝑛 and 𝑛 can satisfy all the constraints. 1 2

**Sample Input**

```
18467
16500
```

**Sample Output**

```
1098435627 = 18467 * 59481
1795324806 = 18467 * 97218
1907345628 = 18467 * 103284
2578140936 = 18467 * 139608
3429765108 = 18467 * 185724
3520678149 = 18467 * 190647
3579680214 = 18467 * 193842
4605318927 = 18467 * 249381
5287416039 = 18467 * 286317
5802479136 = 18467 * 314208
6078542319 = 18467 * 329157
6582137409 = 18467 * 356427
7041356298 = 18467 * 381294
7193265840 = 18467 * 389520
7194263058 = 18467 * 389574
7251436890 = 18467 * 392670
7254096138 = 18467 * 392814
7609438152 = 18467 * 412056
7624895031 = 18467 * 412893
7698024351 = 18467 * 416853
7901456823 = 18467 * 427869
8034751629 = 18467 * 435087
8460397512 = 18467 * 458136
9160278345 = 18467 * 496035
9210637854 = 18467 * 498762
9536728140 = 18467 * 516420

Solution Not Found for c = 16500.
```

## 程式碼

### main.c

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
   int roll = 0;
   long long int c = 0;
   long long int n1 = 0;
   long long int  n2 = 1;
   long long int storen2; //storage of n2
   int i = 0;//roll
   int j = 0;
   int j1 = 0;//times for j1
   int k = 0;
   int not = 0;//don't have any number
   int d = 0;//the rest after / 10

   int s0 = 0;//count each number from 0 to 9
   int s1 = 0;
   int s2 = 0;
   int s3 = 0;
   int s4 = 0;
   int s5 = 0;
   int s6 = 0;
   int s7 = 0;
   int s8 = 0;
   int s9 = 0;
   for ( roll = 1; roll <= 50; ++roll )
   {
       n2 = 0;
       not = 0;
       scanf ( "%d", &c );
       while ( n2 * c < 1000000000 )
       {
           n2 += 1;
       }

       for ( i = n2 ; i <= 987654; ++i )
       {
           storen2 = i;

           if ( i >= 100000 )
           {
               j1 = 6;
               s0 = 0;
               s1 = 0;
               s2 = 0;
               s3 = 0;
               s4 = 0;
               s5 = 0;
               s6 = 0;
               s7 = 0;
               s8 = 0;
               s9 = 0;
           }
           else
           {
               j1 = 5;
               s0 = 0;
               s1 = 0;
               s2 = 0;
               s3 = 0;
               s4 = 0;
               s5 = 0;
               s6 = 0;
               s7 = 0;
               s8 = 0;
               s9 = 0;
           }

           for ( j = 1; j <= j1; ++j )
           {
               d = storen2 % 10;
               storen2 /= 10;

               if ( d ==  0)
               {
                   s0 += 1;
               }
               else if ( d ==  1)
               {
                   s1 += 1;
               }
               else if ( d ==  2)
               {
                   s2 += 1;
               }
               else if ( d ==  3)
               {
                   s3 += 1;
               }
               else if ( d ==  4)
               {
                   s4 += 1;
               }
               else if ( d ==  5)
               {
                   s5 += 1;
               }
               else if ( d ==  6)
               {
                   s6 += 1;
               }
               else if ( d ==  7)
               {
                   s7 += 1;
               }
               else if ( d ==  8)
               {
                   s8 += 1;
               }
               else if ( d ==  9)
               {
                   s9 += 1;
               }
           }
           if ( s0 > 1 || s1 > 1 || s2 > 1 || s3 > 1 || s4 > 1 || s5 > 1 || s6 > 1 || s7 > 1 || s8 > 1 || s9 > 1)
           {
               continue;
           }

           n1 = c * i;
           if ( n1 > 9999999999 )
           {
               continue;
           }
           s0 = 0;
           s1 = 0;
           s2 = 0;
           s3 = 0;
           s4 = 0;
           s5 = 0;
           s6 = 0;
           s7 = 0;
           s8 = 0;
           s9 = 0;

           for ( k = 1 ; k <= 10; ++k )
           {
               d = n1 % 10;
               n1 /= 10;

               if ( d ==  0)
               {
                   s0 += 1;
               }
               else if ( d ==  1)
               {
                   s1 += 1;
               }
               else if ( d ==  2)
               {
                   s2 += 1;
               }
               else if ( d ==  3)
               {
                   s3 += 1;
               }
               else if ( d ==  4)
               {
                   s4 += 1;
               }
               else if ( d ==  5)
               {
                   s5 += 1;
               }
               else if ( d ==  6)
               {
                   s6 += 1;
               }
               else if ( d ==  7)
               {
                   s7 += 1;
               }
               else if ( d ==  8)
               {
                   s8 += 1;
               }
               else if ( d ==  9)
               {
                   s9 += 1;
               }

           }
           if ( s0 > 1 || s1 > 1 || s2 > 1 || s3 > 1 || s4 > 1 || s5 > 1 || s6 > 1 || s7 > 1 || s8 > 1 || s9 > 1)
           {
               continue;
           }
           n1 = c * i;

           printf ( "%lld = %lld * %lld\n", n1, c, i );
           not = 1;

       }
       if ( not == 0 )
       {
           printf ( "Solution Not Found for c = %lld.\n", c );
       }
       if ( roll < 50 )
       {
           printf( "\n" );
       }

       not = 0;


   }
}
```

