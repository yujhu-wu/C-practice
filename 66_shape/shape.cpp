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
