#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int main() {
    int t;
    cin >> t;

    // Precompute the number of towers for each height up to the maximum possible height
    vector<long long> towers(1000001, 0);
    towers[0] = 1; // Base case: empty tower
    towers[1] = 0; // Base case: height 1 cannot have a tower
    towers[2] = 2; // Base case: height 2 has 2 possible towers (vertical or horizontal)

    for (int i = 3; i <= 1000000; ++i) {
        // For each height, the number of towers is the sum of the number of towers for the previous two heights
        towers[i] = (towers[i - 1] + towers[i - 2]) % MOD;
    }

    // Process each test case
    while (t--) {
        int n;
        cin >> n;
        cout << towers[n] << endl;
    }

    return 0;
}
