#ifndef SHAPETWOD_H
#define SHAPETWOD_H

#include "Assn2.h"
using namespace std;

class ShapeTwoD
{
    protected:
        string name;
        bool containsWarpSpace;
    public:
        ShapeTwoD();
        ShapeTwoD(string name, bool containsWarpSpace);

        string getName();
        bool getContainsWarpSpace ();
        virtual string toString();

        virtual void addCoords();
        virtual double computeArea();
        virtual bool isPointInShape(int x, int y);
        virtual bool isPointOnShape(int x, int y);

        void setName(string name);
        void setContainsWarpSpace (bool containsWarpSpace);
};

#endif