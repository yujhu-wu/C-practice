# echo_recursive

> C/C++程式設計練習 · [回到目錄](../README.md)

- **主題**：遞迴
- **語言**：C
- **程式碼**：[main.c](main.c)

## 題目

Recursive function is a function which calls itself either directly or indirectly. The main concept behind recursion is divide-and-conquer, which separates a problem into small pieces, and solves them individually through the same method. The other interesting perspective of recursion function is the bottom up phenomenon; that is, it handles information in a bottom-up manner. Write a program to reverse an input string through recursive function. You should not use an array to store your string. There is no point if you didn’t use recursive function.

**Input**

The input starts with an integer 𝑛 indicates the number of cases, followed by 𝑛 lines of strings.

**Output**

For each case, output the reverse of the input string.

**Sample Input**

```
olleH
ereht
```

**Sample Output**

```
Hello
there
```

## 程式碼

### main.c

```c
#include <stdio.h>
#include <stdlib.h>

int echo(int a);
int main()
{
    int n;
    int c;
    scanf("%d", &n);
    echo(c);
    for(int i=0; i<n; ++i){
        echo(c);
        printf("\n");
    }
    return 0;
}
int echo(int a)
{
    if((a= getchar()) !='\n'){
        echo(a);
        printf("%c", a);
    }
}
```

