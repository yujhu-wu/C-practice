#include <stdio.h>
#include <stdlib.h>

int main()
{
    int roll = 0;
    for ( roll = 1; roll <= 437; ++roll )
    {
        int base, a, b;//a,b two numbers
        int sum = 0;
        int carry = 0;
        scanf( "%d %d %d", &base, &a, &b );
        printf( "Case %d: %d + %d (base %d)\n", roll, a, b, base );
        if(base == 1){
                break;
        }
        while ( a > 0 || b > 0 )
        {
            if ( a > 0 ){
                printf( "%d", a % 10 );
                sum += a % 10;
                a -= a % 10;
                a /= 10;
            }
            else{
                printf( "0" );
            }
            printf( " + " );
            if ( b > 0 ){
                printf( "%d", b % 10 );
                sum += b % 10;
                b -= b % 10;
                b /= 10;
            }
            else{
                printf( "0" );
            }
            printf( " + " );
            printf( "%d", carry );
            if ( carry >= 0 ){
                sum += carry;
            }
            carry = 0;
            if ( sum >= base ){
                printf( " = %d with one carry\n", sum - base );
                carry += 1;
            }
            else{
                printf( " = %d\n", sum );
            }
            sum = 0;
        }
        if ( carry > 0 ){
            printf( "0 + 0 + 1 = 1\n" );
            carry = 0;
        }
        printf( "\n" );

    }
    return 0;
}
