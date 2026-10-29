#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, a, z;
    int n=0, h=0;

    scanf("%d", &a);
    for(int i=0;i<a;i++){
        scanf("%d", &x);
        z=x;
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
        printf("The number of iterations for %d is %d.\n", z, h);
        printf("\n");
        h=0;
    }
    return 0;
}
