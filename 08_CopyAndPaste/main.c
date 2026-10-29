#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, x, y, n;
    n = 1;
    while(scanf("%d", &a)!=EOF){
        if(a<0){
            break;
        }
        x = 1;
        y = pow(2, x);

        while(y<a){
            x++;
            y = pow(2,x);
        }
        if(a==1){
            x=0;
        }
        printf("Case %d: %d\n", n, x);
        n++;
    }

    return 0;
}
