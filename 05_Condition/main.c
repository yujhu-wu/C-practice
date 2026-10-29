#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;
    while(scanf("%d%d", &a, &b) !=EOF)
    {
    if(a < b){
        printf("%d is less than %d.\n", a, b);
    }
    else if(a == b){
        printf("%d is equal to %d.\n", a, b);
    }
    else if(a > b){
        printf("%d is greater than %d.\n", a, b);
    }

    }
    return 0;
}
