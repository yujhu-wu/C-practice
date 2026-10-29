#include <stdio.h>
char text[1000];

void Hamming1(int x,int position)
{
    for(int i=0; i<x; ++i)
    {
        text[position]='1';
        position+=1;
    }
    for(int i=0; i<position; ++i)
    {
        printf("%c",text[i]);
    }

    printf("\n");
}

void Hamming2(int x,int position)
{
    for(int i=0; i<x; ++i)
    {
        text[position]='0';
        position+=1;
    }
    for(int i=0; i<position; ++i)
    {
        printf("%c",text[i]);
    }
    printf("\n");
}

void check(int x,int y,int position)
{
    if((x>y)&&(y>0))
    {
        //printf("0");
        text[position]='0';
        check(x-1,y,position+1);
        //printf("1");
        text[position]='1';
        check(x-1,y-1,position+1);
    }

    if((x==y)&&(y>0))
    {
        Hamming1(x,position);
    }

    if((x>y)&&(y==0))
    {
        Hamming2(x,position);
    }
}

int main()
{
    int num;

    while(scanf("%d",&num) != EOF)
    {
        int x,y;
        for(int i=1; i<=num; ++i)
        {
            scanf("%d%d",&x,&y);
            check(x,y,0);
            if(i!=num) printf("\n");
        }
    }
    return 0;
}
