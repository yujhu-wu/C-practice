#include <stdio.h>
#include <stdlib.h>

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
    int moveitem;
    int temp;

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
        for (x=1;x<element;x++)
        {
            finished=1;
            moveitem=x;
            temp=data[x];
            while(moveitem > 0 && data[moveitem-1] > temp)
            {
                data[moveitem]=data[moveitem-1];
                --moveitem;
            }
            data[moveitem]=temp;
            printf("Pass %d:", x);
            for(i=0;i<element;i++)
            {
                if(data[i]>0)
                    printf(" %c", data[i]);
                else
                    printf(" -%c", data[i]*(-1));
            }
            printf("\n");
       }
   }

    return 0;
}
