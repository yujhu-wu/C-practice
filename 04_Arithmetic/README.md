# Arithmetic

> C/C++ 程式設計練習 · [回到目錄](../README.md)

- **主題：** 運算式
- **語言：** C
- **程式碼：** [main.c](main.c)

## 題目

Arithmetic can be the most common data processing. In C, we can use +, -, *, and / for addition, subtraction, multiplication, and division two numbers, respectively. The results are similar to the mathematics we learned from elementary school, except that the division for integers only takes the integral part. Write a program to do calculation of arithmetics.

**Input**

The input contains ten cases, each of which consist of two integer numbers.

**Output**

For each case, output the results of applying the four arithmetic operators. Each two consecutive cases should be separated by a line.

**Sample Input**

```
4 7
5 3
```

**Sample Output**

```
4 + 7 = 11
4 – 7 = - 3
4 * 7 = 28
4 / 7 = 0

5 + 3 = 8
5 – 3 = 2
5 * 3 = 15
5 / 3 = 1
```

## 程式碼

### main.c

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c, flag=0;
    while(scanf("%d %d\n", &a, &b)!=EOF){
        if(flag==0){
            printf("\n");
        }
        printf("%d + %d = %d\n", a, b, a+b);
        printf("%d + %d = %d\n", a, b, a-b);
        printf("%d + %d = %d\n", a, b, a*b);
        printf("%d + %d = %d\n", a, b, a/b);
    }
    return 0;
}
```

