#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, n=0, h=0;

    while(scanf("%d", &x)!=EOF){
        n= n+1;
        printf("Case %d:\n", n);

        if(x!=1){
            ++h;
            printf("Iteration %d: %d\n", h, x);
        }
        else{
            ++h;
            printf("Iteration %d: %d\n", h, x);
        }
        while(x!=1){
            if(x%2 == 0){
                ++h;
                x=x / 2;
                printf("Iteration %d: %d\n", h, x);
            }
            else{
                ++h;
                x=3*x+1;
                printf("Iteration %d: %d\n", h, x);
            }
        }
        printf("The number of iterations is %d.\n", h);
        printf("\n");
        h=0;
    }
    return 0;
}
