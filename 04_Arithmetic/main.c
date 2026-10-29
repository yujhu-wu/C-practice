#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c, flag=0;
    while(scanf("%d %d\n", &a, &b)!=EOF){
        if(flag==0){
            printf("\n");
        }
        printf("%d + %d = %d\n", a, b, a+b);
        printf("%d + %d = %d\n", a, b, a-b);
        printf("%d + %d = %d\n", a, b, a*b);
        printf("%d + %d = %d\n", a, b, a/b);
    }
    return 0;
}
