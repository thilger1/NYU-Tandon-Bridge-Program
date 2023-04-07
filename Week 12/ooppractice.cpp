#include <iostream>
#include <string>
using namespace std;

class Money {
private:
    long all_cents;
public:
    Money(long dollars, int cents) {
        int d = dollars * 100;
        if (d < 0)
            all_cents = d - cents;
        else
            all_cents = d + cents;
    }
    //Initializes the object so its value represents an amount with
    //the dollars and cents given by the arguments. If the amount
    //is negative, then both dollars and cents should be negative.
    Money(long dollars) {
        all_cents = dollars * 100;
    }
    //Initializes the object so its value represents $dollars.00.
    Money() {
        all_cents = 0;
    }
    //Initializes the object so its value represents $0.00.
    double get_value() const {
        return all_cents * 0.01;
    }
    //Returns the amount of money recorded in the data portion of the calling
    //object.
    friend Money operator +(const Money& amount1, const Money& amount2) {
        Money total;
        total.all_cents = amount1.all_cents + amount2.all_cents;
        return total;
    }
    //Returns the sum of the values of amount1 and amount2.
    friend Money operator -(const Money& amount1, const Money& amount2) {
        Money total;
        total.all_cents = amount1.all_cents - amount2.all_cents;
        return total;
    }
    //Returns amount1 minus amount2.
    friend Money operator -(const Money& amount);
    //Returns the negative of the value of amount.
    friend bool operator ==(const Money& amount1, const Money& amount2);
    //Returns true if amount1 and amount2 have the same value; false otherwise.
    friend bool operator <(const Money& amount1, const Money& amount2);
    //Returns true if amount1 is less than amount2; false otherwise.
    friend istream& operator >>(istream& ins, Money& amount);
    //Overloads the >> operator so it can be used to input values of type
    //Money. Notation for inputting negative amounts is as in − $100.00.
    //Precondition: If ins is a file input stream, then ins has already been
    //connected to a file.
    friend ostream& operator <<(ostream& outs, const Money& amount);
    //Overloads the << operator so it can be used to output values of type
    //Money. Precedes each output value of type Money with a dollar sign.
    //Precondition: If outs is a file output stream, then outs has already been
    //connected to a file.

};

int main () {
    Money amount;
    cout<<amount.get_value()<<endl;
    return 0;
}