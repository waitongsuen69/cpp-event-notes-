#include<iostream>
#include<time.h>
#include<fstream>
#include<vector>
#include"object.h"

using namespace std;

void data_write_in(vector<Object> data_list){
    ofstream file;
    file.open("test.txt");
    for(auto & obj : data_list){
        // int tf = (obj.done)? 1:0;
        // string input = obj.events+" "+ctime(&obj.time)+" "+obj.person+" "+obj.description+" "+"\n";
        // file<<input;

        // file<<obj.events+"\n";
        // file<<ctime(&obj.time);
        // file<<obj.person+"\n";
        // file<<obj.description+"\n";
        // file<<obj.done;
        // file<<"\n"<<"\n";

        file<<obj.events+"\n"<<ctime(&obj.time)<<obj.person+"\n"<<obj.description+"\n"<<obj.done<<"\n"<<"\n";

    }
    file.close();
}

int main(){
    string a = "events name";
    time_t t = time(NULL);
    string b = "karen";
    string c = "this is the war between man and karen";
    Object the_event = Object(a,t,b,c);
    vector<Object> list;
    list.push_back(the_event);
    list.push_back(the_event);
    the_event.show();
    data_write_in(list);
    return 0;
}