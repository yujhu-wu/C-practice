#include <stdio.h>
#include <stdlib.h>

int main()
{
    int s1, s2, r1, r2;
    int step;
    int a [ 500 ] [ 500 ];
    int result [ 500 ] [ 500 ];
    double row;
    int n;
    int max;
    double column;
    int pass = 0;

    while ( scanf ( "%d", &s1 ) ){
        if ( pass > 0 ){
            printf ( "\n" );
        }
        if ( s1 == '*' ){
            break;
        }
        else{
            scanf ( "%d %d %d %d", &s2, &r1, &r2, &step );
        }

        for ( int i = 0; i < s1; ++i ){
            for ( int j = 0; j < s2; ++j ){
                scanf ( "%d", &n );
                a [ i ] [ j ] = n;
            }
        }
        row = ( ( s1 - r1 + 1 ) / ( double ) step );
        column = ( ( s2 - r2 + 1 ) / ( double ) step );
        if ( row != ( int ) row ){
            row = ( int ) row + 1;
        }
        if ( column != ( int ) column ){
            column = ( int ) column + 1;
        }

        for ( int j = 0; j < row; ++j ){
            for ( int k = 0; k < column; ++k ){
                max = a [ j * step ] [ k * step ];

                for ( int l = j * step; l <= ( ( ( j * step ) + r1 ) - 1 ); ++l ){
                    for ( int m = k * step; m <= ( ( ( k * step ) + r2 ) - 1); ++m ){
                        if ( a [ l ] [ m ] > max ){
                            max = a [ l ] [ m ];
                        }
                    }
                }
                result [ j ] [ k ] = max;
            }
        }
        for ( int o = 0; o < row; ++o ){
            for ( int p = 0; p < column; ++p ){
                printf ( "%d", result [ o ] [ p ] );
                if ( p < column - 1 ){
                    printf ( " " );
                }
                if ( p == column - 1 ){
                    printf ( "\n" );
                }
            }
        }
        pass++;
    }
}
