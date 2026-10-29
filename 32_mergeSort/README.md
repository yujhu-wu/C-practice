# mergeSort

> C/C++ 程式設計練習 · [回到目錄](../README.md)

- **主題：** 排序
- **語言：** C
- **程式碼：** [main.c](main.c)

## 題目

Sorting is an essential function in many real-world applications. Merge sort use the concept of divide-and- conquer for solving a sorting problem. Given an array 𝐴 and an upper and lower index 𝑝 and 𝑟 to sort, merge sort divides the problem into two subproblems: sorting from 𝑝 to 𝑞 and sorting from 𝑞 + 1 to 𝑟, where 𝑞 = (𝑝 + 𝑟)/2, and then the two subproblems are solved recursively. The key in merge sort is to merge two sorted subarrays by comparing the two number in the beginning of the two subarrays. Write a program to sort arrays by merge sort.

**Input**

The input has several cases and ends with EOF. Each case contains a set of characters or signed numbers with a maximum size of 20.

**Output**

For each case, sort the input by merge sort. The output should be in ascending order with respect to ASCII code. Output the partial results of merge according to the format given in sample output. Each two consecutive cases should be separated by a line.

**Sample Input**

```
1 2 3 4 -4 -3 -2 -1 d c b a A B C D
```

**Sample Output**

```
Partial Merge: 1 2
Partial Merge: 3 4
Partial Merge: 1 2 3 4
Partial Merge: -4 -3
Partial Merge: -2 -1
Partial Merge: -4 -3 -2 -1
Partial Merge: -4 -3 -2 -1 1 2 3 4
Partial Merge: c d
Partial Merge: a b
Partial Merge: a b c d
Partial Merge: A B
Partial Merge: C D
Partial Merge: A B C D
Partial Merge: A B C D a b c d
Partial Merge: -4 -3 -2 -1 1 2 3 4 A B C D a b c d
```

## 程式碼

### main.c

```c
#include <stdio.h>
#include <stdlib.h>
void mergeSort(int data[], int length);
void sortSubArray(int data[], int low, int high);
void merge(int data[], int left, int middle1, int middle2, int right);
void displayElements(int data[], int length);
void displaySubArray(int data[], int left, int right);

void mergeSort(int data[], int length)
{
    sortSubArray(data, 0, length-1);
}

void sortSubArray(int data[], int low, int high)
{
    if((high-low) >=1)
    {
        int middle1=(low+high)/2;
        int middle2=middle1+1;
        sortSubArray(data, low, middle1);
        sortSubArray(data, middle2, high);
        merge(data, low, middle1, middle2, high);
    }
}

void merge(int data[], int left, int middle1, int middle2, int right)
{
    int leftIndex=left;
    int rightIndex=middle2;
    int combinedIndex=left;
    int tempdata[20];
    while(leftIndex <= middle1 && rightIndex <= right)
    {
        if(data[leftIndex] <= data[rightIndex])
            tempdata[combinedIndex++]=data[leftIndex++];
        else
            tempdata[combinedIndex++]=data[rightIndex++];
    }
    if(leftIndex == middle2)
    {
        while(rightIndex <= right)
            tempdata[combinedIndex++]=data[rightIndex++];
    }
    else
    {
        while(leftIndex <= middle1)
            tempdata[combinedIndex++]=data[leftIndex++];
    }
    for(int i=left;i<=right;i++)
        data[i]=tempdata[i];
    displaySubArray(data, left, right);
}
void displayElements(int data[], int length)
{
    displaySubArray(data, 0, length-1);
}

void displaySubArray(int data[], int left, int right)
{
    printf("Partial Merge:");
    for(int i=left; i<=right;i++)
    {
        if(data[i]>0)
           printf(" %c", data[i]);
        else
           printf(" -%c", data[i]*(-1));
    }
    printf("\n");

}

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

        mergeSort(data, element);
    }
    return 0;
}
```

