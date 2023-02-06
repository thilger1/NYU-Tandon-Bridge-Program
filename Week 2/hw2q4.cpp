#include <iostream>
using namespace std;

int main(){

    int int_one, int_two;
    cout<<"Please enter two positive integers, separated by a space: "<<endl;
    cin>>int_one>>int_two;
    
    int ans_add = int_one + int_two;
    int ans_subtract = int_one - int_two;
    int ans_multiply = int_one * int_two;
    float ans_float_div = (float)int_one / int_two;
    int ans_int_div = int_one / int_two;
    int ans_mod = int_one % int_two;

    cout<<int_one<<" + "<<int_two<<" = "<<ans_add<<endl;
    cout<<int_one<<" - "<<int_two<<" = "<<ans_subtract<<endl;
    cout<<int_one<<" * "<<int_two<<" = "<<ans_multiply<<endl;
    cout<<int_one<<" / "<<int_two<<" = "<<ans_float_div<<endl;
    cout<<int_one<<" div "<<int_two<<" = "<<ans_int_div<<endl;
    cout<<int_one<<" mod "<<int_two<<" = "<<ans_mod<<endl;
    return 0;
}