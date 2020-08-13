#ifndef VECTOR2D_H
#define VECTOR2D_H
#include <iostream>
#include <math.h>
using namespace std;

class Vector2D
{
public:
    double x;
    double y;
    Vector2D();
    Vector2D(double in_x,double in_y);
};
ostream& operator<<(ostream& out, const Vector2D v1);
Vector2D operator*(const Vector2D v1, const double d);
Vector2D operator/(const Vector2D v1, const double d);

#endif