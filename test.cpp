#include<iostream>
#include<time.h>
#include<fstream>
#include<vector>
#include"object.h"
#include<string>

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

        file<<obj.events+"\n"<<obj.time<<"\n"<<obj.person+"\n"<<obj.description+"\n"<<obj.done<<"\n"<<"\n";

    }
    file.close();
}
vector<Object> get_data(){
    vector<Object> list;
    string line;
    ifstream file ("test.txt");
    if(file.is_open()){
        while(getline(file,line)){
            string b,c,x,d;
            getline(file,x);

            long long time_ll = stoll(x,nullptr,10);
            time_t t = time_ll;

            getline(file,b);
            getline(file,c);
            getline(file,d);
            list.push_back(Object(line,t,b,c,stoi(d)));
            getline(file,line);



        }
    }
    return list;
}

int main(){
    vector<Object> list = get_data();
    // vector<Object> list;
    string a = "events name";
    time_t t = time(NULL);
    string b = "karen";
    string c = "this is the war between man and karen";
    bool d = false;
    Object the_event = Object(a,t,b,c,d);
    list.push_back(the_event);
    list.push_back(the_event);
    the_event.show();
    data_write_in(list);
    return 0;
}