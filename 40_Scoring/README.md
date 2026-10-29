# Scoring

> C/C++ 程式設計練習 · [回到目錄](../README.md)

- **主題：** 格式化輸出
- **語言：** C
- **程式碼：** [main.c](main.c)

## 題目

![題目原文](problem.png)

There are lots of applications leveraging formatted I/O. One practical use is to compute students scores. Suppose you are a teacher of some course, and you want to evaluate your students according to their class attendance, practice, and exam score. The final score is determined by the weighted sum in which the weights for these activities are 0.1, 0.3, and 0.6, respectively. To examine the performance on each activity, a common method is the mean value, which is the sum of all values under a certain activity over the number of students. Your goal is to write a program to compile the input scores in a table. Requirement: use integer expression for field width and precision.

**Input**

The input has several cases and ends with a single 0. Each case contains an integer 3 ≤ 𝑛 ≤ 100, which denotes the number of students in the course, and 𝑛 tuples of scores, which represent the scores of attendance, practice, and exam, respectively.

**Output**

For each case, output the received scores, the final scores, and their average according to the sample output format. Note that two consecutive tables should be separated by a line. Please take all computation in integer for precision issue.

**Sample Input**

```
18
83 50 98
79 1 93
34 37 34
56 93 76
5 62 48
81 0 13
41 55 55
42 62 11
77 24 78
52 43 96
73 40 13
75 72 18
10 17 32
12 95 69
31 40 88
85 90 97
89 90 45
53 14 51

0
```

**Sample Output**

```

```

## 程式碼

### main.c

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int roll, a, p, e;
    double f;
    int a1, p1, e1, f1;
    int flag=0;

    while(scanf("%d", &roll))
    {
        a1=0;
        p1=0;
        e1=0;
        f1=0;
        if(roll==0)
        {
            break;
        }
        if(flag>0)
        {
            printf("\n");
        }
        printf("==================================================\n");
        printf("Index   Attendance   Practice   Exam   Final Score\n");
        printf("==================================================\n");
        for(int i=1; i<=roll; ++i)
        {
            scanf("%d %d %d", &a, &p, &e);
            if(i<10)
            {
                f=(double)a/10+((double)p/10)*3+((double)e/10)*6;
                printf("0000%d%13d%11d%7d%14d", i, a, p, e, (int)f );
                if(i<roll)
                {
                    printf("\n");
                }
                a1 += a;
                p1 += p;
                e1 += e;
                f1 += f;
            }
            else if(i<100)
            {
                f=(double)a/10+((double)p/10)*3+((double)e/10)*6;
                printf("000%d%13d%11d%7d%14d", i, a, p, e, (int)f );
                if(i<roll)
                {
                    printf("\n");
                }
                a1 += a;
                p1 += p;
                e1 += e;
                f1 += f;
            }
            else
            {
                f=(double)a/10+((double)p/10)*3+((double)e/10)*6;
                printf("00100%13d%11d%7d%14d", a, p, e, (int)f );
                if(i<roll)
                {
                    printf("\n");
                }
                a1 += a;
                p1 += p;
                e1 += e;
                f1 += f;
            }
        }
        a1 = (double)a1/roll;
        p1 = (double)p1/roll;
        e1 = (double)e1/roll;
        f1 = (double)f1/roll;
        printf("\n");

        printf("==================================================\n");
        printf("Mean%14d%11d%7d%14d\n", a1, p1, e1, f1);
        printf("==================================================\n");
        flag += 1;

    }
    return 0;
}
```

