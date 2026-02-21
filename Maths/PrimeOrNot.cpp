// to check whether a function is prime or not
#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if (n <= 1)
        return false;
        
    if (n == 2)    // direct return 
        return true;
        
    if (n % 2 == 0)  //even number ko alag se handle karne se iteration half ho jayegi
        return false;

    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0)
            return false;
    }

    return true;
}

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;

    if (isPrime(n))
        cout << n << " is Prime";
    else
        cout << n << " is Not Prime";

    return 0;
}
