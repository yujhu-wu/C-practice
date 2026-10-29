#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count=0;
    for(count=1; count<=386; ++count){
        int n=0;
        int base=0;
        int shift=1;
        int d=0;
        scanf("%d %d", &n, &base);
        printf("The number %d in base %d is ", n, base);
        while(shift<n){
            shift *= base;
        }
        while(shift>n){
            shift /= base;
        }
        while(shift!=0){
            printf("%d", n/shift);
            n %= shift;
            shift /= base;
        }
        printf(".\n");
    }
    return 0;
}
