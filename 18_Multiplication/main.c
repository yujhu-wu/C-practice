#include <stdio.h>
#include <stdlib.h>

int main()
{
   int roll = 0;
   long long int c = 0;
   long long int n1 = 0;
   long long int  n2 = 1;
   long long int storen2; //storage of n2
   int i = 0;//roll
   int j = 0;
   int j1 = 0;//times for j1
   int k = 0;
   int not = 0;//don't have any number
   int d = 0;//the rest after / 10

   int s0 = 0;//count each number from 0 to 9
   int s1 = 0;
   int s2 = 0;
   int s3 = 0;
   int s4 = 0;
   int s5 = 0;
   int s6 = 0;
   int s7 = 0;
   int s8 = 0;
   int s9 = 0;
   for ( roll = 1; roll <= 50; ++roll )
   {
       n2 = 0;
       not = 0;
       scanf ( "%d", &c );
       while ( n2 * c < 1000000000 )
       {
           n2 += 1;
       }

       for ( i = n2 ; i <= 987654; ++i )
       {
           storen2 = i;

           if ( i >= 100000 )
           {
               j1 = 6;
               s0 = 0;
               s1 = 0;
               s2 = 0;
               s3 = 0;
               s4 = 0;
               s5 = 0;
               s6 = 0;
               s7 = 0;
               s8 = 0;
               s9 = 0;
           }
           else
           {
               j1 = 5;
               s0 = 0;
               s1 = 0;
               s2 = 0;
               s3 = 0;
               s4 = 0;
               s5 = 0;
               s6 = 0;
               s7 = 0;
               s8 = 0;
               s9 = 0;
           }

           for ( j = 1; j <= j1; ++j )
           {
               d = storen2 % 10;
               storen2 /= 10;

               if ( d ==  0)
               {
                   s0 += 1;
               }
               else if ( d ==  1)
               {
                   s1 += 1;
               }
               else if ( d ==  2)
               {
                   s2 += 1;
               }
               else if ( d ==  3)
               {
                   s3 += 1;
               }
               else if ( d ==  4)
               {
                   s4 += 1;
               }
               else if ( d ==  5)
               {
                   s5 += 1;
               }
               else if ( d ==  6)
               {
                   s6 += 1;
               }
               else if ( d ==  7)
               {
                   s7 += 1;
               }
               else if ( d ==  8)
               {
                   s8 += 1;
               }
               else if ( d ==  9)
               {
                   s9 += 1;
               }
           }
           if ( s0 > 1 || s1 > 1 || s2 > 1 || s3 > 1 || s4 > 1 || s5 > 1 || s6 > 1 || s7 > 1 || s8 > 1 || s9 > 1)
           {
               continue;
           }

           n1 = c * i;
           if ( n1 > 9999999999 )
           {
               continue;
           }
           s0 = 0;
           s1 = 0;
           s2 = 0;
           s3 = 0;
           s4 = 0;
           s5 = 0;
           s6 = 0;
           s7 = 0;
           s8 = 0;
           s9 = 0;

           for ( k = 1 ; k <= 10; ++k )
           {
               d = n1 % 10;
               n1 /= 10;

               if ( d ==  0)
               {
                   s0 += 1;
               }
               else if ( d ==  1)
               {
                   s1 += 1;
               }
               else if ( d ==  2)
               {
                   s2 += 1;
               }
               else if ( d ==  3)
               {
                   s3 += 1;
               }
               else if ( d ==  4)
               {
                   s4 += 1;
               }
               else if ( d ==  5)
               {
                   s5 += 1;
               }
               else if ( d ==  6)
               {
                   s6 += 1;
               }
               else if ( d ==  7)
               {
                   s7 += 1;
               }
               else if ( d ==  8)
               {
                   s8 += 1;
               }
               else if ( d ==  9)
               {
                   s9 += 1;
               }

           }
           if ( s0 > 1 || s1 > 1 || s2 > 1 || s3 > 1 || s4 > 1 || s5 > 1 || s6 > 1 || s7 > 1 || s8 > 1 || s9 > 1)
           {
               continue;
           }
           n1 = c * i;

           printf ( "%lld = %lld * %lld\n", n1, c, i );
           not = 1;

       }
       if ( not == 0 )
       {
           printf ( "Solution Not Found for c = %lld.\n", c );
       }
       if ( roll < 50 )
       {
           printf( "\n" );
       }

       not = 0;


   }
}
