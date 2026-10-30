# shape

> C/C++程式設計練習 · [回到目錄](../README.md)

- **主題**：繼承 / 多型
- **語言**：C++
- **程式碼**：[main.cpp](main.cpp)、[shape.cpp](shape.cpp)、[shape.h](shape.h)

## 題目

Shape is a common and abstract concept with many forms. To establish a useful tool for shapes, we can use the fascinating features in C++: the polymorphism. Your goal is to write a program handling different shapes using dynamic binding. You have to provide a general shape class Shape, and several specific shape classes, including square, circle, equilateral triangle, cube, sphere, rectangle, isosceles triangle, triangle, and cuboid. These classes must contain:

1. Private data members for the parameters of a shape.
2. Appropriate constructors and destructors.
3. Appropriate accessors, mutators, and utility functions.
4. Input member function for input the parameters of a shape.
5. Output member function for output the result.

**Input**

The input contains 1000 cases. The first 1000 numbers denote the types of the shapes. Specifically, 0 ~ 8 represent square, circle, equilateral triangle, cube, sphere, rectangle, isosceles triangle, triangle, and cuboid, respectively. The numbers going after the first 1000 numbers are the parameters for the shapes. The number of parameters corresponds to the type of the shape. Note that the first parameter for a isosceles triangle is the length of the two equal sides.

**Output**

For each case, output the area/volume according to the types of the shapes, and the corresponding parameters. For more details about the format, please see the sample output. Hint: You can use Heron's formula to calculate the area of a triangle.

**Sample Input**

```
0 1 2 3 4 5 6 7 8
51
41
14
45
35
42 47
43 72
36 10 42
40 60 42
```

**Sample Output**

```
The area of square with sides 51 = 2601
The area of circle with radius 41 = 1681 PI
The area of equilateral triangle with sides 14 = sqrt(7203)
The volume of cube with sides 45 = 91125
The volume of sphere with radius 35 = 57166 PI
The area of rectangle with sides 42 and 47 = 1974
The area of isosceles triangle with sides 43 and 72 = sqrt(716688)
The area of triangle with sides 36, 10 and 42 = sqrt(23936)
The volume of cuboid with sides 40, 60 and 42 = 100800
```

## 程式碼

### main.cpp

```cpp
#include <iostream>
#include <vector>
#include "shape.h"

using namespace std;

int main()
{
    const size_t numInput = 1000;
    vector<int> shapeState(numInput);

    for ( int &c : shapeState )
    {
        cin >> c;
    }

    vector<Shape*> shapeVector(numInput);
    size_t n = 0;
    for ( Shape* &shapePtr : shapeVector )
    {
        switch(shapeState[n++])
        {
        case 0:
            shapePtr = new Square;
            break;
        case 1:
            shapePtr = new Circle;
            break;
        case 2:
            shapePtr = new EquTriangle;
            break;
        case 3:
            shapePtr = new Cube;
            break;
        case 4:
            shapePtr = new Sphere;
            break;
        case 5:
            shapePtr = new Rectangle;
            break;
        case 6:
            shapePtr = new IsoTriangle;
            break;
        case 7:
            shapePtr = new Triangle;
            break;
        case 8:
            shapePtr = new Cuboid;
            break;
        default:
            cerr << "Error Shape State" << endl;
            break;
        }
    }

    for ( Shape* shapePtr : shapeVector )
    {
        shapePtr->input()->output();
    }

    for ( Shape* &shapePtr : shapeVector )
    {
        delete shapePtr;
    }

    return 0;
}
```

### shape.cpp

```cpp
#include "shape.h"
#include <iostream>
#include <string>
using namespace std;

Shape::Shape ()
{

}

Shape* Shape::output ()
{

    return this;
}

Shape* Shape::input ()
{
    return this;
}




Square::Square (  )
{

}

Square* Square::output ()
{
    cout << "The area of square with sides " << r1 << " = " << r1 * r1 << endl;
    return this;
}

Square* Square::input ()
{
    int ther;
    cin >> ther;
    r1 = ther;

    return this;
}

Circle::Circle (  )
{

}

Circle* Circle::output ()
{
    cout << "The area of circle with radius "<< r1 << " = " << r1 * r1 << " PI"  << endl;
    return this;
}

Circle* Circle::input ()
{
    int ther;
    cin >> ther;
    r1 = ther;

    return this;
}

EquTriangle::EquTriangle ( )
{

}

EquTriangle* EquTriangle::output ()
{
    cout << "The area of equilateral triangle with sides " << r1 << " = sqrt(" << (( r1 * r1 * r1 * r1 ) *3)/16  << ")"  << endl;
    return this;
}

EquTriangle* EquTriangle::input ()
{
    int ther;
    cin >> ther;
    r1 = ther;

    return this;
}

Cube::Cube (  )
{

}

Cube* Cube::output ()
{
    cout << "The volume of cube with sides " << r1 << " = " << r1 * r1 * r1 << endl;
    return this;
}

Cube* Cube::input ()
{
    int ther;
    cin >> ther;
    r1 = ther;

    return this;
}

Sphere::Sphere ( )
{

}

Sphere* Sphere::output ()
{
    cout << "The volume of sphere with radius " << r1 << " = " << r1 * r1 * r1 * 4 / 3 << " PI" << endl;
    return this;
}

Sphere* Sphere::input ()
{
    int ther;
    cin >> ther;
    r1 = ther;

    return this;
}

Rectangle::Rectangle (  )
{

}

Rectangle* Rectangle::output ()
{
    cout << "The area of rectangle with sides " << r1 << " and " << r2 << " = " << r1 * r2  << endl;
    return this;
}

Rectangle* Rectangle::input ()
{
    int ther, ther2;
    cin >> ther >> ther2;
    r1 = ther;
    r2 = ther2;

    return this;
}

IsoTriangle::IsoTriangle (  )
{

}

IsoTriangle* IsoTriangle::output ()
{
    int halfr = r2 / 2;

    cout << "The area of isosceles triangle with sides " << r1 << " and " << r2 << " = sqrt(" <<  (( r1 * r1 ) - (halfr* halfr))* halfr * halfr  << ")" << endl;
    return this;
}

IsoTriangle* IsoTriangle::input ()
{
    int ther, ther2;
    cin >> ther >> ther2;
    r1 = ther;
    r2 = ther2;

    return this;
}

Triangle::Triangle (  )
{

}


Triangle* Triangle::output ()
{
    int s = (r1 + r2 + r3 ) /2;

    cout << "The area of triangle with sides " << r1 << ", " << r2 << " and " << r3 << " = sqrt(" <<  s * ( s - r1 ) * ( s - r2 ) * ( s - r3 ) << ")" << endl;
    return this;
}

Triangle* Triangle::input ()
{
    int ther, ther2, ther3;
    cin >> ther >> ther2 >> ther3;
    r1 = ther;
    r2 = ther2;
    r3 = ther3;

    return this;
}

Cuboid::Cuboid (  )
{

}

Cuboid* Cuboid::output ()
{

    cout << "The volume of cuboid with sides " << r1 << ", " << r2 << " and " << r3 << " = " <<   r1 * r2 * r3 << endl;
    return this;
}

Cuboid* Cuboid::input ()
{
    int ther, ther2, ther3;
    cin >> ther >> ther2 >> ther3;
    r1 = ther;
    r2 = ther2;
    r3 = ther3;

    return this;
}
```

### shape.h

```cpp
#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>


class Shape
{
public:
    Shape ();
    virtual ~Shape () {}
    virtual  Shape* output ();
    virtual Shape* input ();

private:

};

class Square:public Shape
{
public:
    Square (  );
    virtual ~Square () {}
    Square* output ()  override;
    Square* input () override;

private:
    int r1;

};

class Circle:public Shape
{
public:
    Circle (  );
    virtual ~Circle () {}
    Circle* output () override;
    Circle* input () override;

private:
    int r1;

};

class EquTriangle:public Shape
{
public:
    EquTriangle (  );
    virtual ~EquTriangle () {}
    EquTriangle* output () override;
    EquTriangle* input () override;

private:
    int r1;

};

class Cube:public Shape
{
public:
    Cube (  );
    virtual ~Cube () {}
    Cube* output () override;
    Cube* input () override;

private:
    int r1;

};

class Sphere:public Shape
{
public:
    Sphere (  );
    virtual ~Sphere () {}
    Sphere* output () override;
    Sphere* input () override;

private:
    int r1;

};

class Rectangle:public Shape
{
public:
    Rectangle (   );
    virtual ~Rectangle () {}
    Rectangle* output () override;
    Rectangle* input () override;

private:
    int r1;
    int r2;

};

class IsoTriangle:public Shape
{
public:
    IsoTriangle (  );
    virtual ~IsoTriangle () {}
    IsoTriangle* output () override;
    IsoTriangle* input () override;

private:
    int r1;
    int r2;

};

class Triangle:public Shape
{
public:
    Triangle (  );
    virtual ~Triangle () {}
    Triangle* output () override;
    Triangle* input () override;

private:
    int r1;
    int r2;
    int r3;

};

class Cuboid:public Shape
{
public:
    Cuboid ( );
    virtual ~Cuboid () {}
    Cuboid* output () override;
    Cuboid* input () override;

private:
    int r1;
    int r2;
    int r3;

};
#endif // SHAPE_H
```

