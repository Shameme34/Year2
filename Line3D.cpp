#include "shameem.h"
#include "Point2D.h"
#include "Point3D.h"
#include "Line2D.h"
#include "Line3D.h"
#include "MyTemplates.h"

Line3D::Line3D()
{
    /* Default constructor */
}

Line3D::Line3D(Point3D pt1, Point3D pt2)
:Line2D()
{
    this->pt1 = pt1;
    this->pt2 = pt2;
}

Point3D Line3D::getPt1()
{
    return (pt1);
}

Point3D Line3D::getPt2()
{
    return (pt2);
}

void Line3D::setPt1(Point3D pt1)
{
    Line3D::pt1 = pt1;
}

void Line3D::setPt2(Point3D pt2)
{
    Line3D::pt2 = pt2;
}

void Line3D::setLength()
{
    double value;
    value = sqrt(pow((pt1.getX() - pt2.getX()),2) + pow((pt1.getY() - pt2.getY()),2) + pow((pt1.getZ() - pt2.getZ()),2));
    this->length = value;
}

string Line3D::toString()
{
    ostringstream os;
    os<<"["<<right<<setw(4)<<getPt1().getX()<<", ";
    os<<right<<setw(4)<<getPt1().getY()<<", ";
    os<<right<<setw(4)<<getPt1().getZ()<<"]   ";
    os<<"["<<right<<setw(4)<<getPt2().getX()<<", ";
    os<<right<<setw(4)<<getPt2().getZ()<<", ";
    os<<right<<setw(4)<<getPt2().getZ()<<"]   ";
    os<<fixed<<setprecision(4)<<getScalarValue()<<endl;

    return (os.str());
}

ostream& operator<<(ostream& os, Line3D &l3d)
{
    os<<"( ["<<l3d.getPt1().getX()<<", "<<l3d.getPt1().getY()<<", "<<l3d.getPt1().getZ()<<"], distFrOrigin : ";
    os<<l3d.getPt1().getScalarValue()<<" to ["<<l3d.getPt2().getX()<<", ";
    os<<l3d.getPt2().getY()<<", "<<l3d.getPt2().getZ()<<"], distFrOrigin : "<<l3d.getPt2().getScalarValue()<<" ), length : ";
    os<<fixed<<setprecision(3)<<l3d.getScalarValue()<<endl;

    return os;
}

bool operator== (Line3D &l3d4,Line3D &l3d)
{
    if((equals(l3d4.getPt1(), l3d.getPt1()) == true) &&
        (equals(l3d4.getPt2(), l3d.getPt2()) == true))
    {
        return true;
    }
    else 
    {
        return false;
    }
}

double operator- (Line3D &l3d4,Line3D &l3d)
{
    return (l3d.getScalarValue() - l3d4.getScalarValue());
}