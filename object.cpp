#include"object.h"
#include<iostream>
#include<stdlib.h>
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
    cout<< CYAN << events << RESET<< "("<<state<<")"<<endl;
    cout<<"Time:"<<endl;
    cout<< CYAN  <<  asctime(gmtime(&time)) << RESET;
    cout<<"Person:"<<endl;
    cout<< CYAN  << person << RESET<<endl;
    cout<<"Description:"<<endl;
    cout<< CYAN << description<< RESET<<endl;
}

Object::~Object(){

}