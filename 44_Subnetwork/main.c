#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <time.h>

int main()
{
    int num ;
    int index ;
    unsigned int ip ;
    unsigned int child ;
    int ipNum[4] ;
    int maskCode ;
    char ch[256] ;
    int flag = 0;

    int i ;
    unsigned int mask ;

    FILE *file = fopen( "test_input_Subnetwork.txt", "r" );

    while( 1 )
    {
        fscanf( file, "%d", &num );
        if( num == 0 )
        {
            break ;
        }
        if( flag > 0 )
        {
            printf("\n") ;
        }

        fscanf( file, "%d.%d.%d.%d/%d", ipNum, ipNum + 1, ipNum + 2, ipNum + 3, &maskCode );
        ip = ipNum[0] << 24 | ( ipNum[1] << 16 ) | ( ipNum[2] << 8 ) | ( ipNum[3] );
        printf( "--------------------------------------------------------------------------------\n" );
        printf( "The following addresses are within the subnetwork %d.%d.%d.%d/%d:\n", ipNum[0], ipNum[1], ipNum[2], ipNum[3], maskCode );

        mask = 0 ;
        for( i = 0 ; i < maskCode ; ++i )
            mask = ( mask >> 1 ) | 0x80000000 ;


        for( i = 0 ; i < num ; ++i )
        {
            fscanf( file, "%d.%d.%d.%d/%d", ipNum, ipNum + 1, ipNum + 2, ipNum + 3, &maskCode );
            child = ipNum[0] << 24 | ( ipNum[1] << 16 ) | ( ipNum[2] << 8 ) | ( ipNum[3] );
            if(( child & mask ) == ip )
            {
                printf( "%d.%d.%d.%d\n", ipNum[0], ipNum[1], ipNum[2], ipNum[3] );
            }
        }

        printf( "--------------------------------------------------------------------------------\n" );

        flag += 1;
    }

    return 0;
}
