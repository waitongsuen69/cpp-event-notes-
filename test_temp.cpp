// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include<time.h>
using namespace std;



#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
 
/**
 * I/O
 */
#define output(value) cout << value << endl
#define error(errorString) cout << RED << errorString << RESET << endl
#define info(infoString) cout << CYAN << infoString << RESET << endl
#define success(successString) cout << GREEN << successString << RESET << endl
#define multiple(multiplestring) cout<< MAGENTA << multiplestring << RESET << endl


string force_enter(){
    string enter;
    int count = 0;
    while(enter.empty()){
        if(count != 0){
            cout<<RED<<"Invalid input!!! Write something!!!"<<RESET<<endl;
        }
        getline(cin, enter);
        count++;
    }
    return enter;
}

void  add_event(){
    string a,b,c,date;
    cout<<YELLOW<<"Please enter the name of the event."<<RESET<<endl;
    a = force_enter();
    cout<<YELLOW<<"Please enter the person for this event."<<RESET<<endl;
    b = force_enter();
    cout<<YELLOW<<"Please enter the date of the event."<<RESET<<endl;
    // getline(cin,date);
    cout<<YELLOW<<"Please enter any description."<<RESET<<endl;
    getline(cin,c);
    time_t t = time(NULL);
    bool d = false;
    // Object the_event = Object(a,t,b,c,d);
    // return the_event;
    cout<<a<<endl<<b<<endl<<c<<endl;
}

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

  add_event();
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