#ifndef OBJECT
#define OBJECT


#include<string>
#include<time.h>
using namespace std;
class Object{
public:
    Object(string a,time_t t,string b,string c);
    void show();
    ~Object();

    string events;
    time_t time;
    string person;
    string description;
    bool done;
};

#endif