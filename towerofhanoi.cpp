#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Tower of Hanoi (counting moves only)
void hanoi(int n, char source, char auxiliary, char destination) {
    if (n == 0)
        return;

    hanoi(n - 1, source, destination, auxiliary);
    // move is counted but not printed
    hanoi(n - 1, auxiliary, source, destination);
}

int main() {

    int repetitions = 100;

    cout << "Rings\tAverageTime(ns)\n";

    for (int n = 3; n <= 15; n++) {

        long long totalTime = 0;

        for (int i = 0; i < repetitions; i++) {

            auto start = high_resolution_clock::now();
            hanoi(n, 'A', 'B', 'C');
            auto end = high_resolution_clock::now();

            auto duration = duration_cast<nanoseconds>(end - start);
            totalTime += duration.count();
        }

        double avgTime = (double)totalTime / repetitions;
        cout << n << "\t" << avgTime << endl;
    }

    return 0;
}
