#include<iostream>
#include<algorithm>
#define ll long long 
 
using namespace std;
 
int main(){
    ll n, x; 
    cin >> n >> x;
    
    int arr[n]; 
    
    for(int i = 0; i < n; i++){ 
        cin >> arr[i];
    }
    sort(arr, arr + n); 
    
    int i = 0;
    int j = n-1;
    int count = 0;
    
    while(i<=j){
    if(arr[i]+arr[j]>x){
            count++;
            j--;
        } else {
            i++;
            j--;
            count++;
        }
    }
 
    cout << count << endl;
    return 0;
}