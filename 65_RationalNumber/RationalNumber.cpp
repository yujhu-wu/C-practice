#include "RationalNumber.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

RationalNumber::RationalNumber ( int p1, int q1 )
    :p ( p1 ), q ( q1 )
{

}


ostream &operator<< ( ostream &output,  RationalNumber &ther1 )
{
    int n1 = ther1.p;
    int n2 = ther1.q;

    if ( n1 < 0 )
    {
        n1 *= -1;
    }
    if ( n2 < 0 )
    {
        n2 *= -1;
    }

    double maxnum = n1;
    if ( n2 > maxnum )
    {
        maxnum = n2;
    }


    for ( int i = 2; i <= maxnum/2 ; ++i )
    {
        if ( (ther1.p != 0) && (ther1.q  != 0 ))
        {
            while ( ((ther1.p % i) == 0 )&& ((ther1.q % i) == 0 ))
            {
                ther1.p /=  i;
                ther1.q /=  i;
            }
        }
    }
    if ( ther1.p == 0 )
    {
        output << 0;
    }
    else if ( ther1.p % ther1.q == 0 )
    {
        output << ther1.p / ther1.q;

    }
    else
    {
        if ( ther1.p < 0 && ther1.q < 0 )
        {
            output << ther1.p * -1 << "/" << ther1.q * -1;
        }
        else if ( ther1.p > 0 && ther1.q < 0 )
        {
            output << ther1.p * -1 << "/" << ther1.q * -1;
        }
        else
        {
            output << ther1.p  << "/" << ther1.q ;
        }

    }
    return output;

}

istream &operator >> ( istream &input,  RationalNumber &ther2 )
{
    int a, b;
    input >> a >> b;
    ther2.p = a;
    ther2.q = b;
    return input;

}

std::string operator + ( const RationalNumber &rn1, const RationalNumber&rn2 )
{
    int thep, theq;
    theq = rn1.q * rn2.q;
    thep = ( rn1.p * rn2.q ) + ( rn2.p * rn1.q );

    int n1 = thep;
    int n2 = theq;

    if ( n1 < 0 )
    {
        n1 *= -1;
    }
    if ( n2 < 0 )
    {
        n2 *= -1;
    }

    double maxnum = n1;
    if ( n2 > maxnum )
    {
        maxnum = n2;
    }


    for ( int i = 2; i <= maxnum  ; ++i )
    {
        if ( (thep != 0) && (theq  != 0 ))
        {
            while ( ((thep % i) == 0 )&& ((theq % i) == 0 ))
            {
                thep /=  i;
                theq /=  i;
            }
        }
    }



    if ( thep == 0 )
    {
        string s3 = "0";
        return s3;
    }
    else if ( thep % theq == 0 )
    {
        int n = thep / theq;
        string s1 = to_string(n);
        return s1;

    }
    else
    {
        if ( thep < 0 && theq < 0 )
        {
            int n1 = thep * -1;
            int n3 = theq * -1;
            string s1 = to_string(n1);
            string s2 = to_string(n3);
            string s3;
            s3.append ( s1 ).append( "/" ).append ( s2 );
            return s3;
        }
        else if ( thep > 0 && theq < 0 )
        {
            int n1 = thep * -1;
            int n3 = theq * -1;
            string s1 = to_string(n1);
            string s2 = to_string(n3);
            string s3;
            s3.append ( s1 ).append( "/" ).append ( s2 );
            return s3;
        }
        else
        {
            int n1 = thep ;
            int n3 = theq ;
            string s1 = to_string(n1);
            string s2 = to_string(n3);
            string s3;
            s3.append ( s1 ).append( "/" ).append ( s2 );
            return s3;
        }

    }


}

std::string operator - ( const RationalNumber &rn1, const RationalNumber&rn2 )
{
    int thep, theq;
    theq = rn1.q * rn2.q;
    thep = ( rn1.p * rn2.q ) - ( rn2.p * rn1.q );

    int n1 = thep;
    int n2 = theq;

    if ( n1 < 0 )
    {
        n1 *= -1;
    }
    if ( n2 < 0 )
    {
        n2 *= -1;
    }

    double maxnum = n1;
    if ( n2 > maxnum )
    {
        maxnum = n2;
    }


    for ( int i = 2; i < maxnum/2 ; ++i )
    {
        if ( n1 != 0 && n2  != 0 )
        {
            while ( thep % i == 0 && theq % i == 0 )
            {
                thep /= i;
                theq /= i;
            }
        }
    }




    if ( thep == 0 )
    {
        string s3 = "0";
        return s3;
    }
    else if ( thep % theq == 0 )
    {
        int n = thep / theq;
        string s1 = to_string(n);
        return s1;

    }
    else
    {
        if ( thep < 0 && theq < 0 )
        {
            int n1 = thep * -1;
            int n3 = theq * -1;
            string s1 = to_string(n1);
            string s2 = to_string(n3);
            string s3;
            s3.append ( s1 ).append( "/" ).append ( s2 );
            return s3;
        }
        else if ( thep > 0 && theq < 0 )
        {
            int n1 = thep * -1;
            int n3 = theq * -1;
            string s1 = to_string(n1);
            string s2 = to_string(n3);
            string s3;
            s3.append ( s1 ).append( "/" ).append ( s2 );
            return s3;
        }
        else
        {
            int n1 = thep ;
            int n3 = theq ;
            string s1 = to_string(n1);
            string s2 = to_string(n3);
            string s3;
            s3.append ( s1 ).append( "/" ).append ( s2 );
            return s3;
        }

    }
}

std::string operator * ( const RationalNumber &rn1, const RationalNumber&rn2 )
{
    int thep, theq;
    theq = rn1.q * rn2.q;
    thep = ( rn1.p * rn2.p );

    int n1 = thep;
    int n2 = theq;

    if ( n1 < 0 )
    {
        n1 *= -1;
    }
    if ( n2 < 0 )
    {
        n2 *= -1;
    }

    double maxnum = n1;
    if ( n2 > maxnum )
    {
        maxnum = n2;
    }


    for ( int i = 2; i < maxnum/2 ; ++i )
    {
        if ( n1 != 0 && n2  != 0 )
        {
            while ( thep % i == 0 && theq % i == 0 )
            {
                thep /= i;
                theq /= i;
            }
        }
    }




    if ( thep == 0 )
    {
        string s3 = "0";
        return s3;
    }
    else if ( thep % theq == 0 )
    {
        int n = thep / theq;
        string s1 = to_string(n);
        return s1;

    }
    else
    {
        if ( thep < 0 && theq < 0 )
        {
            int n1 = thep * -1;
            int n3 = theq * -1;
            string s1 = to_string(n1);
            string s2 = to_string(n3);
            string s3;
            s3.append ( s1 ).append( "/" ).append ( s2 );
            return s3;
        }
        else if ( thep > 0 && theq < 0 )
        {
            int n1 = thep * -1;
            int n3 = theq * -1;
            string s1 = to_string(n1);
            string s2 = to_string(n3);
            string s3;
            s3.append ( s1 ).append( "/" ).append ( s2 );
            return s3;
        }
        else
        {
            int n1 = thep ;
            int n3 = theq ;
            string s1 = to_string(n1);
            string s2 = to_string(n3);
            string s3;
            s3.append ( s1 ).append( "/" ).append ( s2 );
            return s3;
        }

    }
}

std::string operator / ( const RationalNumber &rn1, const RationalNumber&rn2 )
{
    if ( rn2.p != 0 )
    {
        int thep, theq;
        theq = rn1.q * rn2.p;
        thep = ( rn1.p * rn2.q );

        int n1 = thep;
        int n2 = theq;

        if ( n1 < 0 )
        {
            n1 *= -1;
        }
        if ( n2 < 0 )
        {
            n2 *= -1;
        }

        double maxnum = n1;
        if ( n2 > maxnum )
        {
            maxnum = n2;
        }


        for ( int i = 2; i < maxnum/2 ; ++i )
        {
            if ( n1 != 0 && n2  != 0 )
            {
                while ( thep % i == 0 && theq % i == 0 )
                {
                    thep /= i;
                    theq /= i;
                }
            }
        }




        if ( thep == 0 )
        {
            string s3 = "0";
            return s3;
        }
        else if ( thep % theq == 0 )
        {
            int n = thep / theq;
            string s1 = to_string(n);
            return s1;

        }
        else
        {
            if ( thep < 0 && theq < 0 )
            {
                int n1 = thep * -1;
                int n3 = theq * -1;
                string s1 = to_string(n1);
                string s2 = to_string(n3);
                string s3;
                s3.append ( s1 ).append( "/" ).append ( s2 );
                return s3;
            }
            else if ( thep > 0 && theq < 0 )
            {
                int n1 = thep * -1;
                int n3 = theq * -1;
                string s1 = to_string(n1);
                string s2 = to_string(n3);
                string s3;
                s3.append ( s1 ).append( "/" ).append ( s2 );
                return s3;
            }
            else
            {
                int n1 = thep ;
                int n3 = theq ;
                string s1 = to_string(n1);
                string s2 = to_string(n3);
                string s3;
                s3.append ( s1 ).append( "/" ).append ( s2 );
                return s3;
            }

        }
    }
    else
    {
        throw runtime_error ( "Divide by zero." );
    }

}
