#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int main() {
    int n;
    cin >> n;

    // Read the grid
    vector<vector<char> > grid(n, vector<char>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    // Create a DP table to store the number of paths to each cell
    vector<vector<int> > dp(n, vector<int>(n, 0));

    // Base case: the upper-left cell has one path
    dp[0][0] = (grid[0][0] == '.') ? 1 : 0;

    // Fill the DP table
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '.') {
                if (i > 0) {
                    dp[i][j] += dp[i - 1][j];
                    dp[i][j] %= MOD;
                }
                if (j > 0) {
                    dp[i][j] += dp[i][j - 1];
                    dp[i][j] %= MOD;
                }
            }
        }
    }

    // Print the result
    cout << dp[n - 1][n - 1] << endl;

    return 0;
}
