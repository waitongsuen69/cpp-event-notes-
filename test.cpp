#include<iostream>
#include<stdlib.h>

//for wait
#include <unistd.h>

#include<time.h>
#include<ctime>

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

//I/O of data from/to txt file 
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

//user function page
    // multiple("1: Drop new events.");
    // multiple("2: Check all events:");
    // multiple("3: Search event:");
    // multiple("4: edit events");
    // multiple("0: quit system");
int user_choose(){
    // system("clear");
    cout<<BOLDBLUE << "Welcome to the cpp events notes!!!"<<RESET<<endl;
    cout<<"What you want to drop down today mate!"<<endl;
    multiple("1: Drop new events.");
    multiple("2: Check all events:");
    multiple("3: Search event:");
    multiple("4: edit events");
    multiple("0: quit system");
    string input;
    cin>> input;

    while(input != ""){
        while(input.length() > 1 || (input[0] < 48 && input[0] > 54)   ){
                system("clear");    
                error("INVALID INPUT!");
                cout<<"Example:"<<endl<<"Please enter [4] and press enter if you want to quit."<<endl;
                cout<<"What you want to drop down today mate!"<<endl;
                multiple("1: Drop new events.");
                multiple("2: Check all events:");
                multiple("3: Search event:");
                multiple("4: edit events.");
                multiple("0: quit system");
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
            case 0:
            return 0;
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
    return -1;
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
time_t time_enter(){
    string input;
    int count =0;
    while(input.size() != 16){
      cout<< YELLOW<<"Please enter your time in format:"<<endl<<"hh:mm/dd/mm/year"<<RESET<<endl;
      if(count!=0){
          cout<<RED<<"Invalid input!!! please follow the format!!!"<<RESET<<endl;
      }
      getline(cin, input); 
      count++ ;
    }
    int hour,minute,day,month,year;
    hour = stoi(input.substr(0,2),nullptr,10);
    minute = stoi(input.substr(3,2),nullptr,10);
    day =stoi(input.substr(6,2),nullptr,10);
    month = stoi(input.substr(9,2),nullptr,10);
    year = stoi(input.substr(12,4),nullptr,10);
    tm* time_ptr ;
    time_t result;
    time(&result);
    time_ptr = localtime(&result);
    time_ptr->tm_hour = hour;
    time_ptr->tm_min = minute;
    time_ptr->tm_mday = day;
    time_ptr->tm_mon = month - 1;
    time_ptr->tm_year = year - 1900;
    result = mktime(time_ptr);
    // cout<<asctime(gmtime(&result));
    return result;

}
Object add_event(){
    string a,b,c,date;
    cout<<YELLOW<<"Please enter the name of the event."<<RESET<<endl;
    a = force_enter();
    cout<<YELLOW<<"Please enter the person for this event."<<RESET<<endl;
    b = force_enter();
    cout<<YELLOW<<"Please enter the date of the event."<<RESET<<endl;
    time_t t = time_enter();
    cout<<YELLOW<<"Please enter any description."<<RESET<<endl;
    getline(cin,c);
    bool d = false;
    // Object the_event = Object(a,t,b,c,d);
    return Object(a,t,b,c,d);
}

//     multiple("2: Check all events:");
void show_all_events(vector<Object> list){
    system("clear");
    cout<<BOLDBLUE << "Event list:"<<RESET<<endl;
    cout<<"Number      event name"<<endl;
    for(int i=0;i<list.size();i++){
        cout<<BOLDBLUE<<(i+1)<<"           "<<MAGENTA<<list[i].events<<RESET<<endl;

    }
    cout<<BOLDBLUE<<"Enter the number of events you want to check in detail."<<RESET<<endl;
    cout<<BLUE<<"[-1] Back to menu."<<RESET<<endl;
    int ui;//user input
    cin>>ui;
    if(ui == -1){
        return;
    }else if(ui >0 && ui <= list.size()){
        system("clear");
        list[ui-1].show();
        cout<<BLUE<<"[0] quit event checking             [1] continue check event"<<RESET<<endl;
        cin>>ui;
        if(ui == 0){
            return;
        } else if (ui == 1){
            show_all_events(list);
        }else {
            cout<<RED<<"INVALID INPUT,QUIT"<<RESET<<endl;
        }
    }else{
        cout<<RED<<"INVALID INPUT,QUIT"<<RESET<<endl;
    }

}

//     multiple("3: Search event:");

//      4: edit events
vector<Object> change_information(vector<Object> list){
    //list out event to pick 
    system("clear");
    cout<<BOLDBLUE << "Event list:"<<RESET<<endl;
    cout<<"Number      event name"<<endl;
    for(int i=0;i<list.size();i++){
        cout<<BOLDBLUE<<(i+1)<<"           "<<MAGENTA<<list[i].events<<RESET<<endl;

    }
    cout<<BOLDBLUE<<"Enter the number of events you want to edit."<<RESET<<endl;
    cout<<BLUE<<"[-1] Back to menu."<<RESET<<endl;
    int ui;//user input
    cin>>ui;
    if(ui == -1){
        return list;
    }else if(ui >0 && ui <= list.size()){
        system("clear");
        list[ui-1].show();  //user pick
    }else {
        error("INVALID INPUT!");
        return list;
    }
    multiple("1: Change events name");
    multiple("2: Change events person");
    multiple("3: Change events description");
    multiple("4: Change events  statement");
    multiple("5: Change time");
    multiple("6: Quit");
    int choice;
    cin >> choice;
    system("clear");
    switch (choice) {
        case 1:{
            cout<<BLUE<<"Current event name :"<<RESET<<list[ui-1].events<<endl;
            list[ui-1].events_change(force_enter());
            break;
        }
        case 2:{
            cout<<BLUE<<"Current person :"<<RESET<<list[ui-1].person<<endl;
            list[ui-1].person_change(force_enter());
            break;
        }
        case 3:{
            cout<<BLUE<<"Current description :"<<RESET<<list[ui-1].description<<endl;
            list[ui-1].description_change( force_enter());
            break;
        }
        case 4:{
            cout<<BLUE<<"Current state :"<<RESET;
            bool state = list[ui-1].done;
            if(state){ cout<<"completed"<<endl; 
            }else {cout<<"not completed"<<endl;}
            cout<<BLUE<<"1: completed"<<endl<<"0:not completed"<<RESET<<endl;
            cin>>state;
            list[ui-1].done_change(state);
            break;
        }
        case 5:{
            cout<<BLUE<<"Current time :"<<RESET<<endl;
            time_t t = time_enter();
            list[ui-1].time_change(t);
            break;
        }
        case 6:{
            return list;
            break;
        }
    }



    success("Success editing!!!");
    list[ui-1].show();
    return list;
}

int main(){
    // int choose = user_choose();
    vector<Object> list = get_data();
    // vector<Object> list;
    int choose = user_choose();
    while (choose != 0 && choose !=-1){
        if(choose == 1){
            //1: Drop new events.
            cout<<"Now you are in:"<< BOLDBLUE << "Drop new events"<<RESET<<endl ;
            list.push_back(add_event());
            cout<<BOLDGREEN << "Success adding events"<<RESET<<endl;
            list.back().show();
            cout<<BLUE << "Back to menu in " ;
            for(int i=5; i>=1 ;i--){
                cout<<i<<" "<<endl;
                usleep(1000000);
            }
            cout<<RESET<<endl;



        }else if(choose == 2 ){
            //2: Check all events
            cout<<"Now you are in:"<< BOLDBLUE << "Drop new events"<<RESET<<endl ;
            show_all_events(list);


        
        }else if (choose == 4){
            //4: edit events
            list = change_information(list);
        cout<<BLUE << "Back to menu in " ;
            for(int i=5; i>=1 ;i--){
                cout<<i<<" "<<endl;
                usleep(1000000);
            }
            cout<<RESET<<endl;
        }
        choose = user_choose();
    }
    cout<<BOLDBLUE<<"Have a good day bra!"<<RESET << endl;

    return 0;
}

