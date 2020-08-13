#include "Vector2D.h"

Vector2D::Vector2D()
{
    this -> x=0;
    this -> y=0;
}

Vector2D::Vector2D(double in_x,double in_y)
{
    this -> x=in_x;
    this -> y=in_y;
}

ostream& operator<<(ostream& out, const Vector2D v1)
{
    out << "<" << v1.x << ", " << v1.y << ">";
    return out;
}

Vector2D operator*(const Vector2D v1, const double d)
{
    double newX=v1.x*d;
    double newY=v1.y*d;
    Vector2D newVec(newX,newY);
    return newVec;
}

Vector2D operator/(const Vector2D v1, const double d)
{
    if (d==0) {
        cout << "Attempt to Divide by Zero" << endl;
        return v1;
    }
    else{
        double newX=v1.x/d;
        double newY=v1.y/d;
        Vector2D newVec(newX,newY);
        return newVec;
    }
}