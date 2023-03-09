#include <iostream>
#include <cmath>
using namespace std;

void quadraticFormula(int a, int b, int c){
    float discriminant = (b*b) - 4*a*c;
    if (a == 0 && b == 0 && c == 0){
        cout<<"This equation has an infinite number of solutions"<<endl;
        return;
    }
    if (discriminant > 0){
        cout<<"This equation has two real solutions"<<endl;
        float solution_one = (b*(-1)) + sqrt(b*b - 4*a*c);
        float solution_two = (b*(-1)) - sqrt(b*b - 4*a*c);
        cout<<"Solution one: x="<<solution_one<<endl;
        cout<<"Solution two: x="<<solution_two<<endl;
        return;
    }
    else if (discriminant == 0){
        cout<<"This equation has one real solution"<<endl;
        float solution = (b*(-1))/(2*a);
        cout<<"Solution: x="<<solution<<endl;
        return;
    }
    else{
        cout<<"This equation has no real solution"<<endl;
        return;
    }
}

int main(){
    int a,b,c;
    cout<<"Please enter the value of a: ";
    cin>>a;
    cout<<"Please enter the value of b: ";
    cin>>b;
    cout<<"Please enter the value of c: ";
    cin>>c;
    quadraticFormula(a, b, c);
    return 0;
}