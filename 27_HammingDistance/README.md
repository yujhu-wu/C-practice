# HammingDistance

> C/C++ 程式設計練習 · [回到目錄](../README.md)

- **主題：** 陣列
- **語言：** C
- **程式碼：** [main.c](main.c)

## 題目

In combinatorial optimization, the Hamming distance is a common way to calculate the distance of two binary patterns. The definition of Hamming distance is the number of different bits between the two patterns. For example, the two patterns A = 0010 and B = 1001 have Hamming distance 3. Write a program to enumerate all possible binary patterns which have length N and Hamming distance 𝐻 to the origin, a string contains 𝑁 zeros. This can be completed by using a recursive function with following recursive equations: 0 + 𝑆 and 1 + 𝑆 𝑁 > 𝐻 > 0 𝑁−1,𝐻 𝑁−1,𝐻−1 𝑆 = ൞ 0 … 0 (𝑁 zeros) 𝑁 > 𝐻 = 0 𝑁,𝐻 1 … 1 𝑁 ones 𝑁 = 𝐻 > 0

**Input**

The input has several cases indicated by the first input and ends with EOF. Each case contains two integers which in turn represent 𝑁 and 𝐻.

**Output**

For each case, output all length-𝑁 binary patterns with Hamming distance 𝐻 to the origin in ascending order. Each two consecutive cases should be separated by a newline character.

**Sample Input**

```
4
1 1
2 1
2 2
3 1
```

**Sample Output**

```
1

01
10

11

001
010
100
```

## 程式碼

### main.c

```c
#include <stdio.h>
char text[1000];

void Hamming1(int x,int position)
{
    for(int i=0; i<x; ++i)
    {
        text[position]='1';
        position+=1;
    }
    for(int i=0; i<position; ++i)
    {
        printf("%c",text[i]);
    }

    printf("\n");
}

void Hamming2(int x,int position)
{
    for(int i=0; i<x; ++i)
    {
        text[position]='0';
        position+=1;
    }
    for(int i=0; i<position; ++i)
    {
        printf("%c",text[i]);
    }
    printf("\n");
}

void check(int x,int y,int position)
{
    if((x>y)&&(y>0))
    {
        //printf("0");
        text[position]='0';
        check(x-1,y,position+1);
        //printf("1");
        text[position]='1';
        check(x-1,y-1,position+1);
    }

    if((x==y)&&(y>0))
    {
        Hamming1(x,position);
    }

    if((x>y)&&(y==0))
    {
        Hamming2(x,position);
    }
}

int main()
{
    int num;

    while(scanf("%d",&num) != EOF)
    {
        int x,y;
        for(int i=1; i<=num; ++i)
        {
            scanf("%d%d",&x,&y);
            check(x,y,0);
            if(i!=num) printf("\n");
        }
    }
    return 0;
}
```

