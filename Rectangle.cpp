/* Including all Files neccessary */
#include "Assn2.h"
#include "ShapeTwoD.h"
#include "Rectangle.h"
using namespace std;

/* Defining empty struct array for Coords for empty constructor*/
Rectangle::Rectangle()
{
    struct Coords * node = nullptr;
}

Rectangle::Rectangle(string name, bool containsWarpSpace, struct Coords*node)
:ShapeTwoD(name, containsWarpSpace)
{
    Rectangle::node = node;
}

/* Method to add Coords to Rectangle */
void Rectangle::addCoords()
{   
    node = new struct Coords [4];
    int a = 1;
    for (int i=0;i<4;i++)
    {
        struct Coords temp;
        
        cout<<"Please enter x-ordinate of pt." <<a<<": ";
        cin>>temp.x;
        cin.ignore();

        cout<<"Please enter y-ordinate of pt." <<a<<": ";
        cin>>temp.y;
        cin.ignore();

        node [i] = temp;
        a++;
    }
}

/* To Compute Area using the Coords */
double Rectangle::computeArea()
{
    /* Getting the respective x and y coordinates and giving their own variables */
    double largestx = 0;
    double smallestx = node[0].x;
    double largesty = 0;
    double smallesty = node[0].y;

    /* To get the largest and smallest x and y values */
    for(int i=0;i<4;i++)
    {
       if(largestx<node[i].x)
       {
        largestx = node[i].x;
       }

       if(smallestx>node[i].x)
       {
        smallestx = node[i].x;
       }

       if(largesty<node[i].y)
       {
        largesty = node[i].y;
       }

       if(smallesty>node[i].y)
       {
        smallesty = node[i].y;
       }
    }
    
    /* Area of the rectangle */
    double area = (largestx - smallestx)*(largesty - smallesty);
    return area ;
}

bool Rectangle::isPointInShape(int x, int y)
{
    double largestx = 0;
    double smallestx = node[0].x;
    double largesty = 0;
    double smallesty = node[0].y;

    for(int i=0;i<4;i++)
    {
       if(largestx<node[i].x)
       {
        largestx = node[i].x;
       }

       if(smallestx>node[i].x)
       {
        smallestx = node[i].x;
       }

       if(largesty<node[i].y)
       {
        largesty = node[i].y;
       }

       if(smallesty>node[i].y)
       {
        smallesty = node[i].y;
       }
    }

    /* To check if the coords are in the boundaries of the rectangle */
    if ( x>smallestx && x<largestx && y>smallesty && y<largesty)
    {
        return true;
    }
    else
    {
        return false;
    }

} 

bool Rectangle::isPointOnShape(int x, int y)
{
    double largestx = 0;
    double smallestx = node[0].x;
    double largesty = 0;
    double smallesty = node[0].y;

    for(int i=0;i<4;i++)
    {
       if(largestx<node[i].x)
       {
        largestx = node[i].x;
       }

       if(smallestx>node[i].x)
       {
        smallestx = node[i].x;
       }

       if(largesty<node[i].y)
       {
        largesty = node[i].y;
       }

       if(smallesty>node[i].y)
       {
        smallesty = node[i].y;
       }
    }

    /* To check if the coords on the edges of the rectangle */
    if (((x==smallestx || x == largestx) && (y>=smallesty && y<=largesty))|| 
        ((y==smallesty || y == largesty) && (x>=smallestx && x<=largestx)))
    {
        if((x == largestx&&y==largesty) || (x == largestx&&y==smallesty)||
            (x == smallestx&&y==largesty) || (x == smallestx&&y==smallesty) )
            return false;
        else
            return true;
    }
    else
    {
        return false;
    }
}

string Rectangle::toString()
{
    /* To get the largest values to check if all the coords less than the largest are in the shape */
    int largestx =0;
    int largesty =0;
    int countperi =0;
    int countin =0;
    for(int i=0;i<4;i++)
    {
       if(largestx<node[i].x)
       {
        largestx = node[i].x;
       }

       if(largesty<node[i].y)
       {
        largesty = node[i].y;
       }
    }

    ostringstream oss;
    oss<<"Name: Rectangle"<<endl;
    if(containsWarpSpace == true)
    {
        oss<<"Special Type: WS";
    }
    else
    {
        oss<<"Special Type: NS";
    }
    oss<<endl;
    oss<<"Area: "<<computeArea()<<" units square"<<endl;
    oss<<"Vertices :"<<endl;
    for(int i=0;i<4;i++)
    {
        oss<<"Point["<<i<<"] : ("<<node[i].x<<", "<<node[i].y<<")"<<endl;
    }
    oss<<endl;
    oss<<"Points on perimeter : ";
    for(int i=0;i<largestx+1;i++)
    {
        for(int j=0;j<largesty+1;j++)
        if(isPointOnShape(i,j) == true )
        {
            oss<<"("<<i<<", "<<j<<"), ";
            countperi++;
        }
        else
        {
            oss<<"";
        }
    }

    if(countperi==0)
    {
        oss<<"none!, ";
    }

    /* Removing the last commas in the oss string */
    oss.seekp(-2,std::ios_base::end);
    oss<<"\0";
    oss<<endl;
    oss<<endl;
    oss<<"Points within shape : ";
    for(int i=0;i<largestx;i++)
    {
        for(int j=0;j<largesty;j++)
        if(isPointInShape(i,j) == true )
        {
            oss<<"("<<i<<", "<<j<<"), ";
            countin++;
        }
        else
        {
            oss<<"";
        }
    }

    if(countin ==0)
    {
        oss<<"none!, ";
    }

    oss.seekp(-2,std::ios_base::end);
    oss<<"\0";
    oss<<endl;
    oss<<endl;
    return(oss.str());
}
