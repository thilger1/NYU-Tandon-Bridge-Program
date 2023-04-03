#include <iostream>
using namespace std;

class Money {
public:
    friend Money add(Money amount1, Money amount2);
    //Precondition: amount1 and amount2 have been given values.
    //Returns the sum of the values of amount1 and amount2.
    friend bool equal(Money amount1, Money amount2);
    //Precondition: amount1 and amount2 have been given values.
    //Returns true if the amount1 and amount2 have the same value;
    //otherwise, returns false.
    Money(long dollars, int cents);
    //Initializes the object so its value represents an amount with the
    //dollars and cents given by the arguments. If the amount is negative,
    //then both dollars and cents must be negative.
    Money (long dollars);
    //Initializes the object so its value represents $dollars.00.
    Money();
    //Initializes the object so its value represents $0.00.
    double get_value();
    //Precondition: The calling object has been given a value.
    //Returns the amount of money recorded in the data of the calling object
    void input(istream& ins);
    //Precondition: If ins is a file input stream, then ins has already been
    //connected to a file. An amount of money, including a dollar sign, has been
    //entered in the input stream ins. Notation for negative amounts is -$100.00.
    //Postcondition: The value of the calling object has been set to
    //the amount of money read from the input stream ins.
    void output(ostream& outs);
    //Precondition: If outs is a file output stream, then outs has already been
    //connected to a file.
    //Postcondition: A dollar sign and the amount of money recorded
   //in the calling object have been sent to the output stream outs.
private:
    long all_cents;
};

class Check {
private:
    int check_number;
    double amount;
    bool is_cashed;

};

int main() {
    return 0;
}