# Hanoi

> C/C++ 程式設計練習 · [回到目錄](../README.md)

- **主題：** 遞迴
- **語言：** C
- **程式碼：** [main.c](main.c)

## 題目

Hanoi tower is a basic problem for knowing the power of divide-and-conquer method, and recursive function. In the Hanoi tower problem, the priest wants to move the stack from the first peg to the third peg through one temporary peg, the second peg. The rule of Hanoi tower problem is simple, including:

1. Each time we can only move one disk.
2. At any time, a larger disk cannot put on a smaller one.

Your goal is to write a program to show how to solve the Hanoi tower problem with n disks step by step. You have to use recursive function to build your solution.

**Input**

The input has several cases and ends with EOF. Each case contains a number which represent the number of disks.

**Output**

For each case, output the steps to solve a Hanoi tower problem. Add a newline between any two consecutive cases.

**Sample Input**

```
1
2
3
```

**Sample Output**

```
Move disk 1 from 1 to 3

Move disk 1 from 1 to 2
Move disk 2 from 1 to 3
Move disk 1 from 2 to 3

Move disk 1 from 1 to 3
Move disk 2 from 1 to 2
Move disk 1 from 3 to 2
Move disk 3 from 1 to 3
Move disk 1 from 2 to 1
Move disk 2 from 2 to 3
Move disk 1 from 1 to 3
```

## 程式碼

### main.c

```c
#include <stdio.h>
#include <stdlib.h>

void hanoi(int, int, int, int);
    int a=1;
    int b=2;
    int c=3;

int main()
{
    int n;
    while(scanf("%d", &n)!=EOF){
        hanoi(n,a,b,c);
        printf("\n");
    }
}

void hanoi(int n, int a, int b, int c)
{
    if(n==1){
        printf("Move disk %d from %d to %d\n", n, a, c);
    }
    else{
        hanoi(n-1, a, c, b);
        printf("Move disk %d from %d to %d\n", n, a, c);
        hanoi(n-1, b, a, c);
    }
}
```

