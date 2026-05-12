#include <iostream>
#include <chrono>
#include <vector>
#include <iomanip>
using namespace std;

// Function: x ko power n tak raise karo (x^n calculate karo)
// Clever idea: halves ko calculate karo instead of full multiplication
// Example: 2^8 = (2^4) * (2^4) = 16 * 16 = 256
int powerRecursive(int x, int n) {
    // Base case: kisi bhi number ki power 0 = 1
    if (n == 0) 
        return 1;
    
    // Half exponent ka result calculate karo (choti problem solve karo)
    int half = powerRecursive(x, n / 2);
    
    // Agar n even hai (0, 2, 4, 6...)
    if (n % 2 == 0) {
        return half * half;
    } 
    // Agar n odd hai (1, 3, 5, 7...)
    else {
        return x * half * half;
    }
}

int main() {
    cout << "===== POWER RECURSIVE - TIME ANALYSIS =====\n\n";
    
    // Different exponent values test karne ke liye
    vector<int> testValues = {1000, 5000, 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000};
    
    // Base number (har test mein same x use hoga)
    int x = 2;
    
    // Har exponent ke liye 10 bar test karenge aur average nikaalenge
    cout << left << setw(15) << "Exponent(n)" 
         << setw(20) << "Average Time(μs)" 
         << setw(15) << "Min Time" 
         << setw(15) << "Max Time" << "\n";
    cout << string(65, '-') << "\n";
    
    for (int i = 0; i < 10; i++) {
        int n = testValues[i];
        double totalTime = 0;
        double minTime = 999999;
        double maxTime = 0;
        
        // Same exponent ke liye 10 iterations chalaate hain
        for (int iter = 0; iter < 10; iter++) {
            // Time measure karne start karo - HIGH PRECISION
            auto start = chrono::high_resolution_clock::now();
            
            // Actual calculation
            int result = powerRecursive(x, n);
            
            // Time measure karne end karo
            auto end = chrono::high_resolution_clock::now();
            
            // Microseconds mein duration nikalo
            chrono::duration<double, micro> duration = end - start;
            double timeInMicro = duration.count();
            
            totalTime += timeInMicro;
            minTime = min(minTime, timeInMicro);
            maxTime = max(maxTime, timeInMicro);
        }
        
        // Average time calculate karo (saare 10 iterations ka average)
        double avgTime = totalTime / 10.0;
        
        // Result print karo
        cout << left << setw(15) << n 
             << setw(20) << fixed << setprecision(4) << avgTime 
             << setw(15) << minTime 
             << setw(15) << maxTime << "\n";
    }
    
    cout << "\n===== ANALYSIS COMPLETE =====\n";
    cout << "Yeh time in microseconds hai (1 second = 10^6 microseconds)\n";
    
    return 0;
}