#include "shameem.h"
#include "Point2D.h"

Point2D::Point2D()
{
    x = 0;
    y = 0;
    distFrOrigin = 0;
}

Point2D::Point2D(int x, int y)
{
    Point2D::x = x;
    Point2D::y = y;
    Point2D::distFrOrigin = distFrOrigin;
}

int Point2D::getX()
{
    return (x);
}

int Point2D::getY()
{
    return (y);
}

double Point2D::getScalarValue()
{
    setDistFrOrigin();
    return (distFrOrigin);
}

void Point2D::setX(int x)
{
    this->x = x;
}

void Point2D::setY(int y)
{
    this->y = y;
}

void Point2D::setDistFrOrigin()
{
    double value = sqrt(pow(x,2) + pow(y,2));
    this->distFrOrigin = value;
}

/* Overloading the '-' operator for the template function */
double operator- (Point2D &p2d4,Point2D &p2d)
{
    return (p2d.getScalarValue() - p2d4.getScalarValue());
}

/* Overloading the '==' operator for the template function */
bool operator== (Point2D &p2d4,Point2D &p2d)
{
    if((p2d.getX() == p2d4.getX())&&(p2d.getY() == p2d4.getY()))
    {
        return true;
    }
    else
    {
        return false;
    }
}

string Point2D::toString()
{
    ostringstream oss;
    oss<<"["<<right<<setw(4)<<getX()<<", ";
    oss<<right<<setw(4)<<getY()<<"]   ";
    oss<<fixed<<setprecision(3)<<getScalarValue()<<endl;

    return (oss.str());
}

ostream& operator<<(ostream& os, Point2D &p2d)
{
    os<<"["<<p2d.getX()<<", ";
    os<<p2d.getY()<<"],  distFrOrigin : ";
    os<<fixed<<setprecision(4)<<p2d.getScalarValue()<<endl;

    return os;
}