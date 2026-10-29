#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    unsigned int n;
    int flag = 0;
    int t;
    t = sizeof ( n );

    while ( scanf ( "%d", &n ) != EOF )
    {
        if ( flag > 0 )
        {
            putchar ( '\n' );
        }
        printf ( "%5d = ", n );
        unsigned int displayMask = 1 << 31;
        for ( unsigned int roll = 1; roll <= t * CHAR_BIT ; ++roll )
        {
            if ( ( ( t * CHAR_BIT ) - roll ) < 16 )
            {
                putchar ( n & displayMask ? '1' : '0' );
                if ( roll == 24 )
                {
                    putchar ( ' ' );
                }
            }
            n <<= 1;
        }
        flag += 1;
    }
}
