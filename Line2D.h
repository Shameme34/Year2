#ifndef LINE2D
#define LINE2D

#include "shameem.h"
#include "Point2D.h"

using namespace std;

class Line2D
{
    /* Overloading of insertion operator to give the desired output */
    friend ostream& operator<<(ostream& os, Line2D &l2d);
    friend bool operator== (Line2D &l2d4,Line2D &l2d);
    friend double operator- (Line2D &l2d4,Line2D &l2d);
    private:
        Point2D pt1;
        Point2D pt2;
    protected:
        double length;
        virtual void setLength();
    public:
        Line2D();
        Line2D(Point2D pt1, Point2D pt2);
        Point2D getPt1();
        Point2D getPt2();
        double getScalarValue();
        void setPt1(Point2D pt1);
        void setPt2(Point2D pt2);
        virtual string toString();
        /* Destructor to destroy pointers */
        ~Line2D(){};
};
#endif