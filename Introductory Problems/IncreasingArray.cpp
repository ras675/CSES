#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    long long moves = 0;
    int min_val = arr[0]; // Initialize the minimum value encountered so far

    for (int i = 1; i < n; ++i) {
        // If the current element is smaller than the minimum value encountered so far,
        // update the minimum value.
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
        // Calculate the number of moves needed for the current element to be at least
        // as large as the minimum value encountered so far, and add it to the total moves.
        moves += (long long)(min_val - arr[i]);
    }

    cout << moves << endl;

    return 0;
}
