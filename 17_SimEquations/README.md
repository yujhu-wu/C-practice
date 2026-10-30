# SimEquations

> C/C++程式設計練習 · [回到目錄](../README.md)

- **主題**：窮舉
- **語言**：C
- **程式碼**：[main.c](main.c)

## 題目

In high school, we have learned a lot about simultaneous equations. In fact, many real-world applications can be described as simultaneous equations. To solve a set of simultaneous equations by hand, we could use many math techniques about algebra, yet these techniques are impractical in computers. A simple concept of finding a solution of a set of simultaneous equations in the sense of computing is to enumerate all the possible solutions if the variables are in integer domain. Write a program to find a solution satisfying the following simultaneous equations: 𝑢 + 2𝑣 + 3𝑤 = 𝑃 𝑢𝑣𝑤 = 𝑄 𝑢3 + 𝑣2 + 𝑤 = 𝑅 Note that 𝑢, 𝑣, and 𝑤 are unique integer values, satisfying 0 < 𝑢 < 𝑣 < 𝑤.

**Input**

The input starts from an integer 𝑛, which indicates the number of cases, and 𝑛 lines follow. Each case in a line contains three integer values, which in turn represent 𝑃, 𝑄 and 𝑅.

**Output**

For each case, output the three values 𝑢, 𝑣, and 𝑤.

**Sample Input**

```
2
42 100 43
30 28 24
```

**Sample Output**

```
Case 1: u = 2, v = 5, w = 10
Case 2: u = 1, v = 4, w = 7
```

## 程式碼

### main.c

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int u, v, w, P, Q, R;
    int a, i;

    scanf("%d", &a);
    for(i=1; i<=a; i++){
        scanf("%d %d %d", &P, &Q, &R);
        for(w=a; w<=P-5; ++w)
        for(v=3; v<w; v++){
            u= P- 2*v - 3*w;
            if((u + 2*v + 3*w == P) && (u*v*w == Q) && (u*u*u+v*v+w == R)){
                printf("Case %d: u = %d, v = %d, w = %d\n", i, u, v, w);
            }
        }
    }
    return 0;
}
```

