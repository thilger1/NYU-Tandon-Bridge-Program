#include <iostream>
#include <fstream>

using namespace std;
ifstream in_stream;
ofstream out_stream;

int main() {
    
    int the_number;
    cout<<"Num?"<<endl;
    in_stream>>the_number;
    out_stream<<"NUM: ";
    out_stream<<the_number;
}