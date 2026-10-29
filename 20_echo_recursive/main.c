#include <stdio.h>
#include <stdlib.h>

int echo(int a);
int main()
{
    int n;
    int c;
    scanf("%d", &n);
    echo(c);
    for(int i=0; i<n; ++i){
        echo(c);
        printf("\n");
    }
    return 0;
}
int echo(int a)
{
    if((a= getchar()) !='\n'){
        echo(a);
        printf("%c", a);
    }
}
