#include <stdio.h>
#include <stdlib.h>

int re(int c);
int main()
{
    int x;
    while(scanf("%d", &x) !=EOF){
        if(-1 == x){break;}
        else{
            printf("The binary pattern of %d is: ", x);
            re(x);
            puts("");
        }
    }

    return 0;
}
int re(int c)
{
    if(c>0){
        re(c/2);
        printf("%d", c%2);
    }
}
