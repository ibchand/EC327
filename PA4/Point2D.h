#ifndef POINT2D_H
#define POINT2D_H
#include <iostream>
#include "Vector2D.h"
#include <math.h>
using namespace std;

class Point2D
{
public:
    double x;
    double y;
    Point2D();
    Point2D(double in_x,double in_y);
};

double GetDistanceBetween(Point2D p1, Point2D p2);
ostream& operator<<(ostream& out, const Point2D p1);
Point2D operator+(const Point2D p1, const Vector2D v1);
Vector2D operator-(const Point2D p1, const Point2D p2);

#endif