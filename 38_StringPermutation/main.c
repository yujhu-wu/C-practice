#include <stdio.h>
#include <stdlib.h>
int main()
{
    int roll;
    scanf ( "%d", &roll );
    int order;
    int n;
    char c [ 100 ];
    char c1;
    int k;
    char hold;

    for ( int i = 0; i < ( roll * 2 ); ++i ){
        if ( i > 0 &&  ( i % 2 ) == 0 ){
            printf ( "\n" );
        }
        order = 0;
        n = 0;
        gets(c);

        while ( c [ n ] != 0 ){
            n++;
        }
        n -= 1;
        scanf ( "%d", &order );

        for ( int o = 0; o < order; ++o ){
            k = n;
            while ( k > 0 && c [ k - 1 ] >= c [ k ] ){
                --k;
            }
            if ( k <= 0 ){
                double len = ( double ) n / 2;
                for ( int l = 0; l < len ; ++l ){
                    hold = c [ l ];
                    c [ l ] = c [ n - l ];
                    c [ n - l ] = hold;
                }
                continue;
            }

            int j = n;
            while ( c [ j ] <= c [ k - 1 ] ){
                --j;
            }

            char temp = c [ k - 1 ];
            c [ k - 1 ] = c [ j ];
            c [ j ] = temp;

            j = n;
            while ( k < j ){
                temp = c [ k ];
                c [ k ] = c [ j ];
                c [ j ] = temp;
                ++k;
                --j;
            }
        }
        for ( int m = 0; m <= n; ++m ){
            printf ( "%c", c [ m ] );
        }
    }
    return 0;
}
