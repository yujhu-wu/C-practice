# nums_recursive

> C/C++程式設計練習 · [回到目錄](../README.md)

- **主題**：遞迴
- **語言**：C
- **程式碼**：[main.c](main.c)

## 題目

The bottom-up property of recursive function is useful in doing many things. It can be used to reverse the information we want to process. One example application is to transform numbers between different number systems without using array. Write a program to transform a value into binary pattern through recursive function. You should not use any array to store your result. There is no point if you didn’t use recursive function.

**Input**

The input has several cases and ends with -1. Each case contains a number in digits.

**Output**

For each case, output the binary pattern of input in the following format: The binary pattern of x is: y

**Sample Input**

```
41
153
-1
```

**Sample Output**

```
The binary pattern of 41 is: 101001
The binary pattern of 153 is: 10011001
```

## 程式碼

### main.c

```c
#include <stdio.h>
#include <stdlib.h>

int re(int c);
int main()
{
    int x;
    while(scanf("%d", &x) !=EOF){
        if(-1 == x){break;}
        else{
            printf("The binary pattern of %d is: ", x);
            re(x);
            puts("");
        }
    }

    return 0;
}
int re(int c)
{
    if(c>0){
        re(c/2);
        printf("%d", c%2);
    }
}
```

