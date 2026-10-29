#include <stdio.h>
#include <stdlib.h>

int gcd(int x, int y);
int main()
{
    int x,y;
    int g,l;
    while(scanf("%d %d", &x, &y)!=EOF){
        g= gcd(x,y);
        l= lcm(x,y);
        printf("%d %d\n", g, l);
    }
    return 0;
}

int gcd(int x, int y)
{
    if(y==0){
        return x;
    }
    else{
        return gcd(y, x%y);
    }
}

int lcm(int x, int y)
{
    return x*y / gcd(x,y);
}
