#include<iostream>
#include<algorithm>
#define ll long long 
 
using namespace std;
 
int main(){
    ll n, m, k; 
    cin >> n >> m >> k;
    
    int arrN[n]; 
    int arrM[m]; 
    
    for(int i = 0; i < n; i++){ 
        cin >> arrN[i];
    }
    sort(arrN, arrN + n); 
    
    for(int i = 0; i < m; i++){ 
        cin >> arrM[i]; 
    }
    sort(arrM, arrM + m); 
    
    int i = 0;
    int j = 0;
    int count = 0;
    
    while(i < n && j < m){
        int val = abs(arrN[i] - arrM[j]);
        if(val <= k) {
            count++;
            i++;
            j++;
        } else {
            if(arrN[i] < arrM[j]) 
                i++;
            else
            j++;
        }
    }
 
    cout << count << endl;
    return 0;
}