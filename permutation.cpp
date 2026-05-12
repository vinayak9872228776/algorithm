#include <iostream>
#include <string>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Function to generate permutations
void permute(string &s, int l, int r) {
    if (l == r) {
        // Just generate, do not print (printing affects time)
        return;
    }

    for (int i = l; i <= r; i++) {
        swap(s[l], s[i]);
        permute(s, l + 1, r);
        swap(s[l], s[i]); // backtrack
    }
}

int main() {

    int repetitions = 100;

    cout << "InputSize\tAverageTime(us)\n";

    for (int size = 3; size <= 10; size++) {

        string s = "";
        for (int i = 0; i < size; i++)
            s += char('A' + i);   // ABC, ABCD, ...

        long long totalTime = 0;

        for (int i = 0; i < repetitions; i++) {

            auto start = high_resolution_clock::now();
            permute(s, 0, size - 1);
            auto end = high_resolution_clock::now();

            auto duration = duration_cast<microseconds>(end - start);
            totalTime += duration.count();
        }

        double avgTime = (double)totalTime / repetitions;
        cout << size << "\t\t" << avgTime << endl;
    }

    return 0;
}
