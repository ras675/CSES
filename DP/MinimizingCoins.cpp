#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    vector<int> dp(x + 1, INT_MAX); // dp[i] represents the minimum number of coins needed to make sum i
    dp[0] = 0; // Base case: 0 coins needed to make sum 0

    for (int i = 1; i <= x; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    if (dp[x] == INT_MAX) {
        cout << -1 << endl; // It's not possible to make the desired sum
    } else {
        cout << dp[x] << endl;
    }

    return 0;
}
