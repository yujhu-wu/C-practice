#include <stdio.h>
#include <stdlib.h>

int main()
{
    int chess [ 30 ];
    int queen;
    int range;
    int x;
    int y;
    int attack;
    int pass = 0;
    while ( scanf ( "%d", &range ) )
    {
        if ( pass > 0 ){
            printf ( "\n" );
        }
        if ( range == 0 ){
            break;
        }
        for ( int m = 0; m < range; ++m ){
            chess [ m ] = 0;
        }

        for ( int i = 0; i < range; ++i ){
            for ( int j = 0; j < range; ++j ){
                scanf ( "%d", &queen );
                if ( queen == 1 ){
                    chess [ i ] = j;
                }
            }
        }
        attack = 0;

        for ( int k = 0; k < range - 1; ++k ){
            for ( int l = k + 1; l < range; ++l ){
                x = l - k;
                y = chess [ l ] - chess [ k ];
                if ( y < 0 ){
                    y *= -1;
                }
                if ( x == y ){
                    attack += 1;
                }
            }
        }

        if ( attack == 1 ){
            printf ( "There is 1 attack.\n" );
        }
        else if ( attack == 0 ){
            printf ( "There is no attack.\n" );
        }
        else{
            printf ( "There are %d attacks.\n", attack );
        }
    }
}
