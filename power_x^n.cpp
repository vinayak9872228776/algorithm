#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Binary Exponentiation (O(log n))
int  power(int x, int n) {
    if(n==0){
        return 1;
    }
    int half = power(x, n / 2);

    if (n % 2 == 0)
        return half * half;
    else
        return x * half * half;
}

int main() {
    int x ;
    cout<<"Enter the value of x";//base
    cin>>x;        
    int repetitions = 100;    // average over 100 runs

    cout << "InputSize\tAverageTime(us)\n";

    for (int n = 1000; n <= 20000; n += 1000) {

        int totalTime = 0;

        for (int i = 0; i < repetitions; i++) {

            auto start = high_resolution_clock::now();
            power(x, n);
            auto end = high_resolution_clock::now();

            auto duration = duration_cast<nanoseconds>(end - start);
            totalTime += duration.count();
        }

        int avgTime = totalTime / repetitions;
        cout << n << "\t\t" << avgTime << endl;
    }

    return 0;
}
