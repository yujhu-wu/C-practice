# selectionSort

> C/C++程式設計練習 · [回到目錄](../README.md)

- **主題**：排序
- **語言**：C
- **程式碼**：[main.c](main.c)

## 題目

Selection sort is a simple sorting algorithm which sorts a set of items by adding the smallest item in unsorted set of items into the set of sorted items, where all sorted items are less than or equal to unsorted items. Write a program to sort items by selection sort.

**Input**

The input has several cases and ends with EOF. Each case contains a set of characters or signed numbers with a maximum size of 20.

**Output**

For each case, sort the input by selection sort. The output should be in ascending order with respect to ASCII code. Output the partial result in each pass according to the format given in sample output. Each two consecutive cases should be separated by a line.

**Sample Input**

```
1 2 3 4 -4 -3 -2 -1 d c b a A B C D
```

**Sample Output**

```
Pass 1: -4 2 3 4 1 -3 -2 -1 d c b a A B C D
Pass 2: -4 -3 3 4 1 2 -2 -1 d c b a A B C D
Pass 3: -4 -3 -2 4 1 2 3 -1 d c b a A B C D
Pass 4: -4 -3 -2 -1 1 2 3 4 d c b a A B C D
Pass 5: -4 -3 -2 -1 1 2 3 4 d c b a A B C D
Pass 6: -4 -3 -2 -1 1 2 3 4 d c b a A B C D
Pass 7: -4 -3 -2 -1 1 2 3 4 d c b a A B C D
Pass 8: -4 -3 -2 -1 1 2 3 4 d c b a A B C D
Pass 9: -4 -3 -2 -1 1 2 3 4 A c b a d B C D
Pass 10: -4 -3 -2 -1 1 2 3 4 A B b a d c C D
Pass 11: -4 -3 -2 -1 1 2 3 4 A B C a d c b D
Pass 12: -4 -3 -2 -1 1 2 3 4 A B C D d c b a
Pass 13: -4 -3 -2 -1 1 2 3 4 A B C D a c b d
Pass 14: -4 -3 -2 -1 1 2 3 4 A B C D a b c d
Pass 15: -4 -3 -2 -1 1 2 3 4 A B C D a b c d
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
    int smallest;

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
        for (x=0;x<element-1;x++)
        {
            int temp;
            finished=1;
            smallest=x;
            for (y=x+1;y<element;y++)
            {
                if (data[y]<data[smallest])
                {
                    smallest=y;
                    finished=0;
                }

            }
            temp=data[x];
            data[x]=data[smallest];
            data[smallest]=temp;
            printf("Pass %d:", x+1);
            for(i=0;i<element;i++)
            {
                if(data[i]>=0)
                    printf(" %c", data[i]);
                else
                    printf(" -%c", data[i]*(-1));
            }
            printf("\n");
        }
   }

    return 0;
}
```

