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
