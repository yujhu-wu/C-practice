#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c;
    int x, y;
    int lb, ub;
    int cnt;

    while(scanf("%d %d %d %d %d", &lb, &ub, &a ,&b ,&c)!=EOF){

        cnt = 0;
        for(x = lb; x<= ub; ++x){
            for(y = lb; y <= ub; ++y){
                if(a * x + b * y <= c){
                    ++cnt;
                }
            }
        }
        if(b >= 0){
          printf("The square area within %d to %d below the line %dx+%dy<=%d is %d.\n", lb, ub, a, b, c, cnt);
        }
        else if(b < 0){
          printf("The square area within %d to %d below the line %dx%dy<=%d is %d.\n", lb, ub, a, b, c, cnt);
        }
    }
    return 0;
}
