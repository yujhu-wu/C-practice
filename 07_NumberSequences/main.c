#include <stdio.h>
#include <stdlib.h>

int main()
{
    int type;
    int a0;
    int c;
    int N;
    int z;
    int counter;

    scanf("%u", &counter);
    for(counter=0; counter < 243; counter++){
        scanf("%d %d %d %d", &type, &a0, &c, &N);
        z=a0;
        if(type == 1){
            for(; a0 < N; a0 += c){

            }
            printf("The least number in the arithmetic sequence starting from %d with difference %d over %d is ", z, c, N);
            printf("%d.\n", a0);
        }
        else if(type == 2){
            for(; a0 < N; a0 *= c){

            }
            printf("The least number in the geometric sequence starting from %d with ratio %d over %d is ", z, c, N);
            printf("%d.\n", a0);
        }
    }
    return 0;
}
