#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct people
{
    char *fn;
    char *ln;
    char *nn;
    char *a;
    char *g;
    char *u;
    char *d;
};

int main()
{
    char c [ 1000 ] ;
    struct people s [ 1000 ];
    int flag;

    printf ( "First Name   Last Name   Nick Name   Age   Gender   University                    Department\n" );
    printf ( "----------------------------------------------------------------------------------------------------------------\n" );

    for ( int i = 0; i < 484; ++i )
    {
        gets ( c );
        s [ i ].fn = strtok (  c, "," );
        s [ i ].ln = strtok ( NULL, "," );
        s [ i ].nn = strtok ( NULL, "," );
        s [ i ].a = strtok ( NULL, "," );
        s [ i ].g = strtok ( NULL, "," );
        s [ i ].u = strtok ( NULL, "," );
        s [ i ].d = strtok ( NULL, "," );

        printf ( "%-13s", s [ i ].fn );
        printf ( "%-12s", s [ i ].ln );
        printf ( "%-12s", s [ i ].nn );

        int n = atoi ( s [ i ].a );
        printf ( "%3d", n );

        flag = strcmp ( s [ i ].g ,"Female" );

        if ( flag == 0 )
        {
            strcpy ( s [ i ].g, "F" );
            printf ( "%6s      ", s [ i ].g );
        }
        else
        {
            strcpy ( s [ i ].g, "M" );
            printf ( "%6s      ", s [ i ].g );
        }

        printf ( "%-30s", s [ i ].u );
        printf ( "%s", s [ i ].d );
        printf ( "\n" );

    }
    printf ( "----------------------------------------------------------------------------------------------------------------\n" );
    return 0;
}
