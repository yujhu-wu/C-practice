#include <stdio.h>
#include <stdlib.h>

int hanoi(int a);
int main()
{
    int number;

    while(scanf("%d", &number)!=EOF){
        int result = hanoi(number);
        printf("%u\n",result);
    }
    return 0;
}
int hanoi(int a)
{
    if(a==1){
        return a;
    }
    else if(a%2==0){
        return hanoi(a-1)+a;
    }
    else{
        return hanoi(a-1)+a+1;
    }
}
