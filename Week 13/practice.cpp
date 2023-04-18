#include <random>
#include <iostream>
using namespace std;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 3);

    int random_number = dis(gen);

    int main() {
    cout<<random_number<<endl;
    return 0;
}