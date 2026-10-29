# CountLoopsFor

> C/C++ 程式設計練習 · [回到目錄](../README.md)

- **主題：** 迴圈
- **語言：** C
- **程式碼：** [main.c](main.c)

## 題目

Some algorithms are hard to determine the number of iterations they could be run. For example, consider the following algorithm:

1. Input 𝑥
2. While 𝑥 is not equal to 1 𝑥
3. If 𝑥 is even then 𝑥 =

2

4. If 𝑥 is odd then 𝑥 = 3𝑥 + 1
5. End While

Your goal is to write a program to determine the number of iterations for each input 𝑥, and record the sequence of 𝑥. Requirement: Use for loop rather than while loop to accomplish your program for simplicity.

**Input**

The input starts from an integer 𝑛, which indicates the number of cases, and 𝑛 lines follow. Each case in a line contains one unsigned integer, which denotes the value 𝑥.

**Output**

For each case, output the sequence of 𝑥 and determine the maximum number of iterations as the format shown in the sample output. Two consecutive cases should be separated by a blank line.

**Sample Input**

```
2
6
8
```

**Sample Output**

```
Case 1:
Iteration 1: 6
Iteration 2: 3
Iteration 3: 10
Iteration 4: 5
Iteration 5: 16
Iteration 6: 8
Iteration 7: 4
Iteration 8: 2
Iteration 9: 1
The number of iterations for 6 is 9.

Case 2:
Iteration 1: 8
Iteration 2: 4
Iteration 3: 2
Iteration 4: 1
The number of iterations for 8 is 4.
```

## 程式碼

### main.c

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, a, z;
    int n=0, h=0;

    scanf("%d", &a);
    for(int i=0;i<a;i++){
        scanf("%d", &x);
        z=x;
        n= n+1;
        printf("Case %d:\n", n);

        if(x!=1){
            ++h;
            printf("Iteration %d: %d\n", h, x);
        }
        else{
            ++h;
            printf("Iteration %d: %d\n", h, x);
        }
        while(x!=1){
            if(x%2 == 0){
                ++h;
                x=x / 2;
                printf("Iteration %d: %d\n", h, x);
            }
            else{
                ++h;
                x=3*x+1;
                printf("Iteration %d: %d\n", h, x);
            }
        }
        printf("The number of iterations for %d is %d.\n", z, h);
        printf("\n");
        h=0;
    }
    return 0;
}
```

