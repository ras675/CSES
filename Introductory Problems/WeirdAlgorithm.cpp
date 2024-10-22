#include <iostream>
using namespace std;

void simulateAlgorithm(long long n) {
    cout << n << " ";
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = n * 3 + 1;
        }
        cout << n << " ";
    }
}

int main() {
    long long n;
    cin >> n;
    simulateAlgorithm(n);
    return 0;
}
