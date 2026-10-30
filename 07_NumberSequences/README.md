# NumberSequences

> C/C++程式設計練習 · [回到目錄](../README.md)

- **主題**：迴圈
- **語言**：C
- **程式碼**：[main.c](main.c)

## 題目

During high school, we have learned two well-known sequences, i.e., arithmetic and geometric sequences. In an arithmetic sequence, the difference between any two consecutive numbers in such sequence is the same, while in a geometric sequence, the ratio between any two consecutive numbers in such sequence is the same. Formally, the arithmetic sequence is defined by a starting condition 𝑎 and a difference 𝑑 so that 𝑎 = 0 𝑛 𝑎 + 𝑑. Similarly, the geometric sequence is defined by a starting condition 𝑎 and a ratio 𝑟 so that 𝑎 = 𝑛−1 0 𝑛 𝑟 ∙ 𝑎 . Write a program to find out the least integer in a sequence which is greater than some set number. 𝑛−1

**Input**

The input begins with an integer 𝑛 indicating the number of cases, followed by 𝑛 lines. Each case contains four numbers 𝑡, 𝑎 , 𝑐, 𝑁, which denote the sequence type (1 = arithmetic, 2 = geometric), the starting 0 condition, the difference or ratio depending upon the type, and the number to be surpassed.

**Output**

For each case, output least number in the sequence over 𝑁 in the format given in sample output.

**Sample Input**

```
3
1 2 5 276
2 3 4 101
```

**Sample Output**

```
The least number in the arithmetic sequence starting from 2 with difference 5 over 276 is 277.
The least number in the geometric sequence starting from 3 with ratio 4 over 101 is 192.
```

## 程式碼

### main.c

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int type;
    int a0;
    int c;
    int N;
    int z;
    int counter;

    scanf("%u", &counter);
    for(counter=0; counter < 243; counter++){
        scanf("%d %d %d %d", &type, &a0, &c, &N);
        z=a0;
        if(type == 1){
            for(; a0 < N; a0 += c){

            }
            printf("The least number in the arithmetic sequence starting from %d with difference %d over %d is ", z, c, N);
            printf("%d.\n", a0);
        }
        else if(type == 2){
            for(; a0 < N; a0 *= c){

            }
            printf("The least number in the geometric sequence starting from %d with ratio %d over %d is ", z, c, N);
            printf("%d.\n", a0);
        }
    }
    return 0;
}
```

