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
