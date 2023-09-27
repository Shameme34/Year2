#include "shameem.h"
#include "menu.h"

using namespace std;

/* Creating of the 2D */
string **array2D = nullptr;

/* Creating a struct of a country to store data of each country/city */
struct Country
{
  int x,y;
  int countryCode;
  string countryName;
  int countcoords;
  double cloudcover;
  double pressure;

  Country()
  {
    int x =0;
    int y =0;
    double cloudcover =0;
    double pressure =0; 
    int countryCode =0;
    int countcoords =0;
    string countryName = "";
  }

  Country(int _x, int _y,double _cloudcover, double _pressure, int _countryCode,int _countcoords, string _countryName)
  {
    x=_x;
    y=_y;
    cloudcover = _cloudcover;
    pressure = _pressure;
    countryCode=_countryCode;
    countcoords = _countcoords;
    countryName=_countryName;
  }
  
  /* Making sure there are no duplicates of the countries when creating a vector of structs */
  bool operator < (const Country &other) const
  {
    return make_tuple(x,y,cloudcover,pressure,countryCode,countcoords,countryName) < 
    make_tuple(other.x,other.y,other.cloudcover,other.pressure,other.countryCode,other.countcoords,other.countryName);
  }

  bool operator == (const Country &other) const
  {
    return make_tuple(x,y,cloudcover,pressure,countryCode,countcoords,countryName) == 
    make_tuple(other.x,other.y,other.cloudcover,other.pressure,other.countryCode,other.countcoords,other.countryName);
  }
};

/* Creating a struct of the coordinates to compare if the coordinates are adjacent and diagonally adjacent */
struct GridArea
{
  int x,y,xbegin,ybegin;

  GridArea()
  {
    x=0;
    y=0;
  }

  GridArea(int _x, int _y)
  {
    x=_x;
    y=_y;
  }

  bool isAdjacent (GridArea anotherPt)
  {
    int verticalDist = abs (anotherPt.y - y);
    int horizontalDis = abs (anotherPt.x - x);

    if (
        ((anotherPt.x == x) && (verticalDist == 1)) ||
        ((anotherPt.y == y) && (horizontalDis == 1))
        )
        return (true);
    return (false);
  }

  bool isDiagonalAdjacent (GridArea anotherPt)
  {
    bool isUpperLeft = (anotherPt.x == (x-1)) && (anotherPt.y == (y+1));
    bool isLowerLeft = (anotherPt.x == (x-1)) && (anotherPt.y == (y-1));
    bool isUpperRight = (anotherPt.x == (x+1)) && (anotherPt.y == (y+1));
    bool isLowerRight = (anotherPt.x == (x+1)) && (anotherPt.y == (y-1));

    if ( isUpperLeft || isUpperRight || isLowerLeft || isLowerRight)
      return (true);
    else
      return (false);
  }
};

/* Function for splitting strings */
vector<string> splitString(string str, string delim)
{
  vector<string> result;
  size_t pos =0;
  string token;

  while ((pos = str.find(delim)) != std::string::npos)
  {
    token = str.substr(0,pos);
    result.push_back(token);
    str.erase(0, pos+ delim.length());
  }

  if (!str.empty())
  {
    result.push_back(str);
  }
  return(result);
}

/* Split String Function */
vector<string>splitString(string str, string delim);
/* Declaring Functions that will be using , readAFile will get all referenced variables and pass it to other Functions*/
void readAFile(string inputFilename, vector<string>&data, int &x,int &xbegin, int &y,int &ybegin,vector<Country>&cid, vector<string>&cityIdCoordAll);
void init2DarrayCity (int userRows, int userColumns, int xrangebegin, int yrangebegin, vector<string>data);
void print2Dcloud (int userRows, int userColumns, int xrangebegin, int yrangebegin, vector<string>data);
void print2DcloudLMH (int userRows, int userColumns, int xrangebegin, int yrangebegin, vector<string>data);
void print2Dpressure (int userRows, int userColumns, int xrangebegin, int yrangebegin, vector<string>data);
void print2DpressureLMH (int userRows, int userColumns, int xrangebegin, int yrangebegin, vector<string>data);
void WFSR(vector<Country>cid);
void safelyDeallocateMemory(int userRows, int userColumns, int xrangebegin);

int main()
{
  /* Declare variables  */
  string inputFilename;
  int x, y, y1,x1;
  vector<string>another;
  vector<string>data;
  vector<Country>countries;
  int s;
  cout << endl;

  displayMenu();
  cout<<endl;
  do
  {
    cout<<"Please enter your choice: ";
    cin>>s;
    if(s!=1)
    {
      cout<<"Please enter a config file first!"<<endl;
      cout<<"Please enter your choice: ";
      cin>>s;
    }
  }while(s!=1);

  cout<<endl;
  cout<<"[Read in and process a configuration file]"<<endl;
  cout << "Please enter config filename : ";
  cin >> inputFilename;
  cout<<endl;
  readAFile(inputFilename, data, x,x1,y,y1,countries, another);
  cout<<"Reading in GridX_IdxRange:"<<x1<<"-"<<x<<"...done!"<<endl;
  cout<<"Reading in GridYIdxRange:"<<y1<<"-"<<y<<"...done!"<<endl;
  cout<<endl;

  cout<<"Storing data from input file:"<<endl;
  for(int i=0;i<data.size();i++)
  {
    cout<<data[i]<<"...done!"<<endl;
  }
  cout<<endl;
  cout<<"All records successfully stored. Going back to main menu ..."<<endl;

  do
  {
    if(cin.get() =='\n')
    {
      displayMenu();
      cout<<endl;
      cout<<"Please enter your choice: ";
      cin>>s;
      cout<<endl;
    }
    if(s==1)
    {
      cout<<"Config file already been entered"<<endl;
      cout<<"Quit program to enter new config file"<<endl;
      cout<<endl;
    }
    if(s==2)
    {
      init2DarrayCity(y, x, y1,x1,data);
      cout<<endl;
      safelyDeallocateMemory(y,x,x1);
      cout<<endl;
      cout<<"Press <enter> to go back to main menu"<<endl;
      cin.ignore();
    }
    if(s==3)
    {
      print2Dcloud(y, x, y1,x1,data);
      cout<<endl;
      safelyDeallocateMemory(y,x,x1);
      cout<<endl;
      cout<<"Press <enter> to go back to main menu"<<endl;
      cin.ignore();
    }
    if(s==4)
    {
      print2DcloudLMH(y, x, y1,x1,data);
      cout<<endl;
      safelyDeallocateMemory(y,x,x1);
      cout<<endl;
      cout<<"Press <enter> to go back to main menu"<<endl;
      cin.ignore();
    }
    if(s==5)
    {
      print2Dpressure(y, x, y1,x1,data);
      cout<<endl;
      safelyDeallocateMemory(y,x,x1);
      cout<<endl;
      cout<<"Press <enter> to go back to main menu"<<endl;
      cin.ignore();
    }
    if(s==6)
    {
      print2DpressureLMH(y, x, y1,x1,data);
      cout<<endl;
      safelyDeallocateMemory(y,x,x1);
      cout<<endl;
      cout<<"Press <enter> to go back to main menu"<<endl;
      cin.ignore();
    }
    if(s==7)
    {
      WFSR(countries);
      cout<<"Press <enter> to go back to main menu"<<endl;
      cin.ignore();
    }
  } while (s!=8);
 
  return (0);
}

/* To Read file and process all coordinates */
void readAFile(string inputFilename, vector<string>&data, int &x,int &xbegin, int &y,int &ybegin, vector<Country>&cid, vector<string>&cityIdCoordAll)
{
  fstream inputFile (inputFilename.c_str(), fstream::in);
  string aLine;

  /* To find all files containing *.txt and also getting the x-range and y-range */
  while (getline (inputFile,aLine))
  {
    size_t pos = aLine.find(".txt"); 
    /* Finding the word for the range and then removing until the equal sign to get the x-axis  */
    if (aLine.find("GridX_IdxRange")!= string::npos)
    {
      string xrange = aLine.erase(0,15);
      vector<string> rangex = splitString (xrange, "-");
      int num = stoi(rangex.at(0));
      xbegin = num;
      num = stoi(rangex.at(1));
      x = num;        
    }

    /* Finding the word for the range and then removing until the equal sign to get the y-axis  */
    if (aLine.find("GridY_IdxRange")!= string::npos)
    {
      string yrange = aLine.erase(0,15);
      vector<string> rangey = splitString (yrange, "-");
      int num = stoi(rangey.at(0));
      ybegin = num;
      num = stoi(rangey.at(1));
      y = num;   
    }     
    
    /* Storing all the *.text files in a vector called data */
    if (pos!=string::npos)
    {
      data.push_back(aLine);
    }
  }
  /* 1st set of variables */
  GridArea ga;
  vector<string>data2;
  string cityfile = data.at(0);
  ifstream ReadMyCity (cityfile);
  string cityText;
  vector<string> city;
  vector<string> cityNew;
  vector<int>cityIdCoordniates;
  string cloudfile = data.at(1);
  ifstream ReadMyCloud (cloudfile);
  string cloudText;
  vector<string> cloud;
  vector<string> cloudNew;
  vector<int>cloudCoordniates;
  string chars = "[]";
  
  /* Reading the citylocation file and storing each row in a vector */
  while (getline (ReadMyCity, cityText))
  {
    city.push_back(cityText);
  }

  /* Removing the "[]" and getting "-" and storing each variable in a new vector */
  for (int i=0;i<city.size();i++)
  {
    string s = city[i];
    for (char c: chars)
    {
      s.erase(remove(s.begin(), s.end(),c), s.end());  
    }
    vector<string>dataItems = splitString(s, "-");
    for (int j =0; j <dataItems.size();j++)
    {
      cityNew.push_back(dataItems.at(j));
    }
  }

  /* Removing the "," and storing the city name and ID in a vector called "data2" */
  /* Storing the city coordinates and city ID in another vector called "cityIDCoordinates" */
  for (int i=0;i<cityNew.size();i++)
  {
    if (i%3 == 0)
    {
      string a = cityNew.at(i);
      vector<string>coordinates = splitString (a, ", ");
      for(int j =0;j<coordinates.size();j++)
      {
        int num = stoi(coordinates.at(j));
        cityIdCoordniates.push_back(num);
      }
    }
    else if (i%3 == 1)
    {
      string a = cityNew[i];
      int num = stoi(cityNew[i]);
      cityIdCoordniates.push_back(num);
      data2.push_back(cityNew[i]);
    }
    else if(i%3==2)
    {
      string b = cityNew[i];
      data2.push_back(cityNew[i]);
    }
  }
  
  /* Creating a new set of struct for each country and labelling the ID and name  */
  /* by creating a vector of structs to store each country */
  int k=0;
  for (int i=0;i<data2.size();i++)
  {
    if (i%2==0)
    {
      cid.push_back(Country());
      int num = stoi(data2[i]);
      cid[k].countryCode = num;
    }
    if(i%2==1)
    {
      cid[k].countryName = data2[i];
      k++;
    }
  }

  /* Storing each line in the cloud txt file into a new vector */
  while (getline (ReadMyCloud, cloudText))
  {
    cloud.push_back(cloudText);
  }

  /* Same Function used for the cloud txt file to get split and get the ID and Coordinates and putting them in new vectors */
  for (int i=0;i<cloud.size();i++)
  {
    string s = cloud[i];
    for (char c: chars)
    {
      s.erase(remove(s.begin(), s.end(),c), s.end());
    }
    vector<string>dataItems = splitString(s, "-");
    for (int j =0; j <dataItems.size();j++)
    {
      cloudNew.push_back(dataItems[j]);
    }
  }

  for (int i=0;i<cloudNew.size();i++)
  {
    if (i%2 == 0)
    {
      string a = cloudNew[i];
      vector<string>coordinates = splitString (a, ", ");
      for(int j =0;j<coordinates.size();j++)
      {
        int num = stoi(coordinates[j]);
        cloudCoordniates.push_back(num);
      }
    }
    else if (i%2 == 1)
    {
      string a = cloudNew[i];
      int num = stoi(cloudNew[i]);
      cloudCoordniates.push_back(num);
    }
  }

  /* Counter to count the number of spaces and the perimeter the city covers  */
  for(int i=0;i<cid.size();i++)
  {
    cid[i].countcoords = 0;
  }

  /* Sort and delete any duplicates in the vector of structs */
  std::sort(cid.begin(), cid.end());
  cid.erase(std::unique(cid.begin(),cid.end()),cid.end());

  /* New set of variables */
  int yrangebegin = ybegin;
  int xrangebegin = xbegin;
  int userRows = x;
  int userColumns = y;

  int b = yrangebegin;
  int xa = xrangebegin;
  int l = userColumns;
  int a = userRows+4;
  int ba = (userColumns)+4;

  //Creating 2d vector
  vector<string>row (a);
  vector<vector<string>>vect(ba, row);

  for (int i =0;i <userColumns+4 -b;i++)
  {
    for(int j =0; j < ((userRows)+4 -xa)  ; j++)
    {
      string str12 = " ";

      /* Storing each city coordinates and ID in a vector according to ID,X,Y  */
      for (int r=0;r<cityIdCoordniates.size();r++)
      {
        if(r%3 ==0 && j == (cityIdCoordniates[r] +2) && i == ((userColumns+4)-(cityIdCoordniates[r+1]+2)) )
        {
          str12 = to_string(cityIdCoordniates[r+2]);
          
          /* String ID,X,Y */
          string str13 = to_string(cityIdCoordniates[r+2]) + "," + to_string(i) + "," + to_string(j);
          cityIdCoordAll.push_back(str13);

          /* Using the Grid struct to find adjacent grids to use */
          /* Putting this strings into another vector */
          /* This allows overlapping if 2 countries share spaces */
          /* This vector will be used to get the coordinates and country ID of the spaces */
          /* Occupied by the specific country */
          ga.x = i;
          ga.y = j;
          GridArea ga_1 (i-1,j);
          GridArea ga_2 (i+1,j);
          GridArea ga_3 (i,j-1);
          GridArea ga_4 (i,j+1);
          GridArea ga_5 (i+1,j+1);
          GridArea ga_6 (i+1,j-1);
          GridArea ga_7 (i-1,j-1);
          GridArea ga_8 (i-1,j+1);
          if (ga.isAdjacent (ga_1) == true)
          {
            string str14 = to_string(cityIdCoordniates[r+2]) + "," + to_string(ga_1.x) + "," + to_string(ga_1.y);
            cityIdCoordAll.push_back(str14);
          }
          if (ga.isAdjacent (ga_2) == true)
          {
            string str14 = to_string(cityIdCoordniates[r+2]) + "," + to_string(ga_2.x) + "," + to_string(ga_2.y);
            cityIdCoordAll.push_back(str14);
          }
          if (ga.isAdjacent (ga_3) == true)
          {
            string str14 = to_string(cityIdCoordniates[r+2]) + "," + to_string(ga_3.x) + "," + to_string(ga_3.y);
            cityIdCoordAll.push_back(str14);
          }
          if (ga.isAdjacent (ga_4) == true)
          {
            string str14 = to_string(cityIdCoordniates[r+2]) + "," + to_string(ga_4.x) + "," + to_string(ga_4.y);
            cityIdCoordAll.push_back(str14);
          }
          if (ga.isDiagonalAdjacent(ga_5) == true)
          {
            string str14 = to_string(cityIdCoordniates[r+2]) + "," + to_string(ga_5.x) + "," + to_string(ga_5.y);
            cityIdCoordAll.push_back(str14);
          }
          if (ga.isDiagonalAdjacent(ga_6) == true)
          {
            string str14 = to_string(cityIdCoordniates[r+2]) + "," + to_string(ga_6.x) + "," + to_string(ga_6.y);
            cityIdCoordAll.push_back(str14);
          }
          if (ga.isDiagonalAdjacent(ga_7) == true)
          {
            string str14 = to_string(cityIdCoordniates[r+2]) + "," + to_string(ga_7.x) + "," + to_string(ga_7.y);
            cityIdCoordAll.push_back(str14);
          }
          if (ga.isDiagonalAdjacent(ga_8) == true)
          {
            string str14 = to_string(cityIdCoordniates[r+2]) + "," + to_string(ga_8.x) + "," + to_string(ga_8.y);
            cityIdCoordAll.push_back(str14);
          }
        }
      }
    }
  }

 /* Sorting and removing duplicates */
  sort(cityIdCoordAll.begin(), cityIdCoordAll.end());
  cityIdCoordAll.erase(unique(cityIdCoordAll.begin(),cityIdCoordAll.end()),cityIdCoordAll.end());

  /* Copying the vector to be safe */
  vector<string>copycityId = cityIdCoordAll;
  vector<int>values;

  /* Removing every "," and changing to a vector of integers */
  for(int i=0;i<copycityId.size();i++)
  {
    string a = copycityId[i];
    vector<string>beforvalues = splitString(a,",");
    for (int j =0;j<beforvalues.size();j++)
    {
      int num = stoi(beforvalues[j]);
      values.push_back(num);
    }
  }

  /* Comparing the coordinates and Country codes and if the match add the cloudcover to the total cloud cover for the country */
  for (int i =0;i <userColumns+4 -b;i++)
  {
    for(int j =0; j < ((userRows)+4 -xa)  ; j++)
    {
      for (int r=0;r<cloudCoordniates.size();r++)
      {
        if(r%3 ==0 && i == ((userColumns+4)-(cloudCoordniates[r+1]+2)) && j == (cloudCoordniates[r] +2) )
        {
          for(int p =0;p<values.size();p++)
          {
            if (p%3==0 && i==values[p+1] && j==values[p+2])
            {
              for(int g=0;g<cid.size();g++)
              {
                if(values[p] == cid[g].countryCode)
                {
                  cid[g].cloudcover = cid[g].cloudcover + cloudCoordniates[r+2];
                  cid[g].countcoords += 1;
                }
              }
            }
          }
        }
      }
    }
  }

  /* All comments same as for the above just for the atmosphere file */
  string atmospherefile = data.at(2);
  ifstream ReadMyatmosphere (atmospherefile);
  string atmosphereText;
  vector<string> atmosphere;
  vector<string> atmosphereNew;
  vector<int>atmosphereCoordniates;

  while (getline (ReadMyatmosphere, atmosphereText))
  {
    atmosphere.push_back(atmosphereText);
  }

  for (int i=0;i<atmosphere.size();i++)
  {
    string s = atmosphere[i];
    for (char c: chars)
    {
      s.erase(remove(s.begin(), s.end(),c), s.end());
    }
    vector<string>dataItems = splitString(s, "-");
    for (int j =0; j <dataItems.size();j++)
    {
      atmosphereNew.push_back(dataItems[j]);
    }
  }
	

  for (int i=0;i<atmosphereNew.size();i++)
  {
    if (i%2 == 0)
    {
      string a = atmosphereNew[i];
      vector<string>coordinates = splitString (a, ", ");
      for(int j =0;j<coordinates.size();j++)
      {
        int num = stoi(coordinates[j]);
        atmosphereCoordniates.push_back(num);
      }
    }
    else if (i%2 == 1)
    {
      string a = atmosphereNew[i];
      int num = stoi(atmosphereNew[i]);
      atmosphereCoordniates.push_back(num);
    }
  }
	for(int i=0;i<cid.size();i++)
	{
	cid[i].pressure =0;
	}


  for (int i =0;i <userColumns+4 -b;i++)
  {
    for(int j =0; j < ((userRows)+4 -xa)  ; j++)
    {
      int num;
      for (int r=0;r<atmosphereCoordniates.size();r++)
      {
        if(r%3 ==0 && i == ((userColumns+4)-(atmosphereCoordniates[r+1]+2)) && j == (atmosphereCoordniates[r] +2) )
        { 
          for(int p =0;p<values.size();p++)
          {
            if (p%3==0 && i==values[p+1] && j==values[p+2])
            {
              for(int g=0;g<cid.size();g++)
              {
                if(values[p] == cid[g].countryCode)
                {
                  cid[g].pressure = cid[g].pressure + atmosphereCoordniates[r+2];
                }
              }
            }
          }  
        }
      }
    }
  }
}

/* To print the city and the grid */
void init2DarrayCity (int userRows, int userColumns, int xrangebegin, int yrangebegin, vector<string>data)
{
	
  GridArea ga;
  string cityfile = data[0];
  ifstream ReadMyCity (cityfile);
  string cityText;
  vector<string> city;
  vector<string> cityNew;
  vector<int>cityIdCoordniates;
  string chars = "[]";
  
  while (getline (ReadMyCity, cityText))
  {
    city.push_back(cityText);
  }

  for (int i=0;i<city.size();i++)
  {
    string s = city[i];
    for (char c: chars)
    {
      s.erase(remove(s.begin(), s.end(),c), s.end());
    }
    vector<string>dataItems = splitString(s, "-");
    for (int j =0; j <dataItems.size();j++)
    {
      cityNew.push_back(dataItems[j]);
    }
  }

  for (int i=0;i<cityNew.size();i++)
  {
    if (i%3 == 0)
    {
      string a = cityNew[i];
      vector<string>coordinates = splitString (a, ", ");
      for(int j =0;j<coordinates.size();j++)
      {
        int num = stoi(coordinates[j]);
        cityIdCoordniates.push_back(num);
      }
    }
    else if (i%3 == 1)
    {
      string a = cityNew[i];
      int num = stoi(cityNew[i]);
      cityIdCoordniates.push_back(num);
    }
  }
  int l = userRows;
  /*Intializing the 2D array*/
  if(userRows%2==0)
  {
    array2D = new string *[userRows+4];
    for(int i=userRows+4;i>xrangebegin;i--)
    {
      array2D [i] = new string [userColumns+4];
    }
  }else
  {
    array2D = new string *[userRows+3];
    for(int i=userRows+3;i>xrangebegin;i--)
    {
      array2D [i] = new string [userColumns+4];
    }
  }

  for (int i=userRows+3;i>xrangebegin;i--)
  {
	
    for(int j =yrangebegin;j<userColumns+4;j++)
    {
      ostringstream oss;
      if (j == yrangebegin+1 || j == userColumns+3)
      {
        oss<<"#";
      }
      else if (i==xrangebegin +1 && j!=yrangebegin)
      {
        oss<<"#";
      }
      else if (i==userRows+3 && j!= yrangebegin)
      {
        oss<<"#";
      }
      else if (j == yrangebegin && l>= xrangebegin && i-2==l)
      {
        if (l>=xrangebegin)
        {
          oss<< array2D[i][j]<< l--;
        }
        else 
        {
          oss<< array2D[i][j]<< " ";
        }
      }
      else
      {
        /* Print city id on the grid */
        string str12 = " ";
        for (int r=0;r<cityIdCoordniates.size();r++)
        {
        if(r%3 ==0 && j == (cityIdCoordniates[r] +2) && i == (cityIdCoordniates[r+1]+2) )
        {
          str12 = to_string(cityIdCoordniates[r+2]);
        }
        }
        oss<<str12;
      }
      array2D[i][j] = oss.str();
    }
  }

  for (int i=userRows+3;i>xrangebegin;i--)
  {
    for(int j =yrangebegin;j<userColumns+4;j++)
    {
      cout<<setw(2)<<array2D[i][j]<<" ";  
    }
    cout<<endl;
  }
  
  for (int j =0; j<(userRows)+3; j++ )
  {
    if ((j>=xrangebegin && j<=userRows+3))
    {
      if(yrangebegin<=userColumns &&j>=2)
      {
        if (yrangebegin <10)
        {
          cout<<setw(2)<<yrangebegin++<<" ";
        }
        else
        {
          cout<<setw(3)<<yrangebegin++;
        }
      }
      else cout<<setw(3)<<"  ";
    }
  }
cout<<endl;
cout<<endl;

}

/* Cloud printing Function */
void print2Dcloud (int userRows, int userColumns, int xrangebegin, int yrangebegin, vector<string>data)
{
  /* All Functions and variables declaration */
  /* Same reasoning form above for the Cloud */
	
  GridArea ga;
  string cloudfile = data[1];
  ifstream ReadMyCloud (cloudfile);
  string cloudText;
  vector<string> cloud;
  vector<string> cloudNew;
  vector<int>cloudCoordniates;
  string chars = "[]";

  while (getline (ReadMyCloud, cloudText))
  {
    cloud.push_back(cloudText);
  }

  for (int i=0;i<cloud.size();i++)
  {
    string s = cloud[i];
    for (char c: chars)
    {
      s.erase(remove(s.begin(), s.end(),c), s.end()); 
    }
    vector<string>dataItems = splitString(s, "-");
    for (int j =0; j <dataItems.size();j++)
    {
      cloudNew.push_back(dataItems[j]);
    }
  }

  for (int i=0;i<cloudNew.size();i++)
  {
    if (i%2 == 0)
    {
      string a = cloudNew[i];
      vector<string>coordinates = splitString (a, ", ");
      for(int j =0;j<coordinates.size();j++)
      {
        int num = stoi(coordinates[j]);
        cloudCoordniates.push_back(num);
      }
    }
    else if (i%2 == 1)
    {
      string a = cloudNew[i];
      int num = stoi(cloudNew[i]);
      cloudCoordniates.push_back(num);
    }
  }

  int l = userRows;
  if(userRows%2==0)
  {
    array2D = new string *[userRows+4];
    for(int i=userRows+4;i>xrangebegin;i--)
    {
      array2D [i] = new string [userColumns+4];
    }
  }else
  {
    array2D = new string *[userRows+3];
    for(int i=userRows+3;i>xrangebegin;i--)
    {
      array2D [i] = new string [userColumns+4];
    }
  }
  
  for (int i=userRows+3;i>xrangebegin;i--)
  {
    for(int j =yrangebegin;j<userColumns+4;j++)
    {
      ostringstream oss;
      if (j == yrangebegin+1 || j == userColumns+3)
      {
        oss<<"#";
      }
      else if (i==xrangebegin +1 && j!=yrangebegin)
      {
        oss<<"#";
      }
      else if (i==userRows+3 && j!= yrangebegin)
      {
        oss<<"#";
      }
      else if (j == yrangebegin && l>= xrangebegin && i-2==l)
      {
        if (l>=xrangebegin)
        {
          oss<< array2D[i][j]<< l--;
        }
        else 
        {
          oss<< array2D[i][j]<< " ";
        }
      }
      else
      {
        /* Print city id on the grid */
        string str12 = " ";
        for (int r=0;r<cloudCoordniates.size();r++)
        {
          if(r%3 ==0 && i == ((cloudCoordniates[r+1]+2)) && j == (cloudCoordniates[r] +2) )
          {
            if (cloudCoordniates[r+2]>=0 && cloudCoordniates[r+2]<10)
              str12 = "0";  
            else if (cloudCoordniates[r+2]>=10 && cloudCoordniates[r+2]<20)
              str12 = "1";
            else if (cloudCoordniates[r+2]>=20 && cloudCoordniates[r+2]<30)
              str12 = "2"; 
            else if (cloudCoordniates[r+2]>=30 && cloudCoordniates[r+2]<40)
              str12 = "3"; 
            else if (cloudCoordniates[r+2]>=40 && cloudCoordniates[r+2]<50)
              str12 = "4"; 
            else if (cloudCoordniates[r+2]>=50 && cloudCoordniates[r+2]<60)
              str12 = "5"; 
            else if (cloudCoordniates[r+2]>=60 && cloudCoordniates[r+2]<70)
              str12 = "6"; 
            else if (cloudCoordniates[r+2]>=70 && cloudCoordniates[r+2]<80)
              str12 = "7"; 
            else if (cloudCoordniates[r+2]>=80 && cloudCoordniates[r+2]<90)
              str12 = "8"; 
            else if (cloudCoordniates[r+2]>=90 && cloudCoordniates[r+2]<100)
              str12 = "9"; 
            else 
              str12 = " ";   
          }
        }
        oss<<str12;
      }
      array2D[i][j] = oss.str();
    }
  }

  for (int i=userRows+3;i>xrangebegin;i--)
  {
    for(int j =yrangebegin;j<userColumns+4;j++)
    {
      cout<<setw(2)<<array2D[i][j]<<" ";  
    }
    cout<<endl;
  }
  
  for (int j =0; j<(userRows)+3; j++ )
  {
    if ((j>=xrangebegin && j<=userRows+3))
    {
      if(yrangebegin<=userColumns &&j>=2)
      {
        if (yrangebegin <10)
        {
          cout<<setw(2)<<yrangebegin++<<" ";
        }
        else
        {
          cout<<setw(3)<<yrangebegin++;
        }
      }
      else cout<<setw(3)<<"  ";
    }
  }

}

/* Function for printing the cloud grid for the L/M/H  */
void print2DcloudLMH (int userRows, int userColumns, int xrangebegin, int yrangebegin, vector<string>data)
{
  /* All Functions and variables declaration */
  /* Same reasoning form above for the Cloud */

  GridArea ga;
  string cloudfile = data[1];
  ifstream ReadMyCloud (cloudfile);
  string cloudText;
  vector<string> cloud;
  vector<string> cloudNew;
  vector<int>cloudCoordniates;
  string chars = "[]";

  while (getline (ReadMyCloud, cloudText))
  {
    cloud.push_back(cloudText);
  }

  for (int i=0;i<cloud.size();i++)
  {
    string s = cloud[i];
    for (char c: chars)
    {
      s.erase(remove(s.begin(), s.end(),c), s.end());     
    }
    vector<string>dataItems = splitString(s, "-");
    for (int j =0; j <dataItems.size();j++)
    {
      cloudNew.push_back(dataItems[j]);
    }
  }

  for (int i=0;i<cloudNew.size();i++)
  {
    if (i%2 == 0)
    {
      string a = cloudNew[i];
      vector<string>coordinates = splitString (a, ", ");
      for(int j =0;j<coordinates.size();j++)
      {
        int num = stoi(coordinates[j]);
        cloudCoordniates.push_back(num);
      }
    }
    else if (i%2 == 1)
    {
      string a = cloudNew[i];
      int num = stoi(cloudNew[i]);
      cloudCoordniates.push_back(num);
    }
  }

  int l = userRows;
if(userRows%2==0)
{
	array2D = new string *[userRows+4];
	for(int i=userRows+4;i>xrangebegin;i--)
  {
    array2D [i] = new string [userColumns+4];
  }
}else
{
	array2D = new string *[userRows+3];
	for(int i=userRows+3;i>xrangebegin;i--)
  {
    array2D [i] = new string [userColumns+4];
  }
}
  
  for (int i=userRows+3;i>xrangebegin;i--)
  {
    for(int j =yrangebegin;j<userColumns+4;j++)
    {
      ostringstream oss;
      if (j == yrangebegin+1 || j == userColumns+3)
      {
        oss<<"#";
      }
      else if (i==xrangebegin +1 && j!=yrangebegin)
      {
        oss<<"#";
      }
      else if (i==userRows+3 && j!= yrangebegin)
      {
        oss<<"#";
      }
      else if (j == yrangebegin && l>= xrangebegin && i-2==l)
      {
        if (l>=xrangebegin)
        {
          oss<< array2D[i][j]<< l--;
        }
        else 
        {
          oss<< array2D[i][j]<< " ";
        }
      }
      else
      {
        /* Print city id on the grid */
        string str12 = " ";
        for (int r=0;r<cloudCoordniates.size();r++)
        {
          if(r%3 ==0 && i == ((cloudCoordniates[r+1]+2)) && j == (cloudCoordniates[r] +2) )
          {
            if (cloudCoordniates[r+2]>=0 && cloudCoordniates[r+2]<35)
              str12 = "L";  
            else if (cloudCoordniates[r+2]>=35 && cloudCoordniates[r+2]<65)
              str12 = "M";
            else if (cloudCoordniates[r+2]>=65 && cloudCoordniates[r+2]<100)
              str12 = "H"; 
            else 
              str12 = " "; 
          }
        }
        oss<<str12;
      }
      array2D[i][j] = oss.str();
    }
  }

  for (int i=userRows+3;i>xrangebegin;i--)
  {
    for(int j =yrangebegin;j<userColumns+4;j++)
    {
      cout<<setw(2)<<array2D[i][j]<<" ";  
    }
    cout<<endl;
  }
  
  for (int j =0; j<(userRows)+3; j++ )
  {
    if ((j>=xrangebegin && j<=userRows+3))
    {
      if(yrangebegin<=userColumns &&j>=2)
      {
        if (yrangebegin <10)
        {
          cout<<setw(2)<<yrangebegin++<<" ";
        }
        else
        {
          cout<<setw(3)<<yrangebegin++;
        }
      }
      else cout<<setw(3)<<"  ";
    }
  }
}

/* Atmosphere printing Function */
void print2Dpressure (int userRows, int userColumns, int xrangebegin, int yrangebegin, vector<string>data)
{
   /* All Functions and variables declaration */
  /* Same reasoning form above for the Atmosphere */
	
  GridArea ga;
  string atmospherefile = data[2];
  ifstream ReadMyatmosphere (atmospherefile);
  string atmosphereText;
  vector<string> atmosphere;
  vector<string> atmosphereNew;
  vector<int>atmosphereCoordniates;
  string chars = "[]";

  while (getline (ReadMyatmosphere, atmosphereText))
  {
    atmosphere.push_back(atmosphereText);
  }

  for (int i=0;i<atmosphere.size();i++)
  {
    string s = atmosphere[i];
    for (char c: chars)
    {
      s.erase(remove(s.begin(), s.end(),c), s.end()); 
    }
    vector<string>dataItems = splitString(s, "-");
    for (int j =0; j <dataItems.size();j++)
    {
      atmosphereNew.push_back(dataItems[j]);
    }
  }

  for (int i=0;i<atmosphereNew.size();i++)
  {
    if (i%2 == 0)
    {
      string a = atmosphereNew[i];
      vector<string>coordinates = splitString (a, ", ");
      for(int j =0;j<coordinates.size();j++)
      {
        int num = stoi(coordinates[j]);
        atmosphereCoordniates.push_back(num);
      }
    }
    else if (i%2 == 1)
    {
      string a = atmosphereNew[i];
      int num = stoi(atmosphereNew[i]);
      atmosphereCoordniates.push_back(num);
    }
  }

  int l = userRows;
  if(userRows%2==0)
  {
    array2D = new string *[userRows+4];
    for(int i=userRows+4;i>xrangebegin;i--)
    {
      array2D [i] = new string [userColumns+4];
    }
  }else
  {
    array2D = new string *[userRows+3];
    for(int i=userRows+3;i>xrangebegin;i--)
    {
      array2D [i] = new string [userColumns+4];
    }
  }
  
  for (int i=userRows+3;i>xrangebegin;i--)
  {
    for(int j =yrangebegin;j<userColumns+4;j++)
    {
      ostringstream oss;
      if (j == yrangebegin+1 || j == userColumns+3)
      {
        oss<<"#";
      }
      else if (i==xrangebegin +1 && j!=yrangebegin)
      {
        oss<<"#";
      }
      else if (i==userRows+3 && j!= yrangebegin)
      {
        oss<<"#";
      }
      else if (j == yrangebegin && l>= xrangebegin && i-2==l)
      {
        if (l>=xrangebegin)
        {
          oss<< array2D[i][j]<< l--;
        }
        else 
        {
          oss<< array2D[i][j]<< " ";
        }
      }
      else
      {
        /* Atmosphere printing Function */ 
        string str12 = " ";
        int num;
        for (int r=0;r<atmosphereCoordniates.size();r++)
        {
          if(r%3 ==0 && i == ((atmosphereCoordniates[r+1]+2)) && j == (atmosphereCoordniates[r] +2) )
          {
            if (atmosphereCoordniates[r+2]>=0 && atmosphereCoordniates[r+2]<10)
              str12 = "0";  
            else if (atmosphereCoordniates[r+2]>=10 && atmosphereCoordniates[r+2]<20)
              str12 = "1";
            else if (atmosphereCoordniates[r+2]>=20 && atmosphereCoordniates[r+2]<30)
              str12 = "2"; 
            else if (atmosphereCoordniates[r+2]>=30 && atmosphereCoordniates[r+2]<40)
              str12 = "3"; 
            else if (atmosphereCoordniates[r+2]>=40 && atmosphereCoordniates[r+2]<50)
              str12 = "4"; 
            else if (atmosphereCoordniates[r+2]>=50 && atmosphereCoordniates[r+2]<60)
              str12 = "5"; 
            else if (atmosphereCoordniates[r+2]>=60 && atmosphereCoordniates[r+2]<70)
              str12 = "6"; 
            else if (atmosphereCoordniates[r+2]>=70 && atmosphereCoordniates[r+2]<80)
              str12 = "7"; 
            else if (atmosphereCoordniates[r+2]>=80 && atmosphereCoordniates[r+2]<90)
              str12 = "8"; 
            else if (atmosphereCoordniates[r+2]>=90 && atmosphereCoordniates[r+2]<100)
              str12 = "9"; 
            else 
              str12 = " ";  
          }
        }
        oss<<str12;
      }
      array2D[i][j] = oss.str();
    }
  }

  for (int i=userRows+3;i>xrangebegin;i--)
  {
    for(int j =yrangebegin;j<userColumns+4;j++)
    {
      cout<<setw(2)<<array2D[i][j]<<" ";  
    }
    cout<<endl;
  }
  
  for (int j =0; j<(userRows)+4; j++ )
  {
    if ((j>=xrangebegin && j<=userRows+4))
    {
      if(yrangebegin<=userColumns &&j>=2)
      {
        if (yrangebegin <10)
        {
          cout<<setw(2)<<yrangebegin++<<" ";
        }
        else
        {
          cout<<setw(3)<<yrangebegin++;
        }
      }
      else cout<<setw(3)<<"  ";
    }
  }

}

/* Atmosphere printing Function for LMH */
void print2DpressureLMH (int userRows, int userColumns, int xrangebegin, int yrangebegin, vector<string>data)
{
   /* All Functions and variables declaration */
  /* Same reasoning form above for the Atmosphere */
	
  GridArea ga;
  string atmospherefile = data[2];
  ifstream ReadMyatmosphere (atmospherefile);
  string atmosphereText;
  vector<string> atmosphere;
  vector<string> atmosphereNew;
  vector<int>atmosphereCoordniates;
  string chars = "[]";

  while (getline (ReadMyatmosphere, atmosphereText))
  {
    atmosphere.push_back(atmosphereText);
  }

  for (int i=0;i<atmosphere.size();i++)
  {
    string s = atmosphere[i];
    for (char c: chars)
    {
      s.erase(remove(s.begin(), s.end(),c), s.end()); 
    }
    vector<string>dataItems = splitString(s, "-");
    for (int j =0; j <dataItems.size();j++)
    {
      atmosphereNew.push_back(dataItems[j]);
    }
  }

  for (int i=0;i<atmosphereNew.size();i++)
  {
    if (i%2 == 0)
    {
      string a = atmosphereNew[i];
      vector<string>coordinates = splitString (a, ", ");
      for(int j =0;j<coordinates.size();j++)
      {
        int num = stoi(coordinates[j]);
        atmosphereCoordniates.push_back(num);
      }
    }
    else if (i%2 == 1)
    {
      string a = atmosphereNew[i];
      int num = stoi(atmosphereNew[i]);
      atmosphereCoordniates.push_back(num);
    }
  }

  int l = userRows;
  if(userRows%2==0)
  {
    array2D = new string *[userRows+4];
    for(int i=userRows+4;i>xrangebegin;i--)
    {
      array2D [i] = new string [userColumns+4];
    }
  }else
  {
    array2D = new string *[userRows+3];
    for(int i=userRows+3;i>xrangebegin;i--)
    {
      array2D [i] = new string [userColumns+4];
    }
  }
  
  for (int i=userRows+3;i>xrangebegin;i--)
  {
    for(int j =yrangebegin;j<userColumns+4;j++)
    {
      ostringstream oss;
      if (j == yrangebegin+1 || j == userColumns+3)
      {
        oss<<"#";
      }
      else if (i==xrangebegin +1 && j!=yrangebegin)
      {
        oss<<"#";
      }
      else if (i==userRows+3 && j!= yrangebegin)
      {
        oss<<"#";
      }
      else if (j == yrangebegin && l>= xrangebegin && i-2==l)
      {
        if (l>=xrangebegin)
        {
          oss<< array2D[i][j]<< l--;
        }
        else 
        {
          oss<< array2D[i][j]<< " ";
        }
      }
      else
      {
        /* Atmosphere printing Function */ 
        string str12 = " ";
        int num;
        for (int r=0;r<atmosphereCoordniates.size();r++)
        {
          if(r%3 ==0 && i == ((atmosphereCoordniates[r+1]+2)) && j == (atmosphereCoordniates[r] +2) )
          {
            if (atmosphereCoordniates[r+2]>=0 && atmosphereCoordniates[r+2]<35)
              str12 = "L";  
            else if (atmosphereCoordniates[r+2]>=35 && atmosphereCoordniates[r+2]<65)
              str12 = "M";
            else if (atmosphereCoordniates[r+2]>=65 && atmosphereCoordniates[r+2]<100)
              str12 = "H"; 
            else 
              str12 = " ";    
          }
        }
        oss<<str12;
      }
      array2D[i][j] = oss.str();
    }
  }

  for (int i=userRows+3;i>xrangebegin;i--)
  {
    for(int j =yrangebegin;j<userColumns+4;j++)
    {
      cout<<setw(2)<<array2D[i][j]<<" ";  
    }
    cout<<endl;
  }
  
  for (int j =0; j<(userRows)+4; j++ )
  {
    if ((j>=xrangebegin && j<=userRows+4))
    {
      if(yrangebegin<=userColumns &&j>=2)
      {
        if (yrangebegin <10)
        {
          cout<<setw(2)<<yrangebegin++<<" ";
        }
        else
        {
          cout<<setw(3)<<yrangebegin++;
        }
      }
      else cout<<setw(3)<<"  ";
    }
  }
}

/*Function to display weather forecast report */
void WFSR(vector<Country>cid)
{
  cout<<"Weather Forecast Summary Report"<<endl;
  cout<<"-------------------------------"<<endl;
  for(int i=cid.size()-1;i>=0;i--)
  {
    float averagec;
    averagec = cid[i].cloudcover/cid[i].countcoords;
    string csymbol;
    if(averagec<35)
    {
      csymbol ="L";
    }
    else if (averagec<65 && averagec >=35)
    {
      csymbol ="M";
    }
    else if (averagec<100 && averagec >=65)
    {
      csymbol = "H";
    }
    
    float averagep;
    averagep = cid[i].pressure/cid[i].countcoords;
    string psymbol;
    if(averagep<35)
    {
      psymbol ="L";
    }
    else if (averagep<65 && averagep >=35)
    {
      psymbol ="M";
    }
    else if (averagep<100 && averagep >=65)
    {
      psymbol = "H";
    }

    int x;
    float rain;
    string rain1;
    string rain2;
    string rain3;
    if (psymbol == "L" && csymbol == "H")
    {
      rain = 90;
      rain1 ="~~~~";
      rain2 ="~~~~~";
      rain3 ="\\\\\\\\\\";
    } 
    else if (psymbol == "L" && csymbol == "M")
    {
      rain = 80;
      rain1 ="~~~~";
      rain2 ="~~~~~";
      rain3 =" \\\\\\\\";
    }
    else if (psymbol == "L" && csymbol == "L")
    {
      rain = 70;
      rain1 ="~~~~";
      rain2 ="~~~~~";
      rain3 ="  \\\\\\";
    }
    else if (psymbol == "M" && csymbol == "H")
    {
      rain = 60;
      rain1 ="~~~~";
      rain2 ="~~~~~";
      rain3 ="   \\\\";
    } 
    else if (psymbol == "M" && csymbol == "M")
    {
      rain = 50;
      rain1 ="~~~~";
      rain2 ="~~~~~";
      rain3 ="    \\";
    }   
    else if (psymbol == "M" && csymbol == "L")
    {
      rain = 40;
      rain1 ="~~~~";
      rain2 ="~~~~~";
      rain3 ="    ";
    } 
    else if (psymbol == "H" && csymbol == "H")
    {
      rain = 30;
      rain1 ="~~~";
      rain2 ="~~~~";
      rain3 =" ";
    } 
    else if (psymbol == "H" && csymbol == "M")
    {
      rain = 20;
      rain1 ="~~";
      rain2 ="~~~";
      rain3 =" ";
    } 
    else if (psymbol == "H" && csymbol == "L")
    {
      rain = 10;
      rain1 ="~";
      rain2 ="~~";
      rain3 =" ";
    } 

    cout<<"City Name  : "<<cid[i].countryName<<endl;
    cout<<"City ID    : "<<cid[i].countryCode<<endl;
    cout<<"Ave. Cloud Cover (ACC)   : "<<fixed<<setprecision(2)<<averagec<<" ("<<csymbol<<")"<<endl;
    cout<<"Ave. Pressure (AP)       : "<<averagep<<" ("<<psymbol<<")"<<endl;
    cout<<"Probability of Rain (%)  : "<<rain<<endl;
    cout<<rain1<<endl;
    cout<<rain2<<endl;
    cout<<rain3<<endl;
    cout<<endl;
  }
}

//Function to safely deallocate memory 
void safelyDeallocateMemory(int userRows, int userColumns, int xrangebegin)
{
  if(userColumns+4<=0)
  {
    return;
  }
  if(userRows%2==0)
  {
    for (int i =userRows+3;i>xrangebegin;i--)
    {
      delete[] array2D[i];
    }
  }
  else
  {
    for (int i =userRows+4;i>xrangebegin;i--)
    {
      delete[] array2D[i];
    }
  }
  delete[] array2D;
}
