#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0)
        return 1;
    else
        return (n * factorial(n - 1));
}

int main() {
    int n = 0;
    cout << "Please Enter the Number to see its Factorial : ";
    cin >> n;
    cout << "Factorial of " << n << " : " << factorial(n) << endl;
    return 0;
}
