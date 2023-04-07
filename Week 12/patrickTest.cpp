#include<iostream>
using namespace std;

// Given Money Class
class Money{
    public:
        friend Money operator+(const Money& amount1, const Money& amount2);
        friend Money operator-(const Money& amount1, const Money& amount2);
        friend Money operator-(const Money& amount);
        friend bool operator==(const Money& amount1, const Money& amount2);
        friend bool operator<(const Money& amount1, const Money& amount2);
        Money(long dollars, int cents) {all_cents = dollars * 100 + cents;};
        Money(long dollars) {all_cents = dollars *100;};
        Money() {all_cents = 0;};
        double get_value() const {return all_cents;};
        friend istream& operator>>(istream& ins, Money& amount);
        friend ostream& operator<<(ostream& outs, const Money& amount);
    private:
        long all_cents;
};

// Friend Operator Definition
Money operator+(const Money& amount1, const Money& amount2) {return Money(0, amount1.get_value() + amount2.get_value());}
Money operator-(const Money& amount1, const Money& amount2) {return Money(0, amount1.get_value() - amount2.get_value());}
Money operator-(const Money& amount) {return Money(0, -amount.get_value());}
bool operator==(const Money& amount1, const Money& amount2) {return amount1.get_value() == amount2.get_value();}
bool operator<(const Money& amount1, const Money& amount2) {return amount2.get_value() < amount1.get_value();}
istream& operator>>(istream& ins, Money& amount) {
    char DOLLAR_SIGN = '$';
    char DOT = '.';
    long dollars;
    int cents;
    ins >> dollars >> DOT >> cents;
    if (DOT != '.') {cents = 0;}
    amount.all_cents = dollars*100+cents;
    return ins;
}
ostream& operator<<(ostream& outs, const Money& amount) {
    long dollars;
    int cents;
    dollars = amount.all_cents/100;
    cents = amount.all_cents%100;
    outs <<'$'<<dollars<<'.';
    if(cents < 10) {
        outs<<'0';
    }
    outs << cents;
    return outs;
}

// Defined Check class
class Check:public Money {
    private:
        int checkNum;
        Money checkAmt;
        bool isCashed;
    public:
        // Constructors
        Check(int c = 0, Money a = 0, bool i = 0) {
            setCheckNum(c);
            checkAmt = a;
            setIsCashed(i);
        }

        // Mutators
        void setCheckNum(int num) {if(num > 0) {checkNum = num;}}
        void setIsCashed(bool c) {isCashed = c;}

        // Accessors
        int getCheckNum() {return checkNum;}
        bool getIsCashed() {return isCashed;}
};

int main() {

    // READING IN CHECKS
    int checkNum = 0;
    Money checkAmt = Money();
    Money totalOfChecksCashed = Money();
    Money totalOfChecksNotCashed = Money();
    bool isCashed;
    Check* checks = new Check[1];
    int checksSize = 0;

    cout<<"Please input the check number, check amount (formatted as 1000.00 for one-thousand dollars), and whether or not the check has been cashed (1 = Yes, 0 = No), each on a separate line."<<endl<<"When you are complete, input -1 to complete check input."<<endl;
    for(int i = 0; checkNum != -1; i++) {
        // Reading in Check public variables
        cin>>checkNum;
        if (checkNum != -1) {
            checksSize++;
            cin>>checkAmt;
            cin>>isCashed;
            
            // Committing them to checks array
            checks[i] = Check(checkNum, checkAmt, isCashed); // need to make this dynamic / changeable

            // Enlarging the array
            Check* temp = new Check[checksSize + 1];
            for (int j = 0; j < checksSize; j++) {
                temp[j] = checks[j];
            }
            delete[] checks;
            checks = temp;
            temp = nullptr;
            // Incrementing to enlarge the array size
            cout<<"Thank you! Your check #"<<checkNum<<" has been recorded."<<endl<<"Please input your next check or input -1 to complete check input."<<endl;
            if (isCashed == 0) {
                totalOfChecksNotCashed = totalOfChecksNotCashed + checkAmt;
            } else {
                totalOfChecksCashed = totalOfChecksCashed + checkAmt;
            }
        }
    }

    // READING IN DEPOSITS
    Money depositAmt = Money();
    Money totalOfDeposits = Money();
    Money* deposits = new Money[1];
    int depositsSize = 0;

    cout<<"Please input the deposit amount(s), each on a new line. Format them as 1000.00 to represent one-thousand dollars."<<endl<<"When you are complete, input -1.00 to complete deposit input."<<endl;
    for(int i = 0; depositAmt.get_value() != -100; i++) { // need to get conditional statement right
        cin>>depositAmt;
        if(depositAmt.get_value() != -100) { // need to get conditional statement right
            depositsSize++;
            deposits[i] = depositAmt;
            Money* temp = new Money[depositsSize+1];
            for (int j = 0; j < depositsSize; j++) {
                temp[j] = deposits[j];
            }
            delete[] deposits;
            deposits = temp;
            temp = nullptr;
            totalOfDeposits = totalOfDeposits + depositAmt;
        }
    }

    // READING IN ACCOUNT OLD/NEW ACCOUNT BALANCES
    Money oldAccBal = Money();
    Money newAccBalPersonal = Money(); 
    Money newAccBalBank = Money();
    cout<<"What is the old account balance?"<<endl;
    cin>>oldAccBal;
    cout<<"What is your recorded new account balance?"<<endl;
    cin>>newAccBalPersonal;

    newAccBalBank = oldAccBal + totalOfDeposits - totalOfChecksCashed;

    // OUTPUTS
    cout<<"The total of your checks cashed is "<<totalOfChecksCashed<<"."<<endl;
    cout<<"The total of your deposits is "<<totalOfDeposits<<"."<<endl;
    cout<<"The banks record of your new account balance is "<<newAccBalBank<<", which differs from your personal new account balance by ";
    if(newAccBalPersonal < newAccBalBank) {
        cout<<newAccBalPersonal-newAccBalBank;
    } else {
        cout<<newAccBalBank-newAccBalPersonal;
    }
    cout<<"."<<endl;
    cout<<"The checks cashed since the last time you balanced your checkbook include:"<<endl;
    for(int i = 0; i < checksSize; i++) {
        if(checks[i].getIsCashed() == 1) {
            cout<<checks[i].getCheckNum()<<endl;
        }
    }
    cout<<"The checks not yet cashed include:"<<endl;
    for(int i = 0; i < checksSize; i++) {
        if(checks[i].getIsCashed() == 0) {
            cout<<checks[i].getCheckNum()<<endl;
        }
    }
}