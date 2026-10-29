#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s [ 1000 ];
    int flag;

    printf ( "First Name   Last Name   Nick Name   Age   Gender   University                    Department\n" );
    printf ( "----------------------------------------------------------------------------------------------------------------\n" );

    for ( int i = 0; i < 484; ++i )
    {
        gets ( s );
        char *fn = strtok (  s, "," );
        char *ln = strtok ( NULL, "," );
        char *nn = strtok ( NULL, "," );
        char *a = strtok ( NULL, "," );
        char *g = strtok ( NULL, "," );
        char *u = strtok ( NULL, "," );
        char *d = strtok ( NULL, "," );

        printf ( "%-13s", fn );
        printf ( "%-12s", ln );
        printf ( "%-12s", nn );

        int n = atoi ( a );
        printf ( "%3d", n );

        flag = strcmp ( g ,"Female" );

        if ( flag == 0 )
        {
            strcpy ( g, "F" );
            printf ( "%6s      ", g );
        }
        else
        {
            strcpy ( g, "M" );
            printf ( "%6s      ", g );
        }

        printf ( "%-30s", u );
        printf ( "%s", d );
        printf ( "\n" );

    }
    printf ( "----------------------------------------------------------------------------------------------------------------\n" );
    return 0;
}
