# BoundedArea

> C/C++ 程式設計練習 · [回到目錄](../README.md)

- **主題：** 迴圈
- **語言：** C
- **程式碼：** [main.c](main.c)

## 題目

In high school, we have learned a lot about two dimensional plane with x axis and y axis. In 2D plane, a line can be represented by three parameters 𝑎, 𝑏, and 𝑐, forming the equation 𝑎𝑥 + 𝑏𝑦 = 𝑐. The area below the line can be expressed as 𝑎𝑥 + 𝑏𝑦 ≤ 𝑐, while the area above the line is 𝑎𝑥 + 𝑏𝑦 ≥ 𝑐. As the ranges of x axis and y axis are from negative infinity to positive infinity, the size of these two areas are also infinity. However, if we bound x axis and y axis to a range from 𝐿𝐵 to 𝑈𝐵, we can calculate the square area below or above the line as the figure shown below. 𝑎𝑥 + 𝑏𝑦 ≥ 𝑐 U𝐵,𝑈𝐵 𝐿𝐵,𝐿𝐵 𝑎𝑥 + 𝑏𝑦 ≤ 𝑐 𝑎𝑥 + 𝑏𝑦 = 𝑐 To approximate the area, a simple way is to count the number of discrete points which are beneath the line. Write a program to help the calculation of such area.

**Input**

The input contains several cases and ends with EOF. Each case contains five integer values, which in turn represent 𝐿𝐵, 𝑈𝐵, 𝑎, 𝑏 and 𝑐.

**Output**

For each case, output the number of points satisfied 𝐿𝐵 ≤ 𝑥 ≤ 𝑈𝐵, 𝐿𝐵 ≤ 𝑦 ≤ 𝑈𝐵, and 𝑎𝑥 + 𝑏𝑦 ≤ 𝑐 for all 𝑥, 𝑦 ∈ 𝑍. The output format is given in sample output.

**Sample Input**

```
-471 76 19 -40 -26
-298 388 7 -78 -5
241 1196 -14 5 -8
219 1047 12 -5 3
```

**Sample Output**

```
The square area within -471 to 76 below the line 19x-40y<=-26 is 92983.
The square area within -298 to 388 below the line 7x-78y<=-5 is 264086.
The square area within 241 to 1196 below the line -14x+5y<=-8 is 864793.
The square area within 219 to 1047 below the line 12x-5y<=3 is 57160.
```

## 程式碼

### main.c

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c;
    int x, y;
    int lb, ub;
    int cnt;

    while(scanf("%d %d %d %d %d", &lb, &ub, &a ,&b ,&c)!=EOF){

        cnt = 0;
        for(x = lb; x<= ub; ++x){
            for(y = lb; y <= ub; ++y){
                if(a * x + b * y <= c){
                    ++cnt;
                }
            }
        }
        if(b >= 0){
          printf("The square area within %d to %d below the line %dx+%dy<=%d is %d.\n", lb, ub, a, b, c, cnt);
        }
        else if(b < 0){
          printf("The square area within %d to %d below the line %dx%dy<=%d is %d.\n", lb, ub, a, b, c, cnt);
        }
    }
    return 0;
}
```

