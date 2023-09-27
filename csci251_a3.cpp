#include "shameem.h"
#include "Point2D.h"
#include "Point3D.h"
#include "Line2D.h"
#include "Line3D.h"
#include "MyTemplates.h"

using namespace std;

/* Declaration of functions */
void displaymenu(string filtcrit, string sortcrit, string sortord);
void displayflitcrit();
void displaysortcrit();
void displaysortcrit2();
void displaysortcrit3();
void displaysortord();
vector<string>splitString(string str, string delim);
void readAFile(string inputFilename, vector<string>&data);

/* Split String method */
vector<string>splitString(string str, string delim)
{
    vector<string> result;
    size_t pos = 0;
    string token;

    while((pos = str.find(delim)) != std::string::npos)
    {
        token = str.substr(0,pos);
        result.push_back(token);
        str.erase(0, pos+delim.length());
    }

    if (!str.empty())
    {
        result.push_back(str);
    }
    return(result);
}

/* Display the main menu */
void displaymenu(string filtcrit, string sortcrit, string sortord)
{
    cout<<"Student ID   : 7364283"<<endl;
    cout<<"Student Name : Shaik Dawood Shameem Ahamed"<<endl;
    cout<<"-------------------------------------------"<<endl;
    cout<<"Welcome to Assn3 program!"<<endl;
    cout<<endl;
    cout<<"1)    Read in data"<<endl;
    cout<<"2)    Specify filtering criteria (current: "<<filtcrit<<")"<<endl;
    cout<<"3)    Specify sorting criteria (current: "<<sortcrit<<")"<<endl;
    cout<<"4)    Specify sorting order (current: "<<sortord<<")"<<endl;
    cout<<"5)    View data"<<endl;
    cout<<"6)    Store data"<<endl;
    cout<<"7)    Quit the program"<<endl;
    cout<<endl;
}

/* All the other display options below */
void displayflitcrit()
{
    cout<<"     a)      Point2D records"<<endl;
    cout<<"     b)      Point3D records"<<endl;
    cout<<"     c)      Line2D records"<<endl;
    cout<<"     d)      Line3D records"<<endl;
    cout<<endl;
}

void displaysortcrit()
{
    cout<<"     a)      X ordinate value"<<endl;
    cout<<"     b)      Y ordinate value"<<endl;
    cout<<"     c)      Dist. Fr Origin value"<<endl;
    cout<<endl;
}

void displaysortcrit2()
{
    cout<<"     a)      X ordinate value"<<endl;
    cout<<"     b)      Y ordinate value"<<endl;
    cout<<"     c)      Z ordinate value"<<endl;
    cout<<"     d)      Dist. Fr Origin value"<<endl;
    cout<<endl;
}

void displaysortcrit3()
{
    cout<<"     a)      Pt. 1's (x, y) values"<<endl;
    cout<<"     b)      Pt. 2's (x, y) values"<<endl;
    cout<<"     c)      Length value"<<endl;
    cout<<endl;
}

void displaysortord()
{
    cout<<"     a)      ASC(Ascending order)"<<endl;
    cout<<"     b)      DSC(Descending order)"<<endl;
}

/* File reading function */
void readAFile(string inputFilename, vector<string>&data)
{
    ifstream inputFile;
    inputFile.open(inputFilename.c_str());
    string aLine;
    set<string>s;

    while(inputFile.good())
    {
        string aLine;
        getline(inputFile, aLine);
        data.push_back(aLine);
    }

    /* Removing duplicates in the data */
    unsigned size = data.size();
    for(unsigned i =0;i<size;++i) s.insert(data[i]);
    data.assign(s.begin(),s.end());
}

int main()
{
    /* Declaring variables */
    string filtcrit = "Point2D";
    string sortcrit = "x-ordinate";
    string sortord  = "ASC";
    int p2dnum = 0;
    int p3dnum = 0;
    int p2d2num =0;
    int p3d2num =0;
    int l2dnum =0;
    int l3dnum =0;

    /* Vectors to hold pointers to classes */
    vector<Point2D*>p2d;
    vector<Point3D*>p3d;
    vector<Point2D*>p2d2;
    vector<Point3D*>p3d2;
    vector<Line2D*>l2d;
    vector<Line3D*>l3d;
    vector<string>readdata;
    int userC;
    
    do
    {
        cout<<endl;
        displaymenu(filtcrit,sortcrit,sortord);
        cout<<"Please enter your choice: ";
        cin>>userC;
        cout<<endl;
        /* File name */
        string inputFilename;
        /* Vector of string to hold data from txt file */
        vector<string>alldata;
        if(userC == 1)
        {
            cout<<"Please enter filename: ";
            cin>>inputFilename;
            cout<<endl;
            /* Reading the file and inserting data in the vector */
            readAFile(inputFilename, alldata);
            cout<<alldata.size() - 1<<" records read in successfully!"<<endl;
            cout<<endl;
            cout<<"Going back to main menu ..."<<endl;
            cout<<endl;
            for(int i=0;i<alldata.size();i++)
            {
                /* Using the delimiters to seperate the values in the data file */
                string newd = alldata[i];
                /* Seperating the delimiters from the data  */
                vector<string>newdata = splitString(newd, ", ");
                for(int j=0;j<newdata.size();j++)
                {
                    /* Placing the seperated data into a new vector */
                    readdata.push_back(newdata[j]);
                }
            }
            for(int i=0;i<readdata.size();i++)
            {
                /* Removing all brackets */
                if(!readdata[i].find("["))
                {
                    readdata[i].erase(readdata[i].begin());
                }
                if(readdata[i].find("]") !=std::string::npos)
                {
                    readdata[i].resize(readdata[i].size()-1);
                }
            }
            for(int i=0;i<readdata.size();i++)
            {
                /* Setting the corresponding coordinates and points to the corresponding classes */
                /* Placing them into vectors as well */
                if(readdata[i]=="Point2D")
                {
                    p2d.push_back(new Point2D());
                    int num = stoi(readdata[i+1]);
                    int num1 = stoi(readdata[i+2]);
                    p2d[p2dnum]->setX(num);
                    p2d[p2dnum]->setY(num1);
                    p2dnum += 1;
                }
                if(readdata[i] == "Point3D")
                {
                    p3d.push_back(new Point3D());
                    int num = stoi(readdata[i+1]);
                    int num1 = stoi(readdata[i+2]);
                    int num2 = stoi(readdata[i+3]);
                    p3d[p3dnum]->setX(num);
                    p3d[p3dnum]->setY(num1);
                    p3d[p3dnum]->setZ(num2);
                    p3dnum += 1;
                }
                if(readdata[i] == "Line2D")
                {
                    int num = stoi(readdata[i+1]);
                    int num1 = stoi(readdata[i+2]);
                    int num2 = stoi(readdata[i+3]);
                    int num3 = stoi(readdata[i+4]);
                    p2d2.push_back(new Point2D());
                    p2d2[p2d2num]->setX(num);
                    p2d2[p2d2num]->setY(num1);
                    l2d.push_back(new Line2D());
                    /* Dereferencing the pointers in the classes to set the points for the line */
                    l2d[l2dnum]->setPt1(*p2d2[p2d2num]);
                    p2d2num += 1;
                    p2d2.push_back(new Point2D());
                    p2d2[p2d2num]->setX(num2);
                    p2d2[p2d2num]->setY(num3);
                    l2d[l2dnum]->setPt2(*p2d2[p2d2num]);
                    p2d2num += 1;
                    l2dnum +=1;
                }
                if(readdata[i] == "Line3D")
                {
                    int num = stoi(readdata[i+1]);
                    int num1 = stoi(readdata[i+2]);
                    int num2 = stoi(readdata[i+3]);
                    int num3 = stoi(readdata[i+4]);
                    int num4 = stoi(readdata[i+5]);
                    int num5 = stoi(readdata[i+6]);
                    p3d2.push_back(new Point3D());
                    p3d2[p3d2num]->setX(num);
                    p3d2[p3d2num]->setY(num1);
                    p3d2[p3d2num]->setZ(num2);
                    l3d.push_back(new Line3D());
                    /* Dereferencing the pointers in the classes to set the points for the line */
                    l3d[l3dnum]->setPt1(*p3d2[p3d2num]);
                    p3d2num += 1;
                    p3d2.push_back(new Point3D());
                    p3d2[p3d2num]->setX(num3);
                    p3d2[p3d2num]->setY(num4);
                    p3d2[p3d2num]->setZ(num5);
                    l3d[l3dnum]->setPt2(*p3d2[p3d2num]);
                    p3d2num += 1;
                    l3dnum +=1;
                }
            }
           
        }
        if(userC == 2)
        {
            /* Displaying the menus and returning them to default if they change the filtering criteria */
            string crit;
            cout<<"[Specifying filtering criteria (current: "<<filtcrit<<")]"<<endl;
            cout<<endl;
            displayflitcrit();
            cout<<"     Please enter your criteria (a-d): ";
            cin>>crit;
            if(crit == "a")
            {
                filtcrit = "Point2D";
                sortcrit = "x-ordinate";
            }
            else if (crit == "b")
            {
                filtcrit = "Point3D";
                sortcrit = "x-ordinate";
            }
            else if (crit == "c")
            {
                filtcrit = "Line2D";
                sortcrit = "Pt. 1";
            }
            else if (crit == "d")
            {
                filtcrit = "Line3D";
                sortcrit = "Pt. 1";
            }
            cout<<"     Filter criteria successfully set to '"<<filtcrit<<"'!"<<endl;
            cout<<endl;
        }
        if(userC == 3)
        {
            /* Asking user for sorting criteria */
            string newcrit;
            cout<<"[Specifying sorting criteria (current: "<<sortcrit<<")]"<<endl;
            cout<<endl;
            if(filtcrit == "Point2D")
            {
                displaysortcrit();
                cout<<endl;
                cout<<"     Please enter your criteria (a-c): ";
            }
            else if (filtcrit == "Point3D")
            {
                displaysortcrit2();
                cout<<endl;
                cout<<"     Please enter your criteria (a-d): ";
            }
            else if (filtcrit == "Line2D" || filtcrit == "Line3D")
            {
                displaysortcrit3();
                cout<<endl;
                cout<<"     Please enter your criteria (a-c): ";
            }
            cin>>newcrit;
            if(filtcrit == "Point2D")
            {
                if(newcrit == "a")
                {
                    sortcrit = "x-ordinate";
                }
                else if(newcrit == "b")
                {
                    sortcrit = "y-ordinate";
                }
                else if(newcrit == "c")
                {
                    sortcrit = "DistFrOrigin";
                }
            }
            else if(filtcrit == "Point3D")
            {
                if(newcrit == "a")
                {
                    sortcrit = "x-ordinate";
                }
                else if(newcrit == "b")
                {
                    sortcrit = "y-ordinate";
                }
                else if(newcrit == "c")
                {
                    sortcrit = "z-ordinate";
                }
                else if(newcrit == "d")
                {
                    sortcrit = "DistFrOrigin";
                }
            }
            else
            {
                if(newcrit == "a")
                {
                    sortcrit = "Pt. 1";
                }
                else if(newcrit == "b")
                {
                    sortcrit = "Pt. 2";
                }
                else if(newcrit == "c")
                {
                    sortcrit = "Length";
                }
            }
        }
        else if(userC == 4)
        {
            /* Getting whether the user wants Asc or Dsc */
            string neword;
            cout<<"[Specifying sorting order (current: "<<sortord<<")]"<<endl;
            cout<<endl;
            displaysortord();
            cout<<endl;
            cout<<"     Please enter your criteria (a-b): ";
            cin>>neword;
            if(neword == "a")
            {
                sortord = "ASC";
            }
            else
            {
                sortord = "DSC";
            }
        }
        else if(userC == 5)
        {
            /* Printing out the values by first checking filtering criteria */
            /* Then sorting order and then sorting criteria */
            cout<<"[View data ...]"<<endl;
            cout<<"filtering criteria: "<<filtcrit<<endl;
            cout<<"sorting criteria: "<<sortcrit<<endl;
            cout<<"sorting ord: "<<sortord<<endl;
            cout<<endl;
            if(filtcrit == "Point2D")
            {
                if(sortord == "ASC")
                {
                    /* Swapping the positions of classes according to ascending or descending */
                    if(sortcrit == "DistFrOrigin")
                    {
                        sort(begin(p2d),
                        end(p2d), [](Point2D* lhs,Point2D* rhs) ->bool
                        {
                            return (lhs->getScalarValue() < rhs->getScalarValue());
                        });
                    }
                    if(sortcrit == "x-ordinate")
                    {
                        sort(begin(p2d),
                        end(p2d), [](Point2D* lhs,Point2D* rhs) ->bool
                        {
                            return (lhs->getX() == rhs->getX()) ? lhs->getY() < rhs->getY() : lhs->getX() < rhs->getX();
                        });
                    }
                    if(sortcrit == "y-ordinate")
                    {
                        sort(begin(p2d),
                        end(p2d), [](Point2D* lhs,Point2D* rhs) ->bool
                        {
                            return (lhs->getY() == rhs->getY()) ? lhs->getX() < rhs->getX() : lhs->getY() < rhs->getY();
                        });
                    }
                }

                if(sortord == "DSC")
                {
                    if(sortcrit == "DistFrOrigin")
                    {
                        sort(begin(p2d),
                        end(p2d), [](Point2D* lhs,Point2D* rhs) ->bool
                        {
                            return (lhs->getScalarValue() > rhs->getScalarValue());
                        });
                    }
                    if(sortcrit == "x-ordinate")
                    {
                        sort(begin(p2d),
                        end(p2d), [](Point2D* lhs,Point2D* rhs) ->bool
                        {
                            return (lhs->getX() == rhs->getX()) ? lhs->getY() > rhs->getY() : lhs->getX() > rhs->getX();
                        });
                    }
                    if(sortcrit == "y-ordinate")
                    {
                        sort(begin(p2d),
                        end(p2d), [](Point2D* lhs,Point2D* rhs) ->bool
                        {
                            return (lhs->getY() == rhs->getY()) ? lhs->getX() > rhs->getX() : lhs->getY() > rhs->getY();
                        });
                    }
                }
                /* Printing the values */
                cout<<"    X     Y    Dist. Fr Origin"<<endl;
                cout<<"--------------------------------------------"<<endl;
                for(int i =0;i<p2d.size();i++)
                {
                    cout<<p2d[i]->toString();
                }
                cout<<endl;
                cout<<"Press ENTER to go back to main menu ..."<<endl;
                cin.ignore();
                cin.ignore();
            }
            if(filtcrit == "Point3D")
            {
                /* For point 3D if the x and y values are the same, the z values will then be used to compare */
                if(sortord == "ASC")
                {
                    if(sortcrit == "DistFrOrigin")
                    {
                        sort(begin(p3d),
                        end(p3d), [](Point3D* lhs,Point3D* rhs) ->bool
                        {
                            return (lhs->getScalarValue() < rhs->getScalarValue());
                        });
                    }
                    if(sortcrit == "x-ordinate")
                    {
                        sort(begin(p3d),
                        end(p3d), [](Point3D* lhs,Point3D* rhs) ->bool
                        {
                            /* Since Point3D contains x,y,z they are arranged first according to the user and then according to the other values if the values equal */
                            if(lhs->getX() == rhs->getX())
                            {
                                if(lhs->getY() == rhs->getY())
                                {
                                    return (lhs->getZ() < rhs->getZ());
                                }
                                else
                                {
                                    return (lhs->getY() < rhs->getY());
                                }
                            }
                            else
                            {
                                return (lhs->getX() < rhs->getX());
                            }
                        });
                    }
                    if(sortcrit == "y-ordinate")
                    {
                        sort(begin(p3d),
                        end(p3d), [](Point3D* lhs,Point3D* rhs) ->bool
                        {
                            if(lhs->getY() == rhs->getY())
                            {
                                if(lhs->getX() == rhs->getX())
                                {
                                    return (lhs->getZ() < rhs->getZ());
                                }
                                else
                                {
                                    return (lhs->getX() < rhs->getX());
                                }
                            }
                            else
                            {
                                return (lhs->getY() < rhs->getY());
                            }
                        });
                    }
                    if(sortcrit == "z-ordinate")
                    {
                        sort(begin(p3d),
                        end(p3d), [](Point3D* lhs,Point3D* rhs) ->bool
                        {
                            if(lhs->getZ() == rhs->getZ())
                            {
                                if(lhs->getX() == rhs->getX())
                                {
                                    return (lhs->getY() < rhs->getY());
                                }
                                else
                                {
                                    return (lhs->getX() < rhs->getX());
                                }
                            }
                            else
                            {
                                return (lhs->getZ() < rhs->getZ());
                            }
                        });
                    }
                }

                if(sortord == "DSC")
                {
                    if(sortcrit == "DistFrOrigin")
                    {
                        sort(begin(p3d),
                        end(p3d), [](Point3D* lhs,Point3D* rhs) ->bool
                        {
                            return (lhs->getScalarValue() > rhs->getScalarValue());
                        });
                    }
                    if(sortcrit == "x-ordinate")
                    {
                        sort(begin(p3d),
                        end(p3d), [](Point3D* lhs,Point3D* rhs) ->bool
                        {
                            if(lhs->getX() == rhs->getX())
                            {
                                if(lhs->getY() == rhs->getY())
                                {
                                    return (lhs->getZ() > rhs->getZ());
                                }
                                else
                                {
                                    return (lhs->getY() > rhs->getY());
                                }
                            }
                            else
                            {
                                return (lhs->getX() > rhs->getX());
                            }
                            
                        });
                    }
                    if(sortcrit == "y-ordinate")
                    {
                        sort(begin(p3d),
                        end(p3d), [](Point3D* lhs,Point3D* rhs) ->bool
                        {
                            if(lhs->getY() == rhs->getY())
                            {
                                if(lhs->getX() == rhs->getX())
                                {
                                    return (lhs->getZ() > rhs->getZ());
                                }
                                else
                                {
                                    return (lhs->getX() > rhs->getX());
                                }
                            }
                            else
                            {
                                return (lhs->getY() > rhs->getY());
                            }
                        });
                    }
                    if(sortcrit == "z-ordinate")
                    {
                        sort(begin(p3d),
                        end(p3d), [](Point3D* lhs,Point3D* rhs) ->bool
                        {
                            if(lhs->getZ() == rhs->getZ())
                            {
                                if(lhs->getX() == rhs->getX())
                                {
                                    return (lhs->getY() > rhs->getY());
                                }
                                else
                                {
                                    return (lhs->getX() > rhs->getX());
                                }
                            }
                            else
                            {
                                return (lhs->getZ() > rhs->getZ());
                            }
                        });
                    }
                }
                cout<<"    X     Y     Z    Dist. Fr Origin"<<endl;
                cout<<"--------------------------------------------"<<endl;
                for(int i =0;i<p3d.size();i++)
                {
                    cout<<p3d[i]->toString();
                }
                cout<<endl;
                cout<<"Press ENTER to go back to main menu ..."<<endl;
                cin.ignore();
                cin.ignore();
            }
            if(filtcrit == "Line2D")
            {
                if(sortord == "ASC")
                {
                    if(sortcrit == "Length")
                    {
                        sort(begin(l2d),
                        end(l2d), [](Line2D* lhs,Line2D* rhs) ->bool
                        {
                            return (lhs->getScalarValue() < rhs->getScalarValue());
                        });
                    }
                    if(sortcrit == "Pt. 1")
                    {
                        sort(begin(l2d),
                        end(l2d), [](Line2D* lhs,Line2D* rhs) ->bool
                        {
                            return (lhs->getPt1().getX() == rhs->getPt1().getX()) ? lhs->getPt1().getY() < rhs->getPt1().getY() : lhs->getPt1().getX() < rhs->getPt1().getX();
                        });
                    }
                    if(sortcrit == "Pt. 2")
                    {
                        sort(begin(l2d),
                        end(l2d), [](Line2D* lhs,Line2D* rhs) ->bool
                        {
                            return (lhs->getPt2().getX() == rhs->getPt2().getX()) ? lhs->getPt2().getY() < rhs->getPt2().getY() : lhs->getPt2().getX() < rhs->getPt2().getX();
                        });
                    }
                }
                else if(sortord == "DSC")
                {
                    if(sortcrit == "Length")
                    {
                        sort(begin(l2d),
                        end(l2d), [](Line2D* lhs,Line2D* rhs) ->bool
                        {
                            return (lhs->getScalarValue() > rhs->getScalarValue());
                        });
                    }
                    if(sortcrit == "Pt. 1")
                    {
                        sort(begin(l2d),
                        end(l2d), [](Line2D* lhs,Line2D* rhs) ->bool
                        {
                            return (lhs->getPt1().getX() == rhs->getPt1().getX()) ? lhs->getPt1().getY() > rhs->getPt1().getY() : lhs->getPt1().getX() > rhs->getPt1().getX();
                        });
                    }
                    if(sortcrit == "Pt. 2")
                    {
                        sort(begin(l2d),
                        end(l2d), [](Line2D* lhs,Line2D* rhs) ->bool
                        {
                            return (lhs->getPt2().getX() == rhs->getPt2().getX()) ? lhs->getPt2().getY() > rhs->getPt2().getY() : lhs->getPt2().getX() > rhs->getPt2().getX();
                        });
                    }
                }
                cout<<" P1-X  P1-Y     P2-X  P2-Y    Length"<<endl;
                cout<<"--------------------------------------------"<<endl;
                for(int i =0;i<l2d.size();i++)
                {
                    cout<<l2d[i]->toString();
                }
                cout<<endl;
                cout<<"Press ENTER to go back to main menu ..."<<endl;
                cin.ignore();
                cin.ignore();
            }
            if(filtcrit == "Line3D")
            {
                if(sortord == "ASC")
                {
                    if(sortcrit == "Length")
                    {
                        sort(begin(l3d),
                        end(l3d), [](Line3D* lhs,Line3D* rhs) ->bool
                        {
                            return (lhs->getScalarValue() < rhs->getScalarValue());
                        });
                    }
                    if(sortcrit == "Pt. 1")
                    {
                        sort(begin(l3d),
                        end(l3d), [](Line3D* lhs,Line3D* rhs) ->bool
                        {
                            if (lhs->getPt1().getX() == rhs->getPt1().getX())
                            {
                                if(lhs->getPt1().getY() == rhs->getPt1().getY())
                                {
                                    return (lhs->getPt1().getZ() < rhs->getPt1().getZ());
                                }
                                else
                                {
                                    return (lhs->getPt1().getY() < rhs->getPt1().getY());
                                }
                            }
                            else
                            {
                                return (lhs->getPt1().getX() < rhs->getPt1().getX());   
                            }
                        });
                    }
                    if(sortcrit == "Pt. 2")
                    {
                        sort(begin(l3d),
                        end(l3d), [](Line3D* lhs,Line3D* rhs) ->bool
                        {
                            if (lhs->getPt2().getX() == rhs->getPt2().getX())
                            {
                                if(lhs->getPt2().getY() == rhs->getPt2().getY())
                                {
                                    return (lhs->getPt2().getZ() < rhs->getPt2().getZ());
                                }
                                else
                                {
                                    return (lhs->getPt2().getY() < rhs->getPt2().getY());
                                }
                            }
                            else
                            {
                                return (lhs->getPt2().getX() < rhs->getPt2().getX());   
                            }
                        });
                    }
                }
                else if(sortord == "DSC")
                {
                    if(sortcrit == "Length")
                    {
                        sort(begin(l3d),
                        end(l3d), [](Line3D* lhs,Line3D* rhs) ->bool
                        {
                            return (lhs->getScalarValue() > rhs->getScalarValue());
                        });
                    }
                    if(sortcrit == "Pt. 1")
                    {
                        sort(begin(l3d),
                        end(l3d), [](Line3D* lhs,Line3D* rhs) ->bool
                        {
                            if (lhs->getPt1().getX() == rhs->getPt1().getX())
                            {
                                if(lhs->getPt1().getY() == rhs->getPt1().getY())
                                {
                                    return (lhs->getPt1().getZ() > rhs->getPt1().getZ());
                                }
                                else
                                {
                                    return (lhs->getPt1().getY() > rhs->getPt1().getY());
                                }
                            }
                            else
                            {
                                return (lhs->getPt1().getX() > rhs->getPt1().getX());   
                            }
                        });
                    }
                    if(sortcrit == "Pt. 2")
                    {
                        sort(begin(l3d),
                        end(l3d), [](Line3D* lhs,Line3D* rhs) ->bool
                        {
                            if (lhs->getPt2().getX() == rhs->getPt2().getX())
                            {
                                if(lhs->getPt2().getY() == rhs->getPt2().getY())
                                {
                                    return (lhs->getPt2().getZ() > rhs->getPt2().getZ());
                                }
                                else
                                {
                                    return (lhs->getPt2().getY() > rhs->getPt2().getY());
                                }
                            }
                            else
                            {
                                return (lhs->getPt2().getX() > rhs->getPt2().getX());   
                            }
                        });
                    }
                }
                cout<<" P1-X  P1-Y  P1-Z     P2-X  P2-Y  P2-Z    Length"<<endl;
                cout<<"--------------------------------------------------------"<<endl;
                for(int i =0;i<l3d.size();i++)
                {
                    cout<<l3d[i]->toString();
                }
                cout<<endl;
                cout<<"Press ENTER to go back to main menu ..."<<endl;
                cin.ignore();
                cin.ignore();
            }
        }
        else if(userC == 6)
        {
            /* Output File from user */
            string ofile;
            ofstream myfile;
            cout<<"Please enter filename: ";
            cin>>ofile;
            cout<<endl;
            /* Opening the file to write the data */
            myfile.open(ofile);
            /* Print the values in the output file */
            if(filtcrit == "Point2D")
            {
                myfile<<"    X     Y    Dist. Fr Origin"<<endl;
                myfile<<"--------------------------------------------"<<endl;
                for(int i =0;i<p2d.size();i++)
                {
                    myfile<<p2d[i]->toString();
                }
                myfile<<endl;
                /* Closing the file to stop writing the data */
                myfile.close();
                cout<<p2d.size()<<" records output successfully!"<<endl;
                cout<<endl;
                cout<<"Going back to main menu ..."<<endl;
            }
            if(filtcrit == "Point3D")
            {
                myfile<<"    X     Y     Z    Dist. Fr Origin"<<endl;
                myfile<<"--------------------------------------------"<<endl;
                for(int i =0;i<p3d.size();i++)
                {
                    myfile<<p3d[i]->toString();
                }
                myfile<<endl;
                myfile.close();
                cout<<p3d.size()<<" records output successfully!"<<endl;
                cout<<endl;
                cout<<"Going back to main menu ..."<<endl;
            }
            if(filtcrit == "Line2D")
            {
                myfile<<" P1-X  P1-Y     P2-X  P2-Y    Length"<<endl;
                myfile<<"--------------------------------------------"<<endl;
                for(int i =0;i<l2d.size();i++)
                {
                    myfile<<l2d[i]->toString();
                }
                myfile<<endl;
                myfile.close();
                cout<<l2d.size()<<" records output successfully!"<<endl;
                cout<<endl;
                cout<<"Going back to main menu ..."<<endl;
            }
            if(filtcrit == "Line3D")
            {
                myfile<<" P1-X  P1-Y  P1-Z     P2-X  P2-Y  P2-Z    Length"<<endl;
                myfile<<"--------------------------------------------------------"<<endl;
                for(int i =0;i<l3d.size();i++)
                {
                    myfile<<l3d[i]->toString();
                }
                myfile<<endl;
                myfile.close();
                cout<<l3d.size()<<" records output successfully!"<<endl;
                cout<<endl;
                cout<<"Going back to main menu ..."<<endl;
            }
        }
    } while (userC<7);
    /* Deleting all pointers and vectors of pointers and calling the destructors after ending functions */
    for(auto p : p2d)
    {
        delete p;
    }
    p2d.clear();
    vector<Point2D*>().swap(p2d);

    for(auto p : p3d)
    {
        delete p;
    }
    p3d.clear();
    vector<Point3D*>().swap(p3d);

    for(auto p : p2d2)
    {
        delete p;
    }
    p2d2.clear();
    vector<Point2D*>().swap(p2d2);

    for(auto p : p3d2)
    {
        delete p;
    }
    p3d2.clear();
    vector<Point3D*>().swap(p3d2);

    /* Swapping vectors to empty vectors to delete any excess memory */
    l2d.clear();
    vector<Line2D*>().swap(l2d);

    l3d.clear();
    vector<Line3D*>().swap(l3d);
}