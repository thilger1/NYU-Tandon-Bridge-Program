#include <iostream>
using namespace std;

class Car {
private:
    double _height;
    double _weight;
    string _color;
    int _numOfWheels;
    int _year;
public:
    Car(){
        _weight = 0;
    }
    Car(double weight){
        _weight = weight;
    }

    double getWeight() {
        return _weight;
    }

    void displayWeight() {
        cout<< "Your car's weight is " << _weight << " tons";
    }

};

int main() {
    Car chevy(15);
    Car tesla(10);

    chevy.getWeight();
    chevy.displayWeight();
    return 0;
}