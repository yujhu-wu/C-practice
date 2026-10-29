# CopyAndPaste

> C/C++ 程式設計練習 · [回到目錄](../README.md)

- **主題：** 字元處理
- **語言：** C
- **程式碼：** [main.c](main.c)

## 題目

Copy-and-paste is a simple and time-saving approach for typing similar codes. For instance, we can type c = a + b; seven times by three copy-and-pastes: c = a + b; c = a + b; c = a + b; c = a + b; c = a + b; c = a + b; c = a + b; c = a + b; c = a + b; c = a + b; c = a + b; c = a + b; c = a + b; c = a + b; Your goal is to write a program to calculate the number of copy-and-paste required for obtaining 𝑛 copies from the original statements.

**Input**

The input includes several lines ended with -1. Each line contains a number.

**Output**

For each case, output the number of copy-and-paste required as mentioned above. Each output should be in separate line.

**Sample Input**

```
3
9
-1
```

**Sample Output**

```
Case 1: 2
Case 2: 4
```

## 程式碼

### main.c

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, x, y, n;
    n = 1;
    while(scanf("%d", &a)!=EOF){
        if(a<0){
            break;
        }
        x = 1;
        y = pow(2, x);

        while(y<a){
            x++;
            y = pow(2,x);
        }
        if(a==1){
            x=0;
        }
        printf("Case %d: %d\n", n, x);
        n++;
    }

    return 0;
}
```

