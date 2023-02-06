#include <iostream>
using namespace std;

int main(){

    int john_days, john_hours, john_minutes, bill_days, bill_hours, bill_minutes;
    const int MINUTES_IN_HOUR = 60;
    const int HOURS_IN_DAY = 24;

    cout<<"Please enter the number of days that John has worked: ";
    cin>>john_days;
    cout<<"Please enter the number of hours that John has worked: ";
    cin>>john_hours;
    cout<<"Please enter the number of minutes that John has worked: ";
    cin>>john_minutes;

    cout<<"Please enter the number of days that Bill has worked: ";
    cin>>bill_days;
    cout<<"Please enter the number of hours that Bill has worked: ";
    cin>>bill_hours;
    cout<<"Please enter the number of minutes that Bill has worked: ";
    cin>>bill_minutes;

    int total_days = john_days + bill_days;
    int total_hours = john_hours + bill_hours;
    int total_minutes = john_minutes + bill_minutes;

    int additional_hours = total_minutes / MINUTES_IN_HOUR;
    total_hours = total_hours + additional_hours;
    total_minutes = total_minutes % MINUTES_IN_HOUR;
    
    int additional_days = total_hours / HOURS_IN_DAY;
    total_days = total_days + additional_days;
    total_hours = total_hours % HOURS_IN_DAY;
    
    cout<<"The total time both of them worked together is: "<<total_days<<" days, "<<total_hours<<" hours and "<<total_minutes<<" minutes."<<endl;
    return 0;
}