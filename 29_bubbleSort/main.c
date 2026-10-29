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
