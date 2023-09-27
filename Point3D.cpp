#include "shameem.h"
#include "Point2D.h"
#include "Point3D.h"

using namespace std;

Point3D::Point3D()
{
    z = 0;
}

Point3D::Point3D(int x, int y, int z)
:Point2D(x, y)
{
    Point3D::z = z;
}

int Point3D::getZ()
{
    return (z);
} 

void Point3D::setZ(int z)
{
    this->z = z;
}

void Point3D::setDistFrOrigin()
{
    double value = sqrt(pow(x,2) + pow(y,2) + pow(z,2));
    this->distFrOrigin = value;
}

ostream& operator<<(ostream& os, Point3D &p3d)
{
    os<<"["<<p3d.getX()<<", ";
    os<<p3d.getY()<<", "<<p3d.getZ()<<"],  distFrOrigin : ";
    os<<fixed<<setprecision(4)<<p3d.getScalarValue()<<endl;

    return os;
}

string Point3D::toString()
{
    ostringstream oss;

    oss<<"["<<right<<setw(4)<<getX()<<", ";
    oss<<right<<setw(4)<<getY()<<", ";
    oss<<right<<setw(4)<<getZ()<<"]   ";
    oss<<fixed<<setprecision(3)<<getScalarValue()<<endl;

    return (oss.str());
}

/* Overloading the '-' operator */
double operator- (Point3D &p3d4,Point3D &p3d)
{
    return (p3d.getScalarValue() - p3d4.getScalarValue());
}

/* Overloading the '==' operator */
bool operator== (Point3D &p3d4,Point3D &p3d)
{
    if((p3d.getX() == p3d4.getX())&&(p3d.getY() == p3d4.getY())&&(p3d.getZ() == p3d4.getZ()))
    {
        return true;
    }
    else
    {
        return false;
    }
}