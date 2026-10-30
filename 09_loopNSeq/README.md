# loopNSeq

> C/C++程式設計練習 · [回到目錄](../README.md)

- **主題**：迴圈
- **語言**：C
- **程式碼**：[main.c](main.c)

## 題目

During high school, we have learned two well-known sequences, i.e., arithmetic and geometric sequences. In an arithmetic sequence, the difference between any two consecutive numbers in such sequence is the same, while in a geometric sequence, the ratio between any two consecutive numbers in such sequence is the same. Formally, the arithmetic sequence is defined by a starting condition 𝑎 and a difference 𝑑 so that 𝑎 = 0 𝑛 𝑎 + 𝑑. Similarly, the geometric sequence is defined by a starting condition 𝑎 and a ratio 𝑟 so that 𝑎 = 𝑛−1 0 𝑛 𝑟 ∙ 𝑎 . Write a program to generate a sequence with predefined length 𝑁. 𝑛−1

**Input**

The input begins with an integer 𝑚 indicating the number of cases, followed by 𝑚 lines. Each case contains four numbers 𝑡, 𝑎 , 𝑐, 𝑁, which denote the sequence type (0 = arithmetic, 1 = geometric), the starting 0 condition, the difference or ratio depending upon the type, and the sequence length 𝑁.

**Output**

For each case, output the corresponding sequence according to the format given in sample output.

**Sample Input**

```
3
0 5 3 5
0 9 5 8
1 6 5 6
```

**Sample Output**

```
Case 1: 5 8 11 14 17
Case 2: 9 14 19 24 29 34 39 44
Case 3: 6 30 150 750 3750 18750
```

## 程式碼

### main.c

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    for(int counter=1; counter<=n; ++counter){
        int t=0;
        int a=0;
        int c=0;
        int N=0;
        int i=0;
        scanf("%d %d %d %d", &t, &a, &c, &N);
        printf("Case %d:", counter);
        if(t==1){
            printf(" %d", a);
            for(i; i<N-1; i++){
                a *= c;
                printf(" %d", a);
        }
        }
        if(t==0){
            printf(" %d", a);
            for(i; i<N-1; i++){
                a += c;
                printf(" %d", a);
        }
        }
    printf("\n");
    }
    return 0;
}
```

