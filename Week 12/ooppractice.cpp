#include <iostream>
using std::string;

class Employee {
    public:
    //semicolon belongs at the end of program
    //everything within class is private by default
    string Name;
    string Company;
    int Age;

    void IntroduceYourself() {
        std::cout << "Name - " << Name << std::endl;
        std::cout << "Company - " << Company << std::endl;
        std::cout << "Age - " << Age << std::endl;
    }

};

int main() {
    int number;
    Employee employee1;
    employee1.Name = "Ted";
    employee1.Company = "Kepler";
    employee1.Age = 26;
}