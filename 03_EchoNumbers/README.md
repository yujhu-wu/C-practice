# EchoNumbers

> C/C++ 程式設計練習 · [回到目錄](../README.md)

- **主題：** 基本輸出入
- **語言：** C
- **程式碼：** [main.c](main.c)

## 題目

C standard library provides formatted input and formatted output functions. It is quite common to input number for further processing, and this can be done by using the scanf function: int number; scanf(“%d”, &number); Here, the %d means that we expect there is an integer number at such position. Note that there is an ampersand sign before the integer variable number, and it represents the number is going to be modified. The integer value from standard input stream will be stored in the variable number. Similarly, to output a number, we can use the printf function: printf(“%d”, number); This statement will output the value stored in number to standard output stream. Write a program to retrieve the input numbers from standard input stream and pass them in the same order to standard output stream.

**Input**

The input has 50 cases and ends with EOF. Each case contains three integers.

**Output**

For each case, output numbers in the same order of the input. Each two consecutive numbers should be separated by a space character.

**Sample Input**

```
1 3 8
5 6 7
4 2 9
```

**Sample Output**

```
1 3 8
5 6 7
4 2 9
```

## 程式碼

### main.c

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c;
    while(scanf("%d %d %d", &a, &b, &c)!=EOF){
        printf("%d %d %d\n", a, b, c);
    }
    return 0;
}
```

