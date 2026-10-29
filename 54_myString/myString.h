#include <iostream>
#include <string>

class MyString
{
public:
    explicit MyString ( std::string input )
        : s ( input )
    {

    }

    void set_string ( std::string input )
    {
        s = input;
    }
    std::string get_string ()
    {
        return s;
    }
    int compact_sum()
    {
        int sum;
        for ( int i = 0; i < s.length(); ++i )
        {
            if ( s [ i ] >= 'a' )
            {
                sum += s [ i ] - 'a' + 1;
            }
            else
            {
                sum += s [ i ] - 'A' + 1;
            }
        }
        while ( sum >= 10 )
        {
            int p1, p2, p3, p4;
            int sum2 = sum;
            if ( sum >= 1000 )
            {
                p1 = sum2 / 1000;
                sum2 -= p1 * 1000;
                p2 = sum2 / 100;
                sum2 -= p2 * 100;
                p3 = sum2 / 10;
                sum2 -= p3 * 10;
                p4 = sum2;
                sum2 -= p4;
                sum = p1 + p2 + p3 + p4;
                sum2 = sum;
            }
            if ( sum >= 100 && sum < 1000)
            {
                p1 = sum2 / 100;
                sum2 -= p1 * 100;
                p2 = sum2 / 10;
                sum2 -= p2 * 10;
                p3 = sum2;
                sum2 -= p3;
                sum = p1 + p2 + p3;
                sum2 = sum;
            }
            if ( sum >= 10 && sum < 100 )
            {
                p1 = sum2 / 10;
                sum2 -= p1 * 10;
                p2 = sum2;
                sum2 -= p2;
                sum = p1 + p2;
                sum2 = sum;
            }
        }
        return sum;
    }
private:
    std::string s;
};
