#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter degree of polynomial: ";
    cin >> n;

    vector<double> coeff(n + 1);

    cout << "Enter coefficients (a0 to an):\n";
    for (int i = 0; i <= n; i++) {
        cin >> coeff[i];
    }

    double x;
    cout << "Enter value of x: ";
    cin >> x;

    // Horner's Rule
    double result = coeff[n];
    for (int i = n - 1; i >= 0; i--) {
        result = coeff[i] + x * result;
    }

    cout << "Result = " << result;

    return 0;
}