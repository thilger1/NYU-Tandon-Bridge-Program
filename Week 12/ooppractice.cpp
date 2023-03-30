#include <iostream>
#include <string>
using namespace std;

class AbstractEmployee {
    virtual void AskForPromotion() = 0;
};

class Employee:AbstractEmployee {
private:
    string Name;
    string Company;
    int Age;
public:
    void setName(string name) {
        Name = name;
    }
    string getName() {
        return Name;
    }

    void setCompany(string company) {
        Company = company;
    }
    string getCompany() {
        return Company;
    }

    void setAge(int age) {
        if (age >= 18)
            Age = age;
    }
    int getAge() {
        return Age;
    }
    void IntroduceYourself() {
        cout<<"Name: " << Name <<endl;
        cout<<"Company: " << Company <<endl;
        cout<<"Age: " << Age <<endl;
    }
    Employee(string name, string company, int age) {
        Name = name;
        Company =company;
        Age=age;
    }
    void AskForPromotion() {
        if(Age > 30)
            cout<< Name <<" got promoted!" << endl;
        else
            cout<< Name << ", sorry no promotion for you!" <<endl;
    }
};

class Developer: Employee{
public:
    string FavProgrammingLanguage;
    Developer(string name, string company, int age, string favProgrammingLanguage)
        :Employee(name, company, age)
    {
        FavProgrammingLanguage = favProgrammingLanguage;
    }
    void FixBug() {
        cout<<getName() <<" fixed bug using "<< FavProgrammingLanguage <<endl;
    }

};


int main() {

    Employee employee1 = Employee("Ted", "Kepler", 26);
    Employee employee2 = Employee("John", "Amazon", 35);

    employee1.AskForPromotion();
    employee2.AskForPromotion();
    Developer t = Developer("Ted", "Kepler", 26, "C++");
    t.FixBug();
}

