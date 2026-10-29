#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int n;
    int a;
    int sum;


    for(int c = 0; c <= 420; ++c){
       scanf("%d", &n);
       if(n == 0){break;}
       else{
        sum = 0;

         for(int i = 0; i < n; ++i){

            scanf("%d", &a);
            if(i == 0){
            printf("%d ", a);
            }
            else if(a > 0){
                printf("+ %d ", a);
            }
            else if(a <= 0){
                printf("- %d ", -a);
            }
            sum += a;

         }
         printf("= %d\n", sum);

        }
    }
    return 0;
}
