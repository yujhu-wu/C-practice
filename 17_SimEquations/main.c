#include <stdio.h>
#include <stdlib.h>

int main()
{
    int u, v, w, P, Q, R;
    int a, i;

    scanf("%d", &a);
    for(i=1; i<=a; i++){
        scanf("%d %d %d", &P, &Q, &R);
        for(w=a; w<=P-5; ++w)
        for(v=3; v<w; v++){
            u= P- 2*v - 3*w;
            if((u + 2*v + 3*w == P) && (u*v*w == Q) && (u*u*u+v*v+w == R)){
                printf("Case %d: u = %d, v = %d, w = %d\n", i, u, v, w);
            }
        }
    }
    return 0;
}
