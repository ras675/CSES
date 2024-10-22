#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));

    // Base case: for the first element, if it's unknown (0), all values from 1 to m are possible
    if (x[0] == 0) {
        for (int j = 1; j <= m; ++j) {
            dp[1][j] = 1;
        }
    } else {
        dp[1][x[0]] = 1;
    }

    // Iterate through each element of the array
    for (int i = 2; i <= n; ++i) {
        // If the current element is unknown (0)
        if (x[i - 1] == 0) {
            for (int j = 1; j <= m; ++j) {
                // The value of the current element can be j - 1, j, or j + 1
                for (int k = j - 1; k <= j + 1; ++k) {
                    if (k >= 1 && k <= m) {
                        dp[i][j] += dp[i - 1][k];
                        dp[i][j] %= MOD;
                    }
                }
            }
        } else {
            // If the current element is known, the value is fixed
            int j = x[i - 1];
            for (int k = j - 1; k <= j + 1; ++k) {
                if (k >= 1 && k <= m) {
                    dp[i][j] += dp[i - 1][k];
                    dp[i][j] %= MOD;
                }
            }
        }
    }

    // Sum up the possibilities for the last element
    int ans = 0;
    for (int j = 1; j <= m; ++j) {
        ans += dp[n][j];
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}
