#include <iostream>
using namespace std;

class Car {
private:
    double _height;
    double _weight;
    string _color;
    int _numOfWheels;
    int _year;

    Car(double weight){
        _weight = weight;
    }

};

int main() {
    Car chevy(15);
    Car tesla(10);

    cout << chevy.weight;

    return 0;
}