/* Including all Files neccessary */
#include "Assn2.h"
#include "ShapeTwoD.h"
#include "Circle.h"
using namespace std;

/* Defining empty struct array and radius for Coords for empty constructor*/
Circle::Circle()
{
    struct Coords * node = nullptr;
    int radius = 0;
}

Circle::Circle(string name, bool containsWarpSpace, struct Coords*node, int radius)
:ShapeTwoD(name, containsWarpSpace)
{
    Circle::node = node;
    Circle::radius = radius;
}

/* Method to get radius */
int Circle::getRadius(int radius)
{
    return (radius);
}

/* Method to set radius */
void Circle::setRadius(int radius)
{
    Circle::radius = radius;
}

/* Method to add Coords to Cross */
void Circle::addCoords()
{   
    node = new struct Coords [1];
    for (int i=0;i<1;i++)
    {
        struct Coords temp;
        
        cout<<"Please enter x-ordinate of center :";
        cin>>temp.x;
        cin.ignore();

        cout<<"Please enter y-ordinate of center :";
        cin>>temp.y;
        cin.ignore();

        node [i] = temp;
    }
    cout<<"Please enter radius (units) :";
    cin>>radius;
    cin.ignore();

    cout<<endl;
}

/* To Compute Area using the radius */
double Circle::computeArea()
{
    double pi = 3.14;
    double area = (3.14)*(radius)*(radius);
    return area;
}

bool Circle::isPointInShape(int x, int y)
{
    double radx = node[0].x;
    double rady = node[0].y;

    /* To check if the point is in the circle */
    double dist = sqrt(pow((x-radx),2) + pow((y-rady),2));

    if (dist<radius)
    {
        if(x == radx && y == rady)
        {
            return false;
        }
        else 
        {
            return true;
        }
    }
    else
    {
        return false;
    }

} 

bool Circle::isPointOnShape(int x, int y)
{
    double radx = node[0].x;
    double rady = node[0].y;

    double dist = sqrt(pow((x-radx),2) + pow((y-rady),2));

    /* To check if the point is on the circle */
    if (dist==(radius))
    {
        return true;
    }
    else
    {
        return false;
    }
}

string Circle::toString()
{
    int largestx = node[0].x + radius;
    int largesty = node[0].y + radius;
    int countperi=0;
    int countin =0;

    ostringstream oss;
    oss<<"Name: Circle"<<endl;
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
    for(int i=0;i<1;i++)
    {
        oss<<"Point["<<i<<"] : ("<<node[i].x<<", "<<node[i].y<<")"<<endl;
    }
    oss<<endl;
    oss<<"Points on perimeter : ";
    for(int i=0;i<largestx+1;i++)
    {
        for(int j=0;j<largesty+1;j++)
        {
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
    }
    
    if(countperi ==0)
    {
        oss<<"none!, ";
    }

    /* To remove the last commas */
    oss.seekp(-2,std::ios_base::end);
    oss<<"\0";
    oss<<endl;
    oss<<endl;
    oss<<"Points within shape : ";
    for(int i=0;i<largestx;i++)
    {
        for(int j=0;j<largesty;j++)
        {
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