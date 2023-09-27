#ifndef POINT3D
#define POINT3D

#include "shameem.h"
#include "Point2D.h"

using namespace std;

class Point3D:public Point2D
{
    /* Overloading of insertion operator to give the desired output */
    friend double operator- (Point3D &p3d4,Point3D &p3d);
    friend ostream& operator<<(ostream& os, Point3D &p2d);
    friend bool operator== (Point3D &p2d4,Point3D &p2d);
    protected:
        int z;
        void setDistFrOrigin() override;
    public:
        Point3D();
        Point3D(int x, int y, int z);
        int getZ();
        void setZ(int z);
        virtual string toString() override;
        ~Point3D(){};
};
#endif