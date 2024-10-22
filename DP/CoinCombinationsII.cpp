#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;


void solve(){
      int n, x;
    cin >> n >> x;
      vector<long long> coins(n);
      for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    sort(coins.begin(), coins.end());
    vector<long long> dp(x + 1);
      dp[0] = 1;
      
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= x; j++) {
            if (j - coins[i] >= 0) {
                dp[j] +=  dp[j - coins[i]];
            }
            dp[j] %= MOD;
        }
    }

    cout << dp[x] << endl; 
}

int main() {

    int t;
    t=1;
    while(t--){
        solve();
    }

    return 0;
}
