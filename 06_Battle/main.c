#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int a, b;

    scanf("%d", &n);

    n = 1;
    while(scanf("%d %d", &a, &b)!=EOF){
        if(a<b){
            printf("Defending creature survived. No damage caused.\n");
        }
        else if(a>b, a-b>1){
            printf("Defending creature vanished. Attacker caused %d damages to opponent player.\n", a - b);
        }
        else if(a>b, a-b==1){
            printf("Defending creature vanished. Attacker caused %d damage to opponent player.\n", a - b);
        }
        else if(a==b){
            printf("Defending creature vanished. No damage caused.\n");
        }
        n++;
    }

    return 0;
}
