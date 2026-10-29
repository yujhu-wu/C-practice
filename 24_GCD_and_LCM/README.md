# GCD_and_LCM

> C/C++ 程式設計練習 · [回到目錄](../README.md)

- **主題：** 遞迴
- **語言：** C
- **程式碼：** [main.c](main.c)

## 題目

The properties of integer values have been studied for centuries in number theory. Two important concepts developed are the greatest common divisor (GCD), and least common multiple (LCM). Given two integers 𝑥 and 𝑦. The GCD is defined as the largest integer value which can divide both 𝑥 and 𝑦, while the LCM is defined as the smallest integer value which can be divided by both 𝑥 and 𝑦. A special properties among 𝑥, 𝑦, and their GCD, and LCM is 𝑥𝑦 = 𝐺𝐶𝐷 𝑥, 𝑦 × 𝐿𝐶𝑀 𝑥, 𝑦 . To determine the values of GCD and LCM, we can first calculate the value of GCD by using the Euclid's algorithm: 𝐺𝐶𝐷 𝑥, 𝑦 = 𝐺𝐶𝐷 𝑦, 𝑥 mod 𝑦 and 𝐺𝐶𝐷 𝑥, 0 = 𝑥. After the value of GCD is determined, the value of LCM can be obtained: 𝑥𝑦 𝐿𝐶𝑀 𝑥, 𝑦 = . 𝐺𝐶𝐷(𝑥, 𝑦) Write a program to calculate the GCD and LCM. You have to wrap the calculation of GCD and LCM into two functions.

**Input**

The input contains several cases and ends with EOF. Each case contains two integer values, which in turn represent 𝑥 and y.

**Output**

For each case, output the GCD and LCM of 𝑥 and 𝑦.

**Sample Input**

```
4 7
6 3
21 9
```

**Sample Output**

```
1 28
3 6
3 63
```

## 程式碼

### main.c

```c
#include <stdio.h>
#include <stdlib.h>

int gcd(int x, int y);
int main()
{
    int x,y;
    int g,l;
    while(scanf("%d %d", &x, &y)!=EOF){
        g= gcd(x,y);
        l= lcm(x,y);
        printf("%d %d\n", g, l);
    }
    return 0;
}

int gcd(int x, int y)
{
    if(y==0){
        return x;
    }
    else{
        return gcd(y, x%y);
    }
}

int lcm(int x, int y)
{
    return x*y / gcd(x,y);
}
```

