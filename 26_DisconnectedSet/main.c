#include <stdio.h>
#include <stdlib.h>

void hanoi(int, int, int, int);
    int a=1;
    int b=2;
    int c=2;

int main()
{
    int n;
    while(scanf("%d", &n)!=EOF){
        hanoi(n,a,b,c);
    }
}

void hanoi(int n, int a, int b, int c)
{
    if(n==1){
        printf("%d\n", a);
    }
    else if(n==2){
        printf("%d\n", b);
    }
    else if(n==3){
        printf("%d\n", c);
    }
    else if(n>3){
        return hanoi(n-1, b, c, a+b);
        printf("%d\n", a+b);
    }
}
