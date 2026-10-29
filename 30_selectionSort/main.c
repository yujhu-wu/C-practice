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
