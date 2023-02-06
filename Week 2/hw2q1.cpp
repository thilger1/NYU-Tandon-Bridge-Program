#include <iostream>
using namespace std;

int main(){

    int total, dollars, cents, quarters, dimes, nickels, pennies;
    cout<<"Please enter the number of coins:"<<endl;

    const int QUARTER_VALUE = 25;
    cout<<"# of quarters:"<<endl;
    cin>>quarters;

    const int DIME_VALUE = 10;
    cout<<"# of dimes:"<<endl;
    cin>>dimes;

    const int NICKEL_VALUE = 5;
    cout<<"# of nickels:"<<endl;
    cin>>nickels;

    const int DOLLAR_VALUE = 100;
    cout<<"# of pennies:"<<endl;
    cin>>pennies;

    total = (quarters * QUARTER_VALUE) + (dimes * DIME_VALUE) + (nickels * NICKEL_VALUE) + (pennies);
    dollars = total / DOLLAR_VALUE;
    cents = total % DOLLAR_VALUE;
    cout << "The total is " << dollars << " dollars and " << cents << " cents" << endl;
    return 0;
}