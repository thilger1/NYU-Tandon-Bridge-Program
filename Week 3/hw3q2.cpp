#include <iostream>
#include <string.h>
using namespace std;

main(){

    string name;
    string status;
    int grad_year, curr_year;

    cout<<"Please enter your name: ";
    cin>>name;
    cout<<"Please enter your grad year: ";
    cin>>grad_year;
    cout<<"Please enter current year: ";
    cin>>curr_year;

    int difference = grad_year - curr_year;
    if (difference <= 0){
        cout<<name<<", you are Graduated"<<endl;
    }
    else if (difference == 1){
        cout<<name<<", you are a Senior"<<endl;
    }
    else if (difference == 2){
        cout<<name<<", you are a Junior"<<endl;
    }
    else if (difference == 3){
        cout<<name<<", you are a Sophomore"<<endl;
    }
    else if (difference == 4){
        cout<<name<<", you are a Freshman"<<endl;
    }
    else
        cout<<name<<", you are not in college yet"<<endl;
    return 0;
}