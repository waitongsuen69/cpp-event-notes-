#include"object.h"
#include<iostream>
#include<stdlib.h>
#define RESET   "\033[0m"
#define BOLDGREEN   "\033[1m\033[32m"

using namespace std;

Object::Object(string a,time_t t,string b,string c,bool d){
    events = a;
    time = t;
    person  =b;
    description = c;
    done = d;
}

void Object::show(){
    system("clear");
    cout<<"Event name:"<<endl;
    string state;
    if(done){
        state = "done";
    }else{
        state = "uncomplete";
    }
    cout<< BOLDGREEN << events << RESET<< "("<<state<<")"<<endl;
    cout<<"Time:"<<endl;
    cout<< BOLDGREEN <<  asctime(gmtime(&time)) << RESET;
    cout<<"Person:"<<endl;
    cout<< BOLDGREEN << person << RESET<<endl;
    cout<<"Description:"<<endl;
    cout<< BOLDGREEN << description<< RESET<<endl;
}

Object::~Object(){

}