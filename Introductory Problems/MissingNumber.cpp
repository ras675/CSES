#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    // Calculate the sum of all numbers from 1 to n
    long long sum = (long long)n * (n + 1) / 2;

    // Subtract the sum of given numbers from the sum of all numbers
    for (int i = 1; i < n; ++i) {
        int num;
        cin >> num;
        sum -= num;
    }

    // The result will be the remaining sum
    cout << sum << endl;

    return 0;
}
