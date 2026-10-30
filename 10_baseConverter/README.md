# baseConverter

> C/C++程式設計練習 · [回到目錄](../README.md)

- **主題**：進位轉換
- **語言**：C
- **程式碼**：[main.c](main.c)

## 題目

In our living world, the most commonly used number system was brought by Indian mathematicians and was adopted in Arabic mathematics. Today, this number system is known as the Hindu–Arabic numeral system. The Hindu–Arabic numeral system is a positional number system to represent numbers by symbols. However, numbers can be presented in different number systems. Most importantly, the positional number systems are interchangeable; that is, we can present a number in some system through the other number system. A positional number system is represented by its base 𝑏 and its set of symbols 𝑆. For example, the well- known Hindu–Arabic numeral system consists of base 𝑏 = 10, and set of symbols 𝑆 = {0,1,2,3, … , 9}. A number can therefore be presented as (𝑠 𝑠 … 𝑠 𝑠 ) , and its corresponding value is given as: 𝑘−1 𝑘−2 1 0 𝑏 𝑁 = 𝑠 𝑏𝑘−1 + 𝑠 𝑏𝑘−2 + ⋯ + 𝑠 𝑏1 + 𝑠 𝑏0 = σ𝑘−1 𝑠 𝑏𝑖, where 𝑁 is the value in decimal system. 𝑘−1 𝑘−2 1 0 𝑖=0 𝑖 According to this formula, we can easily change a number from the Hindu–Arabic numeral system to any other positional number system if the base 𝑏 and set of symbols 𝑆 are given. Write a program to do such transformation. (Hint: Suppose 𝑁 = σ 𝑗−1 𝑠 𝑏𝑖, try to figure out how to take 𝑠 from 𝑁 and the relations 𝑗 𝑖=0 𝑖 𝑗−1 𝑗 between 𝑁 and 𝑁 .) 𝑗 𝑗−1

**Input**

The input is ended with -1 with 𝑛 cases, each of which is composed of the number 𝑁 to be transformed and the base 𝑏 of the destination number system.

**Output**

For each case, output the transformed number in base 𝑏. Each output should be in separate line.

**Sample Input**

```
5744 3
9388 8
4494 4
638 9
-1
```

**Sample Output**

```
The number 5744 in base 3 is 21212202.
The number 9388 in base 8 is 22254.
The number 4494 in base 4 is 1012032.
The number 638 in base 9 is 778.
```

## 程式碼

### main.c

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count=0;
    for(count=1; count<=386; ++count){
        int n=0;
        int base=0;
        int shift=1;
        int d=0;
        scanf("%d %d", &n, &base);
        printf("The number %d in base %d is ", n, base);
        while(shift<n){
            shift *= base;
        }
        while(shift>n){
            shift /= base;
        }
        while(shift!=0){
            printf("%d", n/shift);
            n %= shift;
            shift /= base;
        }
        printf(".\n");
    }
    return 0;
}
```

