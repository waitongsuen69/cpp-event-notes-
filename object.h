#ifndef OBJECT
#define OBJECT


#include<string>
#include<time.h>
using namespace std;
class Object{
public:
    
    Object(string a,time_t t,string b,string c,bool d );
    void show();
    void time_change(time_t n);
    void events_change(string n);
    void person_change(string n);
    void description_change(string n);
    void done_change(bool n);
    ~Object();

    string events;
    time_t time;
    string person;
    string description;
    bool done;
};

#endif