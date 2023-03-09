#include <iostream>
#include <string>
using namespace std;

int main(){
    char colon;
    string day;
    int start, length, minutes;
    float total_cost;
    const float RATE_ONE = 0.4;
    const float RATE_TWO = 0.25;
    const float RATE_THREE = 0.15;
    cout<<"Please input the day of the week: ";
    cin>>day;
    cout<<"Please input the time that the call started: ";
    cin>>start >> colon >> minutes;
    cout<<"Please input the length of time of the call in minutes: ";
    cin>>length;
    
    if (day == "Mo" || day == "Tu" || day == "We" || day == "Th" || day == "Fr"){
        if (start >= 8 && start <= 18){
            total_cost = length * RATE_ONE;
        }
        else{
            total_cost = length * RATE_TWO;
        }
    }
    else if (day == "Sa" || day == "Su"){
        total_cost = length * RATE_THREE;
    }
    else{
        cout<<"Couldn't understand day"<<endl;
    }
    cout<<"Cost of call: $"<<total_cost<<endl;
    return 0;
}