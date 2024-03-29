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
    friend Money operator -(const Money& amount) {
        Money negative;
        negative.all_cents = -(amount.all_cents);
        return negative;
    }
    //Returns the negative of the value of amount.
    friend bool operator ==(const Money& amount1, const Money& amount2) {
        if (amount1.all_cents == amount2.all_cents)
            return true;
        else
            return false;
    }
    //Returns true if amount1 and amount2 have the same value; false otherwise.
    friend bool operator <(const Money& amount1, const Money& amount2) {
        if (amount1.all_cents < amount2.all_cents)
            return true;
        else
            return false;
    }

    //Returns true if amount1 is less than amount2; false otherwise.
    friend istream& operator >>(istream& ins, Money& amount) {
        char first_char, decimal;
        double dollars;
        int cents;
        bool negative;
        ins >> first_char;
        if (first_char == '-')
            negative = true;
        if (first_char != '-' || first_char != '$') {
            cout<<"Please enter your dollar amount starting with a $"<<endl;
        }
        else
            negative = false;
        
        ins >> dollars >> decimal >> cents;

        if (negative)
            amount.all_cents = -(dollars * 100 + cents);
        else    
            amount.all_cents = dollars * 100 + cents;
        return ins;
    }
    //Overloads the >> operator so it can be used to input values of type
    //Money. Notation for inputting negative amounts is as in − $100.00.
    //Precondition: If ins is a file input stream, then ins has already been
    //connected to a file.
    friend ostream& operator << (ostream& outs, const Money& amount) {
        int dollars, cents;
        
        dollars = amount.all_cents / 100;
        cents = amount.all_cents % 100;
        if (amount < 0)
            cout<<"-$"<<-(dollars)<<"."<<-(cents);
        else
            cout<<"$"<<dollars<<"."<<cents;
        return outs;
    }
    //Overloads the << operator so it can be used to output values of type
    //Money. Precedes each output value of type Money with a dollar sign.
    //Precondition: If outs is a file output stream, then outs has already been
    //connected to a file.

};

class Check {
private:
    int check_num;
    Money check_amount;
    bool check_cashed;
public:
    Check (int num = 0, Money amount = 0, bool cashed = 0) {
        check_num = num;
        check_amount = amount;
        check_cashed = cashed;
    }

    void setNum(int num) {
        check_num = num;
    }
    void setAmount(Money amount) {
        check_amount = amount;
    }
    Money getAmount() {
        return check_amount;
    }
    //1 or 0
    void setCashed(int binary) {
        check_cashed = binary;
    }

};

void doubleArray(Check *& arr, int& size, int double_size) {
    Check* temp = new Check[double_size];
    for (int i = 0; i < size; i++) {
        temp[i] = arr[i];
    }

    delete[] arr;

    arr = temp;
    size = double_size;
}

void depositChecks() {
    int size = 10; //arbitrary starting size
    int counter = 0;
    Check* arr = new Check[size];
    bool more_checks = true;
    int check_num;
    Money check_amount;
    char check_cashed;
    cout<<"Please enter the following info for your checks. If you are done submitting info for your checks, submit '-1' as the check number"<<endl;

    while (more_checks) {
        cin>>check_num;
        //user stop
        if (check_num == -1) {
            more_checks = false;
            return
        }

        else {
            //array has reached size limit
            if (counter == size) {
                doubleArray(arr, size, size * 2);
            }
            else {
                Check new_check;
                new_check.setNum(check_num);

                //Check amount
                cout<<"\nPlease enter the check amount: ";
                cin>>check_amount;
                new_check.setAmount(check_amount);

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
        }
    delete[] arr;
    }
}

int main() {
    Check checker;
    cout<<checker.getAmount();
    return 0;
}



//stage 1
//read in from checks: number, amount (type money), and whether or not cashed (1/0)
//check array to store them, reads in this info from console

//stage 2
//second array to hold bank deposits
//new account balance is old, plus all deposits, minus checks cashed
//outputs total of checks cashed, total of deposits, new balanace, difference between what bank said it should be
