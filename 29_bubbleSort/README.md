# bubbleSort

> C/C++ 程式設計練習 · [回到目錄](../README.md)

- **主題：** 排序
- **語言：** C
- **程式碼：** [main.c](main.c)

## 題目

Bubble sort is a simple sorting algorithm which sorts a set of items by swapping consecutive items if they violated the order we want. Write a program to sort items by bubble sort.

**Input**

The input has several cases and ends with EOF. Each case contains a set of characters or signed numbers with a maximum size of 20.

**Output**

For each case, sort the input by bubble sort. The output should be in ascending order with respect to ASCII code. Output the partial result in each pass according to the format given in sample output. Note that your sorting process should end if there is no swap occurred. Each two consecutive cases should be separated by a line.

**Sample Input**

```
1 2 3 4 -4 -3 -2 -1 d c b a A B C D
```

**Sample Output**

```
Pass 1: 1 2 3 -4 -3 -2 -1 4 c b a A B C D d
Pass 2: 1 2 -4 -3 -2 -1 3 4 b a A B C D c d
Pass 3: 1 -4 -3 -2 -1 2 3 4 a A B C D b c d
Pass 4: -4 -3 -2 -1 1 2 3 4 A B C D a b c d
```

## 程式碼

### main.c

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int data[20];
    char input[80];
    int input_length;
    int i,j;
    int element;
    int x, y;
    int finished;
    int input_line=0;

    while(fgets(input, 80, stdin)!=NULL)
    {
        input_line++;
       if(input_line!=1)
            printf("\n");
        element=0;
        input_length=strlen(input);
        input_length--;

        j=0;
        i=0;

        while(i<input_length)
        {
            if(input[i]=='-')
            {
                i++;
               data[j]=input[i];
               data[j]=data[j]*(-1) ;
            }
            else
                data[j]=input[i];
            i++;
            i++;
            j++;
        }
        element=j;
        finished=1;
        for (x=1;x<element;++x)
        {
            finished=1;
            for (y=0;y<element-x;++y)
            {
                if (data[y]>data[y+1])
                {
                    int temp=data[y];
                    data[y]=data[y+1];
                    data[y+1]=temp;
                    finished=0;
                }

            }
            if(finished==0)
            {
                printf("Pass %d:", x);
                for(i=0;i<element;i++)
                {
                    if(data[i]>=0)
                        printf(" %c", data[i]);
                    else
                        printf(" -%c", data[i]*(-1));
                }
                printf("\n");
            }
            else
                x=element;
       }
   }
    return 0;
}
```

