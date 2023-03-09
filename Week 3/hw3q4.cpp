#include <iostream>
using namespace std;

int main(){
    const int FLOOR_ROUND = 1;
    const int CEILING_ROUND = 2;
    const int ROUND = 3;
    float user_num;
    int user_choice;
    cout<<"Please enter a Real number:"<<endl;
    cin>>user_num;
    cout<<"Choose your rounding method:"<<endl;
    cout<<"1. Floor round"<<endl;
    cout<<"2. Ceiling round"<<endl;
    cout<<"3. Round to the nearest whole number"<<endl;
    cin>>user_choice;

    if (user_choice == 1 || user_choice == 2 || user_choice == 3){
        int round_num;
        switch(user_choice){
            case 1:
                round_num = user_num;
                break;
            case 2:
                round_num = (user_num + 0.5);
                break;
            case 3:
                int whole_num = user_num;
                if ((user_num - whole_num) < 0.5){
                    round_num = user_num;
                }
                else
                    round_num = (user_num + 0.5);
                break;
        }
        cout<<round_num<<endl;
    }
    else{
        cout<<"Sorry, that was not an option."<<endl;
    }
    return 0;
}