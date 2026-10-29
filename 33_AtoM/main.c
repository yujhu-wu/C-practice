#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c;
    char up, method;
    int array [ 1000 ];
    int array2 [ 300 ] [ 300 ];
    int n;
    int pass = 0;

    while ( scanf ( "%d", &a ) ){
        if ( pass > 0 ){
            printf ( "\n" );
        }
        if ( a == '*' ){
            break;
        }
        else{
            scanf ( "%d %d %c %c", &b, &c, &up, &method );
            pass++;
        }

        if ( up == 'U' ){
            for ( int i = 0; i < c; ++i ){
                scanf ( "%d", &n );
                array [ i ] = n;
            }
            if ( method == 'R'){
                for ( int i = 0; i < a; ++i ){
                    for ( int j = 0; j < b; ++j ){
                        array2 [ i ] [ j ] = array [ ( i * b ) + j ];
                        printf ( "%d", array2 [ i ] [ j ] );
                        if ( j < b - 1 ){
                            printf ( " " );
                        }
                        if ( j == b - 1 ){
                            printf ( "\n" );
                        }
                    }
                }
            }
            else{
                for ( int k = 0; k < a; ++k ){
                    for ( int l = 0; l < b; ++l ){
                        array2 [ k ] [ l ] = array [ ( l * a ) + k ];
                        printf ( "%d", array2 [ k ] [ l ] );
                        if ( l < b - 1 ){
                            printf ( " " );
                        }
                        if ( l == b - 1 ){
                            printf ( "\n" );
                        }
                    }
                }
            }
        }
        else{
            for ( int i = 0; i < c; ++i ){
                scanf ( "%d", &n );
                array [ i ] = n;
            }
            if ( method == 'R' ){
                for ( int o = 0; o < c; ++o ){
                    printf ( "%d", array [ o ] );
                    if ( o < c - 1 ){
                        printf ( " " );
                    }
                    if ( o == c - 1 ){
                        printf ( "\n" );
                    }
                }
            }
            else{
                for ( int p = 0; p < b; ++p ){
                    for ( int q = 0; q < a; ++q ){
                        printf ( "%d", array [ ( q * b ) + p ] );
                        if ( p < b - 1 || q < ( a - 1 ) ){
                            printf ( " " );
                        }
                        if ( p ==  ( b - 1 ) && q == ( a - 1 ) ){
                            printf ( "\n" );
                        }
                    }
                }
            }
        }
    }
    return 0;
}
