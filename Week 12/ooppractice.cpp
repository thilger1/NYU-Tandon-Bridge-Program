#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
    string Name;
    string Company;
    int Age;

    void IntroduceYourself() {
        cout<<"Name: " << Name <<endl;
        cout<<"Company: " << Company <<endl;
        cout<<"Age: " << Age <<endl;
    }
};

int main() {
    Employee employee1;
    employee1.Name = "Ted";
    employee1.Company = "Kepler";
    employee1.Age = 25;
    employee1.IntroduceYourself();

    Employee employee2;
    employee2.Name = "John";
    employee2.Company = "Amazon";
    employee2.Age = 35;
    employee2.IntroduceYourself();
}