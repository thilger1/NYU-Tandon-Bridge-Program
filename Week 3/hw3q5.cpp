#include <iostream>
#include <string>
using namespace std;

int main(){
    //bmi = weight(kilo) / height^2(meters)
    //below 18.5, Underweight
    //18.5 - 25, Normal
    //25 - 30, Overweight
    //30+, Obese

    int weight, height;
    string status;
    cout<<"Please enter weight (in pounds): ";
    cin>>weight;
    cout<<"Please enter height (in inches): ";
    cin>>height;
    float kilos = weight * 0.453592;
    float meters = height * 0.0254;
    float bmi = kilos / (meters*meters);
    if (bmi < 18.5){
        status = "Underweight";
    }
    else if (bmi >= 18.5 && bmi <= 25){
        status = "Normal";
    }
    else if (bmi >= 25 && bmi <= 30){
        status = "Overweight";
    }
    else{
        status = "Obese";
    }
    cout<<"The weight status is: "<<status<<endl;
    return 0;
}