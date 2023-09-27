/* Including all Files neccessary */
#include "Assn2.h"
#include "ShapeTwoD.h"
#include "Cross.h"
using namespace std;

/* Defining empty struct array for Coords for empty constructor*/
Cross::Cross()
{
    struct Coords * node = nullptr;
}

Cross::Cross(string name, bool containsWarpSpace, struct Coords*node)
:ShapeTwoD(name, containsWarpSpace)
{
    Cross::node = node;
}

/* Method to add Coords to Cross */
void Cross::addCoords()
{   
    node = new struct Coords [12];
    int a = 1;
    for (int i=0;i<12;i++)
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
double Cross::computeArea()
{
    /* Formula to get area of any polygon */
    double area = 0.0;
    int ox = node[0].x;
    int oy = node[0].y;

    for (int i =1;i<12;i++)
    {
        area += ((node[i].x * oy) - (node[i].y) * ox);
        ox = node[i].x;
        oy = node[i].y;
    }
    area += ((node[0].x * oy) - (node[0].y) * ox);
    area = area/2.0;

    if(area <0)
    {
        area = area * (-1);
    }

    return area ;
}

bool Cross::isPointInShape(int x, int y)
{
    int secondx = x+100;
    int secondy = y+100;

    int intersecting = 0;
    int yintersecting =0;

    for (int i = 0;i<12;i++)
    {
        if(i<=10)
        {
            /* Checking if the point lies using a line to x infinity */
            if ((((node[i].x-x)*(y-y) - (node[i].y-y)*(secondx-x)) 
                * ((node[i+1].x-x)*(y-y) - (node[i+1].y-y)*(secondx-x)) < 0) 
                && 
            (((x-node[i].x)*(node[i+1].y-node[i].y) - (y-node[i].y)*(node[i+1].x-node[i].x)) 
                * ((secondx-node[i].x)*(node[i+1].y-node[i].y) - (y-node[i].y)*(node[i+1].x-node[i].x)) < 0))
                {
                    intersecting += 1;
                }
            /* Checking if the point lies using a line to y infinity */
            if ((((node[i].x-x)*(secondy-y) - (node[i].y-y)*(x-x)) 
                * ((node[i+1].x-x)*(secondy-y) - (node[i+1].y-y)*(x-x)) < 0) 
                && 
            (((x-node[i].x)*(node[i+1].y-node[i].y) - (y-node[i].y)*(node[i+1].x-node[i].x)) 
                * ((x-node[i].x)*(node[i+1].y-node[i].y) - (secondy-node[i].y)*(node[i+1].x-node[i].x)) < 0))
                {
                    yintersecting += 1;
                }
        }
        if(i == 11)
        {
            /* Checking if the point lies using a line to x infinity */
            if ((((node[i].x-x)*(y-y) - (node[i].y-y)*(secondx-x)) 
                * ((node[0].x-x)*(y-y) - (node[0].y-y)*(secondx-x)) < 0) 
                && 
            (((x-node[i].x)*(node[0].y-node[i].y) - (y-node[i].y)*(node[0].x-node[i].x)) 
                * ((secondx-node[i].x)*(node[0].y-node[i].y) - (y-node[i].y)*(node[0].x-node[i].x)) < 0))
                {
                    intersecting += 1;
                }
            /* Checking if the point lies using a line to y infinity */
            if ((((node[i].x-x)*(secondy-y) - (node[i].y-y)*(x-x)) 
                * ((node[0].x-x)*(secondy-y) - (node[0].y-y)*(x-x)) < 0) 
                && 
            (((x-node[i].x)*(node[0].y-node[i].y) - (y-node[i].y)*(node[i+1].x-node[i].x)) 
                * ((x-node[i].x)*(node[0].y-node[i].y) - (secondy-node[i].y)*(node[0].x-node[i].x)) < 0))
                {
                    yintersecting += 1;
                }
        }
    }
    /* If intersecting point gives a reminader of 1 return true */
    if((yintersecting%2 == 1 || intersecting%2 == 1) && isPointOnShape(x,y) == false)
    {
        return true;
    }
    else
    {
        return false;
    }
    
} 

bool Cross::isPointOnShape(int x, int y)
{

    /* Checking if the coordinates that lie on the x coordinate lie on the edge */
    for (int i = 0;i<12;i++)
    {
        if(i<=10)
        {
            if (node[i].x == node[i+1].x)
            {
                if(node[i].x == x && ((y>node[i].y && y<node[i+1].y) || (y>node[i+1].y && y<node[i].y)))
                {
                    return true;
                }
            }
            /* Checking if the coordinates that lie on the y coordinate lie on the edge */
            if (node[i].y == node[i+1].y)
            {
                if(node[i].y == y && ((x>node[i].x && x<node[i+1].x) || (x>node[i+1].x && x<node[i].x)))
                {
                    return true;
                }
            }
        }
        if(i==11)
        {
            if (node[i].x == node[0].x)
            {
                if(node[i].x == x && ((y>node[i].y && y<node[0].y) || (y>node[0].y && y<node[i].y)))
                {
                    return true;
                }
            }
            /* Checking if the coordinates that lie on the y coordinate lie on the edge */
            if (node[i].y == node[0].y)
            {
                if(node[i].y == y && ((x>node[i].x && x<node[0].x) || (x>node[0].x && x<node[i].x)))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

string Cross::toString()
{
    vector<int>xcoord;
    int countperi=0;
    int countin =0;
    for(int i = 0;i<12;i++)
    {
        xcoord.push_back(node[i].x);
    }

    vector<int>ycoord;
    for(int i = 0;i<12;i++)
    {
        ycoord.push_back(node[i].x);
    }

    sort(xcoord.begin(),xcoord.end());
    xcoord.erase(unique(xcoord.begin(), xcoord.end()), xcoord.end());

    sort(ycoord.begin(),ycoord.end());
    ycoord.erase(unique(ycoord.begin(), ycoord.end()), ycoord.end());

    int largestx = xcoord[3];
    int largesty = ycoord[3];

    ostringstream oss;
    oss<<"Name: Cross"<<endl;
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
    for(int i=0;i<12;i++)
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

    if(countperi ==0)
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
    return(oss.str());
}