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
#define multiple(multiplestring) cout<< MAGENTA << multiplestring << RESET << endl

using namespace std;

Object::Object(string a,time_t t,string b,string c,bool d){
    events = a;
    time = t;
    person  =b;
    description = c;
    done = d;
}

void Object::show(){
    // system("clear");
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

    void Object::time_change(time_t n){
        time = n;
    }
    void Object::events_change(string n){
        events = n;
    }
    void Object::person_change(string n){
        person = n;
    }
    void Object::description_change(string n){
        description = n;
    }
    void Object::done_change(bool n){
        done = n;
    }

// void Object::edit(){
//     cout<<BOLDBLUE<<"Now you are editing:"<<RESET<<events<<endl;
//     multiple("1: Change events name");
//     multiple("2: Change events person");
//     multiple("3: Change events description");
//     multiple("4: Change events  statement");
//     multiple("5: Change time");
//     multiple("6: Quit");
//     int choice;
//     cin >> choice;
//     system("clear");
//     switch (choice) {
//         case 1:
//             cout<<BLUE<<"Current event name :"<<RESET<<events<<endl;
//             events = force_enter();
//             break;
//         case 2:
//             cout<<BLUE<<"Current person :"<<RESET<<person<<endl;
//             person = force_enter();
//             break;
//         case 3:
//             cout<<BLUE<<"Current description :"<<RESET<<description<<endl;
//             description = force_enter();
//             break;
//         case 4:
//             cout<<BLUE<<"Current state :"<<RESET;
//             if(done){ cout<<"completed"<<endl; 
//             }else {cout<<"not completed"<<endl;}
//             cout<<BLUE<<"1: completed"<<endl<<"0:not completed"<<RESET<<endl;
//             cin>>done;
//             break;
//         case 5:
//             cout<<BLUE<<"Current time :"<<RESET<<endl;
//             time = time_enter();
//             break;
//         case 6:
            
//             break;
//         default:
//             error("invalid input");
//     }
// }

Object::~Object(){

}