#include "Point2D.h"

/*This class contains two double values, which will be used to represent a set of (x, y)
Cartesian coordinates. This class and Point2D (described below) will be used to simplify 
keeping track of the coordinates of each object in the game, and updating their locations 
as they move. 
All data members and functions for this class should be public.
*/
Point2D::Point2D()
{
    this -> x=0;
    this -> y=0;
}

Point2D::Point2D(double in_x,double in_y)
{
    this -> x=in_x;
    this -> y=in_y;
}

//Non-Member Functions
//Returns the Cartesian (ordinary) distance between p1 and p2
double GetDistanceBetween(Point2D p1, Point2D p2)
{
    //Distance Formula
    return sqrt( pow((p1.x-p2.x),2) + pow((p1.y-p2.y),2) );
}

//Non-member Overloaded Operators (assume p1 and p2 represent two Point2D objects, and v1 represents a Vector2D object)
//Stream output Operator
ostream& operator<<(ostream& out, const Point2D p1) //Do I need const here. Why do I need an & after Point2D
{
    out << "(" << p1.x << ", " << p1.y << ")";
    return out;
}

//Addition Operator
Point2D operator+(const Point2D p1, const Vector2D v1)
{
    double newX=p1.x+v1.x;
    double newY=p1.y+v1.y;
    //Make a new Point2D with newX and newY
    Point2D newPoint(newX,newY);
    return newPoint;
}

Vector2D operator-(const Point2D p1, const Point2D p2)
{
    double newX=p1.x-p2.x;
    double newY=p1.y-p2.y;
    //Make a new Point2D with newX and newY
    Vector2D newVec(newX,newY);
    return newVec; 
}


