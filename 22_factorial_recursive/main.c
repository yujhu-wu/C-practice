#include <stdio.h>
#include <stdlib.h>
long long int array [ 6 ] = { };//make array empty
int recursive ( int x );
int main ( void )
{

    int n = 0;
    for ( int j = 1; j <= 40; ++j )
    {
        for ( int l = 0; l <= 5; l++ )
        {
            array [ l ] = 0;
        }
        scanf ( "%d", &n );
        recursive ( n );


        if ( n == 1 )
        {
            printf ( "The 1st factorial number is 1.\n" );
        }
        else if ( n == 2 )
        {
            printf ( "The 2nd factorial number is 2.\n" );
        }
        else if ( n == 3 )
        {
            printf ( "The 3rd factorial number is 6.\n" );
        }
        else if ( n == 4 )
        {
            printf ( "The 4th factorial number is 24.\n" );
        }
        else if ( n > 4 )
        {
            printf ( "The %dth factorial number is", n );
            for ( int k = 0; k <= 5; ++k )
            {

                if ( array [ k ] == 0)
                {
                    if ( k == 5 )
                    {
                        printf ( " 00000000" );
                        continue;
                    }
                    continue;
                }
               if ( array [ k - 1 ] > 0 && array [ k ] <= 9999999 )
               {
                   if ( array [ k ] >= 1000000 )
                   {
                       printf ( " 0%lld", array [ k ] );
                       continue;
                   }

                   else if ( array [ k ] >= 100000 )
                   {
                       printf ( " 00%lld", array [ k ] );
                       continue;
                   }
               }
                printf ( " %lld", array [ k ] );
            }
            printf ( ".\n" );
        }

    }
    return 0;
}

int recursive ( int x )
{
    if ( x == 1)
    {
        array [ 5 ] = 1;
    }
    else
    {
        recursive ( x - 1 );
        for ( int i = 0; i <= 5; ++i )
        {
            array [i] *= x;
        }

        if ( array [ 5 ] > 99999999 )//shift if number over the limit
        {
            array [ 4 ] += array [ 5 ] / 100000000;
            array [ 5 ] %= 100000000;

        }
        if ( array [ 4 ] > 99999999 )
        {
            array [ 3 ] += array [ 4 ] / 100000000;
            array [ 4 ] %= 100000000;
        }
        if ( array [ 3 ] > 99999999 )
        {
            array [ 2 ] += array [ 3 ] / 100000000;
            array [ 3 ] %= 100000000;
        }
        if ( array [ 2 ] > 99999999 )
        {
            array [ 1 ] += array [ 2 ] / 100000000;
            array [ 2 ] %= 100000000;
        }
        if ( array [ 1 ] > 99999999 )
        {
            array [ 0 ] += array [ 1 ] / 100000000;
            array [ 1 ] %= 100000000;
        }


    }
}
