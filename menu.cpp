#include "shameem.h"
using namespace std;

/* Function to display menu */
void displayMenu()
{
  cout<<"Student ID    : 7364283"<<endl;
  cout<<"Student Name  : Shaik Dawood Shameem Ahamed"<<endl;
  cout<<"-------------------------------------------"<<endl;
  cout<<"Welcome to Weather Information Processing System!"<<endl;
  cout<<endl;
  cout<<setw(8)<<left<<"1)"<<"Read in and process a configuration file"<<endl;
  cout<<setw(8)<<left<<"2)"<<"Display City Map"<<endl;
  cout<<setw(8)<<left<<"3)"<<"Display cloud coverage map (cloudiness index)"<<endl;
  cout<<setw(8)<<left<<"4)"<<"Display cloud coverage map (LMH symbols)"<<endl;
  cout<<setw(8)<<left<<"5)"<<"Display atmospheric pressure map (pressure index)"<<endl;
  cout<<setw(8)<<left<<"6)"<<"Display atmospheric pressure map (LMH symbols)"<<endl;
  cout<<setw(8)<<left<<"7)"<<"Show weather forecast summary report"<<endl;
  cout<<setw(8)<<left<<"8)"<<"Quit"<<endl;
}