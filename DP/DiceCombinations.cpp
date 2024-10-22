#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

#define ll long long
const ll md = 1000000007;

void solve(){
    int n;
    cin >> n;
    vector<ll> nums;
    for(int i = 0; i < 6; i++){
        nums.push_back(pow(2, i));
    }
    for(int i = 6; i <= n; i++){ 
        nums.push_back((nums[i-1] + nums[i-2] + nums[i-3] + nums[i-4] + nums[i-5] + nums[i-6]) % md);
    }
    cout << nums[n-1] << endl;
}

int main(){
    int t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}
