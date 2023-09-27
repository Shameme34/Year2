#ifndef LINE3D
#define LINE3D

#include "shameem.h"
#include "Point2D.h"
#include "Point3D.h"
#include "Line2D.h"

using namespace std;

class Line3D:public Line2D
{
    /* Overloading of insertion operator to give the desired output */
    friend ostream& operator<<(ostream& os, Line3D &l3d);
    friend bool operator== (Line3D &l3d4,Line3D &l3d);
    friend double operator- (Line3D &l3d4,Line3D &l3d);
    private:
        Point3D pt1;
        Point3D pt2;
    protected:
        void setLength() override;
    public:
        Line3D();
        Line3D(Point3D pt1, Point3D pt2);
        Point3D getPt1();
        Point3D getPt2();
        void setPt1(Point3D pt1);
        void setPt2(Point3D pt2);
        string toString() override;
        ~Line3D(){};
};
#endif