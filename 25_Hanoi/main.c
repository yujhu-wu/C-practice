#include <stdio.h>
#include <stdlib.h>

void hanoi(int, int, int, int);
    int a=1;
    int b=2;
    int c=3;

int main()
{
    int n;
    while(scanf("%d", &n)!=EOF){
        hanoi(n,a,b,c);
        printf("\n");
    }
}

void hanoi(int n, int a, int b, int c)
{
    if(n==1){
        printf("Move disk %d from %d to %d\n", n, a, c);
    }
    else{
        hanoi(n-1, a, c, b);
        printf("Move disk %d from %d to %d\n", n, a, c);
        hanoi(n-1, b, a, c);
    }
}
