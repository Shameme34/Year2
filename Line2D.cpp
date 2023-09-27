#include "shameem.h"
#include "Point2D.h"
#include "Line2D.h"
#include "MyTemplates.h"

Line2D::Line2D()
{
    /* Default constructor */
}

Line2D::Line2D(Point2D pt1, Point2D pt2)
{
    this->pt1 = pt1;
    this->pt2 = pt2;
    this->length = length;
}

void Line2D::setLength()
{
    double value;
    value = sqrt(pow((pt1.getX() - pt2.getX()),2) + pow((pt1.getY() - pt2.getY()),2));
    this->length = value;
}

double Line2D::getScalarValue()
{
    setLength();
    return(length);
}

Point2D Line2D::getPt1()
{
    return (pt1);
}

Point2D Line2D::getPt2()
{
    return (pt2);
}

void Line2D::setPt1(Point2D pt1)
{
    Line2D::pt1 = pt1;
}

void Line2D::setPt2(Point2D pt2)
{
    Line2D::pt2 = pt2;
}

string Line2D::toString()
{
    ostringstream os;

    os<<"["<<right<<setw(4)<<getPt1().getX()<<", ";
    os<<right<<setw(4)<<getPt1().getY()<<"]   ";
    os<<"["<<right<<setw(4)<<getPt2().getX()<<", ";
    os<<right<<setw(4)<<getPt2().getY()<<"]   ";
    os<<fixed<<setprecision(4)<<getScalarValue()<<endl;

    return (os.str());
}

ostream& operator<<(ostream& os, Line2D &l2d)
{
    os<<"( ["<<l2d.getPt1().getX()<<", "<<l2d.getPt1().getY()<<"], distFrOrigin : ";
    os<<l2d.getPt1().getScalarValue()<<" to ["<<l2d.getPt2().getX()<<", ";
    os<<l2d.getPt2().getY()<<"], distFrOrigin : "<<l2d.getPt2().getScalarValue()<<" ), length : ";
    os<<fixed<<setprecision(3)<<l2d.getScalarValue()<<endl;

    return os;
}

double operator- (Line2D &l2d4,Line2D &l2d)
{
    return (l2d4.getScalarValue() - l2d.getScalarValue());
}

bool operator== (Line2D &l2d4,Line2D &l2d)
{
    if((equals(l2d4.getPt1(), l2d.getPt1()) == true) &&
        (equals(l2d4.getPt2(), l2d.getPt2()) == true))
    {
        return true;
    }
    else 
    {
        return false;
    }
}