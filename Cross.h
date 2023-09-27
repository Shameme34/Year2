#ifndef CROSS_H
#define CROSS_H

#include "Assn2.h"
#include "ShapeTwoD.h"
using namespace std;

class Cross:public ShapeTwoD
{
    private:
        struct Coords 
        {
            int x;
            int y;
        };
        Coords *node;
    public:
        Cross();
        Cross (string name, bool containsWarpSpace, struct Coords * node);

        void addCoords() override;
        double computeArea() override;
        bool isPointInShape(int x, int y) override;
        bool isPointOnShape(int x, int y) override;
        string toString() override;
        ~Cross()
        {
            delete []node;
        }
};

#endif