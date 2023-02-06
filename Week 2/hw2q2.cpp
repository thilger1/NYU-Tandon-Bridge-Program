#include <iostream>
using namespace std;

int main(){

    int dollars, cents, quarters, dimes, nickels, pennies;

    const int DOLLAR_VALUE = 100;
    cout<<"Please enter your amount in the format of dollars and cents separated by a space:"<<endl;
    cin>>dollars>>cents;

    int total = DOLLAR_VALUE * dollars + cents;
    const int QUARTER_VALUE = 25;
    const int DIME_VALUE = 10;
    const int NICKEL_VALUE = 5;

    quarters = total / QUARTER_VALUE;
    dimes = (cents % QUARTER_VALUE) / DIME_VALUE;
    nickels = (cents % QUARTER_VALUE % DIME_VALUE) / NICKEL_VALUE;
    pennies = (cents % NICKEL_VALUE);
    cout<<dollars<<" and "<<cents<<" cents are:\n";
    cout<<quarters<<" quarters, "<<dimes<<" dimes, "<<nickels<<" nickels and "<<pennies<<" pennies";
    return 0;
}