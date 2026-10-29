#include <stdio.h>
#include <stdlib.h>

int main()
{
    int roll=0;
    int LB, UB;
    int a, b, c;
    int dot, j, i;
    int n;

    scanf("%d", &n);
    for(roll=1; roll<=243; ++roll){
        scanf("%d %d %d %d %d", &LB, &UB, &a, &b, &c);
        dot=0;
        for(i=LB; i<=UB; ++i){
            for(j=LB; j<=UB; ++j){
                if(a * i + b * j <= c){
                    dot += 1;
                }
            }
        }
        if(b >= 0){
            printf("The square area within %d to %d below the line %dx+%dy<=%d is %d.\n", LB, UB, a, b, c, dot);
        }
        if(b < 0){
            printf("The square area within %d to %d below the line %dx%dy<=%d is %d.\n", LB, UB, a, b, c, dot);
        }
    }
    return 0;
}
