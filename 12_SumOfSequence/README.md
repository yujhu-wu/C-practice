# SumOfSequence

> C/C++程式設計練習 · [回到目錄](../README.md)

- **主題**：迴圈
- **語言**：C
- **程式碼**：[main.c](main.c)

## 題目

Sequence exists everywhere in our life. For example, the students scores, the cost of your shopping list, and bills of your credit cards, all of them can be described as sequences. In that, an important and common work is to sum all the numbers in a sequence. For convenience, it is quite common to show the process of such summation. Write a program for figuring out the sum of any sequence and show the equation of the calculation.

**Input**

The input contains several cases. Each case contains an integer value for sequence length 𝑛, followed by a sequence of 𝑛 numbers. The input ends in case of length 𝑛 equals to 0.

**Output**

For each case, output the summation equation and the result of summation. For any negative number, you should convert it to a subtraction of a positive value rather than an addition of a negative value.

**Sample Input**

```
2 -2 3
1 7
5 2 -10 9 10 4
6 3 -4 -3 -2 3 4
8 8 -1 -1 7 -4 9 3 2
0
```

**Sample Output**

```
-2 + 3 = 1
7 = 7
2 - 10 + 9 + 10 + 4 = 15
3 - 4 - 3 - 2 + 3 + 4 = 1
8 - 1 - 1 + 7 - 4 + 9 + 3 + 2 = 23
```

## 程式碼

### main.c

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int n;
    int a;
    int sum;


    for(int c = 0; c <= 420; ++c){
       scanf("%d", &n);
       if(n == 0){break;}
       else{
        sum = 0;

         for(int i = 0; i < n; ++i){

            scanf("%d", &a);
            if(i == 0){
            printf("%d ", a);
            }
            else if(a > 0){
                printf("+ %d ", a);
            }
            else if(a <= 0){
                printf("- %d ", -a);
            }
            sum += a;

         }
         printf("= %d\n", sum);

        }
    }
    return 0;
}
```

