/* Including all Files neccessary */
#include "Assn2.h"
#include "ShapeTwoD.h"
#include "Square.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Cross.h"
using namespace std;

/* Function for the display menu */
void displaymenu()
{
    cout<<"Student ID   : 7364283"<<endl;
    cout<<"Student Name : Shaik Dawood Shameem Ahamed"<<endl;
    cout<<"-------------------------------------------"<<endl;
    cout<<"Welcome to Assn2 program!"<<endl;
    cout<<endl;
    cout<<"1)       Input sensor data"<<endl;
    cout<<"2)       Compute area (for all records)"<<endl;
    cout<<"3)       Print Shapes report"<<endl;
    cout<<"4)       Sort shape data"<<endl;
    cout<<endl;
}

int main()
{
    int currentpos =0;
    string shape;
    string spacialtype;
    ShapeTwoD *ShapeTwoDPtr[100];
    
    int count =0;
    int x;
    do
    {
        displaymenu();
        cout<<"Please enter your choice: ";
        cin>>x;
        cout<<endl;
        if(x==1)
        {
            cout<<"Please enter name of shape: ";
            cin>>shape;
            cout<<endl;
            cout<<"Please enter special type: ";
            cin>>spacialtype;
            cout<<endl;
            count++;

            /* Defining each shape when the user types in the shape */
            if(shape =="Square")
            {
                Square *s = new Square();
                ShapeTwoDPtr[currentpos] = s;
                ShapeTwoDPtr[currentpos]->setName("Square");
                if (spacialtype == "WS")
                {
                    ShapeTwoDPtr[currentpos]->setContainsWarpSpace(true); 
                }
                else
                {
                    ShapeTwoDPtr[currentpos]->setContainsWarpSpace(false); 
                }
                ShapeTwoDPtr[currentpos]->addCoords();
            }
            else if(shape == "Circle")
            {
                Circle *c = new Circle();
                ShapeTwoDPtr[currentpos] = c;
                ShapeTwoDPtr[currentpos]->setName("Circle");
                if (spacialtype == "WS")
                {
                    ShapeTwoDPtr[currentpos]->setContainsWarpSpace(true); 
                }
                else
                {
                    ShapeTwoDPtr[currentpos]->setContainsWarpSpace(false); 
                }
                ShapeTwoDPtr[currentpos]->addCoords();
                
            }
            else if(shape == "Rectangle")
            {
                Rectangle *r = new Rectangle();
                ShapeTwoDPtr[currentpos] = r;
                ShapeTwoDPtr[currentpos]->setName("Rectangle");
                if (spacialtype == "WS")
                {
                    ShapeTwoDPtr[currentpos]->setContainsWarpSpace(true); 
                }
                else
                {
                    ShapeTwoDPtr[currentpos]->setContainsWarpSpace(false); 
                }
                ShapeTwoDPtr[currentpos]->addCoords();
                
            }
            else if(shape == "Cross")
            {
                Cross *cr = new Cross();
                ShapeTwoDPtr[currentpos] = cr;
                ShapeTwoDPtr[currentpos]->setName("Cross");
                if (spacialtype == "WS")
                {
                    ShapeTwoDPtr[currentpos]->setContainsWarpSpace(true); 
                }
                else
                {
                    ShapeTwoDPtr[currentpos]->setContainsWarpSpace(false); 
                }
                ShapeTwoDPtr[currentpos]->addCoords();
                
            }
            cout<<endl;
            cout<<"Record successfully stored. Going back to main menu ..."<<endl;
            cout<<endl;
            currentpos++;
        }
        else if(x==2)
        {
            /* Computing area for all shapes */
            for(int i=0;i<count;i++)
            {
                ShapeTwoDPtr[i]->computeArea();
            }
            cout<<"Computation Completed! ( "<<count<<" records were updated)"<<endl;
        }
        else if(x==3)
        {
            cout<<endl;
            cout<<"Total no. of records available = "<<count<<endl;
            cout<<endl;
            /* Printing all shapes */
            for(int i=0;i<count;i++)
            {
                cout<<"Shape["<<i<<"]"<<endl;
                cout<<ShapeTwoDPtr[i]->toString()<<endl;
            }
        }
        else if(x==4)
        {
            string alphab;
            do
            {
                cout<<endl;
                cout<<"a)       Sort by area (ascending)"<<endl;
                cout<<"b)       Sort by area (descending)"<<endl;
                cout<<"c)       Sort by special type and area"<<endl;
                cout<<endl;
                cout<<"Please select sort option ('q' to go main menu): ";
                cin>>alphab;
                cin.ignore();
                cout<<endl;
                if(alphab == "a")
                {
                    cout<<endl;
                    cout<<"Sort by area (smallest to largest) ..."<<endl;
                    cout<<endl;
                    for(int i=0;i<count;i++)
                    {
                        for (int j=i;j<count;j++)
                        {
                            /* Comparing the areas of the shape and swapping them */
                            if((ShapeTwoDPtr[i]->computeArea())>(ShapeTwoDPtr[j]->computeArea()))
                            {
                                std::swap(ShapeTwoDPtr[i],ShapeTwoDPtr[j]);
                            }
                        }
                    }
                    for(int i=0;i<count;i++)
                    {
                        /* Printing out the shapes */
                        cout<<"Shape["<<i<<"]"<<endl;
                        cout<<ShapeTwoDPtr[i]->toString()<<endl;
                        cout<<endl;
                    }
                }
                else if(alphab == "b")
                {
                    cout<<endl;
                    cout<<"Sort by area (largest to smallest) ..."<<endl;
                    cout<<endl;
                    for(int i=0;i<count;i++)
                    {
                        for (int j=i;j<count;j++)
                        {
                            /* Swapping the shapes and arranging according to the area */
                            if((ShapeTwoDPtr[i]->computeArea())<(ShapeTwoDPtr[j]->computeArea()))
                            {
                                std::swap(ShapeTwoDPtr[i],ShapeTwoDPtr[j]);
                            }
                        }
                    }
                    for(int i=0;i<count;i++)
                    {
                        cout<<"Shape["<<i<<"]"<<endl;
                        cout<<ShapeTwoDPtr[i]->toString()<<endl;
                        cout<<endl;
                    }
                }
                else if(alphab == "c")
                {
                    cout<<endl;
                    cout<<"Sort by area and special type (largest to smallest) ..."<<endl;
                    cout<<endl;
                    int copyc = count-1;
            
                    for(int i=0;i<count;i++)
                    {
                        for (int j=i;j<count;j++)
                        {
                            /* Swapping and arranging based on area */
                            if((ShapeTwoDPtr[i]->computeArea())<(ShapeTwoDPtr[j]->computeArea()))
                            {
                                std::swap(ShapeTwoDPtr[i],ShapeTwoDPtr[j]);
                            }
                        }
                    }
                    /* Printing out those with Warp Space and then Normal Space afterwards */
                    for(int i=0;i<count;i++)
                    {
                        if(ShapeTwoDPtr[i]->getContainsWarpSpace() == true)
                        {
                            cout<<"Shape["<<copyc<<"]"<<endl;
                            cout<<ShapeTwoDPtr[i]->toString()<<endl;
                            cout<<endl;
                            copyc--;
                        }
                    }
                    for(int i=0;i<count;i++)
                    {
                        if(ShapeTwoDPtr[i]->getContainsWarpSpace() == false)
                        {
                            cout<<"Shape["<<copyc<<"]"<<endl;
                            cout<<ShapeTwoDPtr[i]->toString()<<endl;
                            cout<<endl;
                            copyc--;
                        }
                    }
                }
            } while (alphab != "q");
        }
    } while (x<5);
    /* Deleting the array when program is over to prevent memory leak */
   delete [] ShapeTwoDPtr[100];
}