#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    int steps = 0;
    while (n != 0) {
        string num_str = to_string(n); // Convert integer to string to access each digit
        int max_digit = 0;
        for (char digit : num_str) {
            max_digit = max(max_digit, digit - '0'); // Convert char to integer
        }
        n -= max_digit; // Subtract the maximum digit
        steps++;
    }

    cout << steps << endl;

    return 0;
}
