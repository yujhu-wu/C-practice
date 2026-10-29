#include <stdio.h>
#include <stdlib.h>

int main()
{
    int h[100][100];
    int x, y, i, j, k, l;
    int r=0;

    while(scanf("%d %d %d %d %d %d", &x, &y, &i, &j, &k, &l)==6){
        if(r==1){
            printf("\n");
        }
        r=1;
        for(int a=0; a<x; a++){
            for(int b=0; b<y; b++){
                scanf("%d", &h[a][b]);
            }
        }
        for(int z=i; z<=k; z++){
            for(int w=j; w<=l; w++){
                if(w==l){
                    printf("%d", h[z][w]);
                }
                else{
                    printf("%d ", h[z][w]);
                }
            }
            printf("\n");
        }
    }
}
