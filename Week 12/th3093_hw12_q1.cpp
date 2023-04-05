#include <iostream>
using namespace std;

class Money {
public:
    friend Money operator +(const Money& amount1, const Money& amount2);
    //Returns the sum of the values of amount1 and amount2.
    friend Money operator -(const Money& amount1, const Money& amount2);
    //Returns amount1 minus amount2.
    friend Money operator -(const Money& amount);
    //Returns the negative of the value of amount.
    friend bool operator ==(const Money& amount1, const Money& amount2);
    //Returns true if amount1 and amount2 have the same value; false otherwise.
    friend bool operator <(const Money& amount1, const Money& amount2);
    //Returns true if amount1 is less than amount2; false otherwise.
    Money(long dollars, int cents);
    //Initializes the object so its value represents an amount with
    //the dollars and cents given by the arguments. If the amount
    //is negative, then both dollars and cents should be negative.
    Money(long dollars);
    //Initializes the object so its value represents $dollars.00.
    Money();
    //Initializes the object so its value represents $0.00.
    double get_value( ) const;
    //Returns the amount of money recorded in the data portion of the calling
    //object.
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
private:
    long all_cents
};

class Check {
private:
    int check_num;
    Money check_amount;
    int check_cashed;
public:
    void setNum(int num) {
        check_num = num;
    }
    void setAmount(Money amount) {
        check_amount = amount;
    }
    //1 or 0
    void setCashed(int binary) {
        check_cashed = binary;
    }

};

void depositChecks(Check arr[], int size) {
    int counter = 0;
    bool more_checks = true;
    int check_num;
    Money check_amount;
    char check_cashed;
    cout<<"Please enter the following info for your checks. If you are done submitting info for your checks, submit '0' as the check number"<<endl;

    //loops until user enters zero as check number to indicate loop stop
    while (more_checks) {

        //Check Number
        cout<<"Check number?: ";
        cin>>check_num;
        if (check_num != 0) {
            Check new_check;
            new_check.setNum(check_num);

            //Check amount
            cout<<"\nPlease enter the check amount: ";
            cin>>check_amount;
            new_check.setAmount(check_amount);

            //Check cashed
            cout<<"\nWas the check cashed? Y/N: ";
            cin>>check_cashed;
            if (check_cashed == 'Y') {
                new_check.setCashed(1);
            }
            if (check_cashed == 'N') {
                new_check.setCashed(0);
            }
            else {
                cout<<"I'm sorry, I didn't recognize that. Please enter 'Y' or 'N' next time." <<endl;
                return;
            }
            arr[counter++] = new_check;

        }
        else {
            more_checks = false;
            return;
        }
    }

}

const int ARBITRARY_SIZE = 5;
int main() {
    Check arr[ARBITRARY_SIZE];
    depositChecks(arr, ARBITRARY_SIZE);

    return 0;
}



//stage 1
//read in from checks: number, amount (type money), and whether or not cashed (1/0)
//check array to store them, reads in this info from console

//stage 2
//second array to hold bank deposits
//new account balance is old, plus all deposits, minus checks cashed
//outputs total of checks cashed, total of deposits, new balanace, difference between what bank said it should be
