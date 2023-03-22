#include <iostream>
using namespace std;

//recursive function to check if it's a double palindrome

int fib(int n) {
    if (n <= 1){
        return n;
    }
    return fib(n-1) + fib(n-2);
}