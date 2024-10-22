#include<iostream>
#include<algorithm>
#define ll long long 
 
using namespace std;
 
int main(){
    ll n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n); //sorting the array in ascending order.
    int count=1;
    for(ll i=1;i<n;i++){
        if(arr[i]==arr[i-1]){
            continue;
        }else{
            count++;
        }
    }
    cout<<count<<endl;//printing the number of distinct elements present in the array
    return 0;
}