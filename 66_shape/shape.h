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
