#include <iostream>
using namespace std;

class Money {
public:
    friend Money add(Money amount1, Money amount2);
    friend bool equal(Money amount1, Money amount2);
    Money(long dollars, int cents);
    Money (long dollars);
    Money();
    double get_value();
    void input(istream& ins);
    void output(ostream& outs);
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