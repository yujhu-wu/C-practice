# Submatrix

> C/C++ 程式設計練習 · [回到目錄](../README.md)

- **主題：** 二維陣列
- **語言：** C
- **程式碼：** [main.c](main.c)

## 題目

Matrix is quite common to store a table of values. Important information may reside in submatrices, which can be defined by four parameters, including the starting row, 𝑠𝑟𝑜𝑤 the starting column 𝑠𝑐𝑜𝑙, the ending row 𝑒𝑟𝑜𝑤, and the ending column 𝑒𝑐𝑜𝑙. Write a program to give all the submatrix for a given matrix according to the four parameters.

**Input**

The input includes several cases, separated by a newline character. Each case contains six integers and a matrix. The first two integers indicate the row and column numbers of the matrix, respectively, and the last four integers are the starting row, 𝑠𝑟𝑜𝑤 the starting column 𝑠𝑐𝑜𝑙, the ending row 𝑒𝑟𝑜𝑤, and the ending column 𝑒𝑐𝑜𝑙 of the submatrix. All elements in the matrix have the range between 0 to 9. The consecutive rows in the matrix are separated by a newline character, while each pair of consecutive columns in the matrix is separated by a space. The input ends with the asterisk symbol.

**Output**

For each case, output the corresponding submatrix. A newline character should be added between two consecutive submatrices.

**Sample Input**

```
3 3 0 1 2 2
1 2 3
4 5 6
7 8 9

2 3 1 0 1 2
1 2 3
4 5 6

*
```

**Sample Output**

```
2 3
5 6
8 9

4 5 6
```

## 程式碼

### main.c

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int h[100][100];
    int x, y, i, j, k, l;
    int r=0;

    while(scanf("%d %d %d %d %d %d", &x, &y, &i, &j, &k, &l)==6){
        if(r==1){
            printf("\n");
        }
        r=1;
        for(int a=0; a<x; a++){
            for(int b=0; b<y; b++){
                scanf("%d", &h[a][b]);
            }
        }
        for(int z=i; z<=k; z++){
            for(int w=j; w<=l; w++){
                if(w==l){
                    printf("%d", h[z][w]);
                }
                else{
                    printf("%d ", h[z][w]);
                }
            }
            printf("\n");
        }
    }
}
```

