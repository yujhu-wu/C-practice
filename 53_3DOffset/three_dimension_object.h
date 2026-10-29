#include <iostream>
#include <string>

void input ( unsigned int &num, unsigned int& t2 , int& x2 , int& y2 , int& z2 , int& xv2 , int& yv2 , int& zv2 , int& xa2 , int& ya2 , int& za2  )
{
    std::cin >> num;
    if ( num == 1 )
    {
        std::cin >> t2;
    }
    else if ( num == 2 )
    {
        std::cin >> t2 >> x2;
    }
    else if ( num == 3 )
    {
        std::cin >> t2 >> x2 >> y2;
    }
    else if ( num == 4 )
    {
        std::cin >> t2 >> x2 >> y2 >> z2;
    }
    else if ( num == 5 )
    {
        std::cin >> t2 >> x2 >> y2 >> z2 >> xv2;
    }
    else if ( num == 6 )
    {
        std::cin >> t2 >> x2 >> y2 >> z2 >> xv2 >> yv2;
    }
    else if ( num == 7 )
    {
        std::cin >> t2 >> x2 >> y2 >> z2 >> xv2 >> yv2 >> zv2;
    }
    else if ( num == 8 )
    {
        std::cin >> t2 >> x2 >> y2 >> z2 >> xv2 >> yv2 >> zv2 >> xa2;
    }
    else if ( num == 9 )
    {
        std::cin >> t2 >> x2 >> y2 >> z2 >> xv2 >> yv2 >> zv2 >> xa2 >> ya2;
    }
    else if ( num == 10)
    {
        std::cin >> t2 >> x2 >> y2 >> z2 >> xv2 >> yv2 >> zv2 >> xa2 >> ya2 >> za2;
    }
}

class ThreeDimensionObject
{

public:
    ThreeDimensionObject ( unsigned int t = 5, int x = 0, int y = 0, int z = 0, int xv = 3, int yv = -5, int zv = 7, int xa = 3, int ya = 2, int za = -1 )
        : t1 ( t ), x1 ( x ), y1 ( y ), z1 ( z ), xv1 ( xv ), yv1 ( yv ), zv1 ( zv ), xa1 ( xa ), ya1 ( ya ), za1 ( za )
    {

    }


    void initialize (  int  x = 0, int y = 0, int z = 0, int xv = 3, int yv = -5, int zv = 7, int xa = 3, int ya = 2, int za = -1 )
    {
        x1 = x;
        y1 = y;
        z1 = z;
        xv1 = xv;
        yv1 = yv;
        zv1 = zv;
        xa1 = xa;
        ya1 = ya;
        za1 = za;


    }
    void output_position ( unsigned int t = 5 )
    {
        t1 = t;
        x1 += xv1 * t1 + ( ( t1 * t1 * xa1 ) / 2 );
        y1 += yv1 * t1 + ( ( t1 * t1 * ya1 ) / 2 );
        z1 += zv1 * t1 + ( ( t1 * t1 * za1 ) / 2 );
        std::cout << x1 << " " << y1 << " " << z1 << std::endl;

    }
private:
    int x1, y1, z1, xv1, yv1, zv1, xa1, ya1, za1;
    int t1;
};
