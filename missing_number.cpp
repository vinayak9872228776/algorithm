#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

// LSB-based missing number function
int findMissing(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if ((arr[i] & 1) == (arr[i + 1] & 1)) {
            return (arr[i] + arr[i + 1]) / 2;
        }
    }
    return -1;
}

int main() {

    int repetitions = 100;

    cout << "InputSize\tAverageTime(us)\n";

    for (int size = 1000; size <= 20000; size += 1000) {

        // Create sorted consecutive array with one missing number
        vector<int> arr(size);
        int start = 500;                  // arbitrary start (not from 1)
        int missingIndex = size / 2;      // missing in middle

        for (int i = 0, val = start; i < size; val++) {
            if (i == missingIndex) val++; // skip one number
            arr[i++] = val;
        }

        long long totalTime = 0;

        for (int i = 0; i < repetitions; i++) {

            auto startTime = high_resolution_clock::now();
            findMissing(arr.data(), size);
            auto endTime = high_resolution_clock::now();

            totalTime += duration_cast<microseconds>(endTime - startTime).count();
        }

        double avgTime = (double)totalTime / repetitions;
        cout << size << "\t\t" << avgTime << endl;
    }

    return 0;
}
