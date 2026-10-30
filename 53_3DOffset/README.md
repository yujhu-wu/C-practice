# 3DOffset

> C/C++程式設計練習 · [回到目錄](../README.md)

- **主題**：類別
- **語言**：C++
- **程式碼**：[main.cpp](main.cpp)、[three_dimension_object.h](three_dimension_object.h)

## 題目

C++ provides the concept of class to encapsulate the attributes and behaviors of objects. One common behavior of real-world objects is their movement. To describe a movement, we must define the position, velocity, and acceleration along the x, y, and z axes as our real-world is of three dimension. Your goal is to write a program to determine the final position of an object according to above attributes. Specifically, you have to

1. An input function to get input values.
2. Give a class ThreeDimensionObject containing the above attributes.
3. A default constructor with default values 𝒙 = (𝟎, 𝟎, 𝟎), 𝒗 = 𝟑, −𝟓, 𝟕 , 𝒂 = (𝟑, 𝟐, −𝟏)
4. A set of overloaded member functions to initialize the data members.
5. A member function output_position to output the position according to the input time with default value 5.
6. All implementation should be applicable to the given main.cpp file.

**Input**

The first line contains an integer 𝑁, representing the number of cases. In the following 𝑁 lines, each line contains an integer 𝑛, representing the number of parameters to be inputted, followed by 𝑛 integers which in turn correspond to (if exist) the time, the positions along with x, y, and z coordinates, the velocities along with x, y and z coordinates, and the accelerations along with x, y, and z coordinates.

**Output**

For each line of input, output the 3D offsets with end line stream manipulator. All the calculation must be completed using integer operations.

**Sample Input**

```
11
0
1 6
2 6 1
3 6 1 2
4 6 1 2 3
5 6 1 2 3 -4
6 6 1 2 3 -4 5
7 6 1 2 3 -4 5 -6
8 6 1 2 3 -4 5 -6 7
9 6 1 2 3 -4 5 -6 7 -8
10 6 1 2 3 -4 5 -6 7 -8 9
```

**Sample Output**

```
52 0 23
72 6 24
73 6 24
73 8 24
73 8 27
31 8 27
31 68 27
31 68 -51
103 68 -51
103 -112 -51
103 -112 129
```

## 程式碼

### main.cpp

```cpp
#include <iostream>
#include "three_dimension_object.h"

using namespace std;

int main()
{
    unsigned int num_cases;
    cin >> num_cases;

    for ( unsigned int i = 1; i <= num_cases; ++i )
    {
        int x, y, z, xv, xa, yv, ya, zv, za;
        unsigned int num_par, t;
        input(num_par, t, x, y, z, xv, yv, zv, xa, ya, za); // implement input function

        ThreeDimensionObject object; // implement class ThreeDimensionObject
        switch(num_par) // implement overloaded member function initialize
        {
            case 2:
                object.initialize(x);
                break;
            case 3:
                object.initialize(x, y);
                break;
            case 4:
                object.initialize(x, y, z);
                break;
            case 5:
                object.initialize(x, y, z, xv);
                break;
            case 6:
                object.initialize(x, y, z, xv, yv);
                break;
            case 7:
                object.initialize(x, y, z, xv, yv, zv);
                break;
            case 8:
                object.initialize(x, y, z, xv, yv, zv, xa);
                break;
            case 9:
                object.initialize(x, y, z, xv, yv, zv, xa, ya);
                break;
            case 10:
                object.initialize(x, y, z, xv, yv, zv, xa, ya, za);
                break;
            default:
                break;
        }
        if ( num_par ) // implement member function output_position with default value
        {
            object.output_position(t);
        }
        else
        {
            object.output_position();
        }
    }

    return 0;
}
```

### three_dimension_object.h

```cpp
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
```

