#include <iostream>
using namespace std;

main(){
    float price_one, price_two;
    float rate;
    char card;
    cout<<"Enter price of first item: ";
    cin>>price_one;
    cout<<"Enter the price of second item: ";
    cin>>price_two;
    cout<<"Does customer have a club card? (Y/N): ";
    cin>>card;
    cout<<"Enter tax rate, e.g. 5.5 for 5.5% tax: ";
    cin>>rate;
    rate = (100 + rate) / 100;

    float base = price_one + price_two;
    cout<<"Base price: "<<base<<endl;
    if (price_one > price_two)
        price_two /= 2;
    else
        price_one /= 2;
    float discounted = price_one + price_two;

    if (card == 'Y' || card == 'y')
        discounted *= .9;
    cout<<"Price after discounts: "<<discounted<<endl;
    float with_tax = rate * discounted;
    cout<<"Total price: "<<with_tax<<endl;
    return 0;
}