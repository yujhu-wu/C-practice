# MovingBalls

> C/C++ 程式設計練習 · [回到目錄](../README.md)

- **主題：** 陣列
- **語言：** C
- **程式碼：** [main.c](main.c)

## 題目

Towers of Hanoi is a famous problem in computer science. An extension is to generalize it to 𝑁 pegs, and each peg can afford several balls. Each ball corresponds to a unique value. There two rules for putting a ball on a certain peg:

1. The ball must be put on the top of a peg.
2. The sum of the ball on the top of the peg and the ball to be put on the top should be a square number.

Your goal is to write a program to determine the maximum number of balls ( starting from one, and incrementing by one) which can be afforded by the 𝑁 pegs. Your program should use an array to record the ball on the top of each peg. Then you can examine from the first peg to the last peg to see if the current ball can find a place on which to be put.

**Input**

The input has several cases and ends with EOF. Each case contains one integer which represents the number of pegs 𝑁 with a maximum of 200.

**Output**

For each case, output the maximum number of balls which can be afforded by the 𝑁 pegs.

**Sample Input**

```
1
3
7
9
```

**Sample Output**

```
1
7
31
49
```

## 程式碼

### main.c

```c
#include <stdio.h>
#include <stdlib.h>

int hanoi(int a);
int main()
{
    int number;

    while(scanf("%d", &number)!=EOF){
        int result = hanoi(number);
        printf("%u\n",result);
    }
    return 0;
}
int hanoi(int a)
{
    if(a==1){
        return a;
    }
    else if(a%2==0){
        return hanoi(a-1)+a;
    }
    else{
        return hanoi(a-1)+a+1;
    }
}
```

