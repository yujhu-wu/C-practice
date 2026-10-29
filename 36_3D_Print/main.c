#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    scanf("%d", &a);
    int square, first, high, e;
    int position[10050];
    int start, start2;

    for(int i=1; i<=a;++i){
        start2 =0;
        scanf ("%d", &square);
        for(int l=0; l<10050; ++l){
        position[l] =0;
        }
        for(int j=0; j<square; ++j){
            scanf ("%d %d %d", &first, &high, &e);
            for(int k=first; k<e; ++k){
                if(position[k] <high){
                    position[k] =high;
                }
            }
            if(e>start2){
                start2=e;
            }
        }
        for(int m =0; m<start2; ++m){
            if(position[m] !=0){
                    start=m;
                    break;
            }
        }
        printf("Case %d:", i);
        printf(" %d %d", start, position[start]);
        for(int n=start; n<=start2; ++n){
            if(position[n] !=position[n+1]){
                printf (" %d", n +1);
                printf (" %d", position[n+1]);
            }
        }
        printf("\n");
    }
}
