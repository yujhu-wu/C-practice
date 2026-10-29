# DisconnectedSet

> C/C++ 程式設計練習 · [回到目錄](../README.md)

- **主題：** 陣列
- **語言：** C
- **程式碼：** [main.c](main.c)

## 題目

Number theory is an interesting area for finding useful relations between numbers. Consider the following problem: Given a sequence of 𝑁 numbers from 1 to 𝑁, how many maximal disconnected sets do exist? Here we have to define the term maximal disconnected sets. A set is disconnected if there is no consecutive numbers exist in it. The maximal disconnected set means that inserting any number into the set may make the set connected. Here we can use recursive thinking to simplify the problem. The maximal disconnected sets for 𝑁 numbers can be divided into two situations: containing 𝑁 or not. If 𝑁 is included, then the prefix must be a solution of 𝑁 − 2 since 𝑁 − 1 will never be included. If 𝑁 is excluded, which means 𝑁 − 1 is included, then the prefix must be a solution of 𝑁 − 3 since 𝑁 − 2 will never be included. Now, write a program to solve the problem with any 𝑁. For efficiency, please limit the branching factor to one and use tail recursion.

**Input**

The input has several cases and ends with EOF. Each case contains one integer which represents the number 𝑁.

**Output**

For each case, output the maximum number of maximal disconnected sets.

**Sample Input**

```
1
3
5
15
```

**Sample Output**

```
1
2
4
65
```

## 程式碼

### main.c

```c
#include <stdio.h>
#include <stdlib.h>

void hanoi(int, int, int, int);
    int a=1;
    int b=2;
    int c=2;

int main()
{
    int n;
    while(scanf("%d", &n)!=EOF){
        hanoi(n,a,b,c);
    }
}

void hanoi(int n, int a, int b, int c)
{
    if(n==1){
        printf("%d\n", a);
    }
    else if(n==2){
        printf("%d\n", b);
    }
    else if(n==3){
        printf("%d\n", c);
    }
    else if(n>3){
        return hanoi(n-1, b, c, a+b);
        printf("%d\n", a+b);
    }
}
```

