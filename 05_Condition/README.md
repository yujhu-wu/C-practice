# Condition

> C/C++ 程式設計練習 · [回到目錄](../README.md)

- **主題：** 條件判斷
- **語言：** C
- **程式碼：** [main.c](main.c)

## 題目

Making decision is quite common in programming. In C, we can make a decision by checking the condition through the if statement: if (expression) { //something you want to do } Here, the expression, representing some condition, can be anything having a value. A common case is the relation between two numbers, i.e., the >, <, ==, >=, and <=, which denote the first operand is greater than, less than, equal to, greater or equal to, less than or equal to, the second operand, respectively. Write a program to compare numbers and output their relation.

**Input**

The input contains 50 cases, each of which consists of two numbers.

**Output**

For each case, output one of the three relations (>, ==, <) of the two numbers. Each output should be in a separated line.

**Sample Input**

```
1 3
2 2
9 5
```

**Sample Output**

```
1 is less than 3.
2 is equal to 2.
9 is greater than 5.
```

## 程式碼

### main.c

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;
    while(scanf("%d%d", &a, &b) !=EOF)
    {
    if(a < b){
        printf("%d is less than %d.\n", a, b);
    }
    else if(a == b){
        printf("%d is equal to %d.\n", a, b);
    }
    else if(a > b){
        printf("%d is greater than %d.\n", a, b);
    }

    }
    return 0;
}
```

