#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<fstream>
#include<vector>
#include"object.h"
#include<string>

#include <regex>
 
/**
 * Use namespace std
 */
using namespace std;
 
/**
 * Colors
 */
 
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

//color coding



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
        file.close();
    }
    return list;
}

int user_choose(){
    // system("clear");
    cout<<BOLDBLUE << "Welcome to the cpp events notes!!!"<<RESET<<endl;
    cout<<"What you want to drop down today mate!"<<endl;
    multiple("1: Drop new events.");
    multiple("2: Check all events:");
    multiple("3: Search event:");
    multiple("4: quit system");
    string input;
    cin>> input;

    while(input != ""){
        while(input.length() > 1 || (input[0] < 49 && input[0] > 54)   ){
                system("clear");    
                error("INVALID INPUT!");
                cout<<"Example:"<<endl<<"Please enter [4] and press enter if you want to quit."<<endl;
                cout<<"What you want to drop down today mate!"<<endl;
                multiple("1: Drop new events.");
                multiple("2: Check all events:");
                multiple("3: Search event:");
                multiple("4: quit system");
                cin>>input;

        }
        int user_input = stoi(input);
        switch(user_input){
            case 1:
            return 1;
            break;
            case 2:
            return 2;
            break;
            case 3:
            return 3;
            break;
            case 4:
            return 4;
            break;
            default:
                system("clear");
                error("INVALID INPUT!");
                cout<<"Example:"<<endl<<"Please enter [4] and press enter if you want to quit."<<endl;
                cout<<"What you want to drop down today mate!"<<endl;
                multiple("1: Drop new events.");
                multiple("2: Check all events:");
                multiple("3: Search event:");
                multiple("4: quit system");
                cin>>input;
        }
    }
    return 0;
}

//  multiple("1: Drop new events.");
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

Object add_event(){
    string a,b,c,date;
    cout<<YELLOW<<"Please enter the name of the event."<<RESET<<endl;
    a = force_enter();
    cout<<YELLOW<<"Please enter the person for this event."<<RESET<<endl;
    b = force_enter();
    cout<<YELLOW<<"Please enter the date of the event."<<RESET<<endl;
    getline(cin,date);
    cout<<YELLOW<<"Please enter any description."<<RESET<<endl;
    getline(cin,c);
    time_t t = time(NULL);
    bool d = false;
    // Object the_event = Object(a,t,b,c,d);
    return Object(a,t,b,c,d);
}
//     multiple("2: Check all events:");
//     multiple("3: Search event:");


int main(){
    int choose = user_choose();
    while (choose != 4){
        if(choose == 1){
            cout<<"Now you are in:"<< BOLDBLUE << "Drop new events"<<RESET<<endl ;
        }
        choose = user_choose();
    }
    cout<<BOLDBLUE<<"Have a good day bra!"<<RESET << endl;
    // vector<Object> list = get_data();
    // string a = "events name";
    // time_t t = time(NULL);
    // string b = "karen";
    // string c = "this is the war between man and karen";
    // bool d = false;
    // Object the_event = Object(a,t,b,c,d);
    // list.push_back(the_event);
    // the_event.show();
    // data_write_in(list);
    return 0;
}