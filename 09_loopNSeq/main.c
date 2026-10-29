#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    for(int counter=1; counter<=n; ++counter){
        int t=0;
        int a=0;
        int c=0;
        int N=0;
        int i=0;
        scanf("%d %d %d %d", &t, &a, &c, &N);
        printf("Case %d:", counter);
        if(t==1){
            printf(" %d", a);
            for(i; i<N-1; i++){
                a *= c;
                printf(" %d", a);
        }
        }
        if(t==0){
            printf(" %d", a);
            for(i; i<N-1; i++){
                a += c;
                printf(" %d", a);
        }
        }
    printf("\n");
    }
    return 0;
}
