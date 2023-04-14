#include <iostream>
#include <string.h>
using namespace std;

class Shape {
public:
    void virtual getArea() {
        cout<<"Area of shape: "<<endl;
    }
};

class Circle : public Shape {
private:
    int Radius;
public:
    Circle() : Radius(0) {};
    Circle(int radius) : Radius(radius) {};
    void getArea() {
        cout<<"Area of circle: "<< (Radius * Radius) * 3.14 << endl;
    }
};

class Rectangle : public Shape {
private:
    int Height;
    int Width;
public:
    Rectangle() : Height(0), Width(0) {};
    Rectangle(int height, int width) : Height(height), Width(width) {};
    void getArea() {
        cout<<"Area of rectangle: "<< (Height * Width)<<endl;
    }
};

int main() {
    Shape* circlePtr = new Circle(5);
    circlePtr->getArea();
    delete circlePtr;
    return 0;
}