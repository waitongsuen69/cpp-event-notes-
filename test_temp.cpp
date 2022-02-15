// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include<time.h>
using namespace std;

int main () {
  time_t tim = time(NULL);
  long long tim_s = tim;
  cout<<tim_s<<endl;
  cout<<ctime(&tim)<<endl;

  string nt = "1644873886";
  long long nn_t = stoll(nt,nullptr,10);
  time_t nnt = nn_t;

  time_t n_t = tim;
  cout<<"new time is "<<ctime(&n_t)<<endl;
  cout<<"new new  time is "<<ctime(&nnt)<<endl;
  // string line;
  // ifstream myfile ("test.txt");
  // if (myfile.is_open())
  // {
  //   while ( getline (myfile,line) )
  //   {
  //     cout << line << endl;
  //   }
  //   myfile.close();
  // }

  // else cout << "Unable to open file"; 

  return 0  ;
}