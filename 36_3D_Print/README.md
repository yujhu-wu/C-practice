# 3D_Print

> C/C++ 程式設計練習 · [回到目錄](../README.md)

- **主題：** 三維陣列
- **語言：** C
- **程式碼：** [main.c](main.c)

## 題目

3D printing becomes popular in recent years. To print the object from a 3D model built by CAD, we need to calculate the contour of the 3D model in each slice, and this can be accomplished by given the position and height of each component. Your goal is to write the program to calculate the 2D contours from the given components.

**Input**

The input starts from an integer T, indicating the number of cases. Each case includes an integer, denoting the number of components, and a list of three-value parameters, representing the starting position (s) of the component, the height of the component (h), and the end position of the component (e). 9 h 6 5 2 s e 1 3 5 10 12 13 15 17 Each case has a maximum of 5000 components. The position values are integers ranging from 0 to 10000.

**Output**

For each case, print its contour by several pairs of values, where the former denotes the starting position, and the latter stands for the height.

**Sample Input**

```
1

4
1 6 5
3 2 10
12 5 17
13 9 15
```

**Sample Output**

```
Case 1: 1 6 5 2 10 0 12 5 13 9 15 5 17 0
```

## 程式碼

### main.c

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    scanf("%d", &a);
    int square, first, high, e;
    int position[10050];
    int start, start2;

    for(int i=1; i<=a;++i){
        start2 =0;
        scanf ("%d", &square);
        for(int l=0; l<10050; ++l){
        position[l] =0;
        }
        for(int j=0; j<square; ++j){
            scanf ("%d %d %d", &first, &high, &e);
            for(int k=first; k<e; ++k){
                if(position[k] <high){
                    position[k] =high;
                }
            }
            if(e>start2){
                start2=e;
            }
        }
        for(int m =0; m<start2; ++m){
            if(position[m] !=0){
                    start=m;
                    break;
            }
        }
        printf("Case %d:", i);
        printf(" %d %d", start, position[start]);
        for(int n=start; n<=start2; ++n){
            if(position[n] !=position[n+1]){
                printf (" %d", n +1);
                printf (" %d", position[n+1]);
            }
        }
        printf("\n");
    }
}
```

