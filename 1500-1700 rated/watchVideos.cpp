/*
problem link->
https://codeforces.com/problemset/problem/1765/D
*/

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,m; cin>>n>>m;
    int arr[n];
    int sum=0;

    for(int i=0; i<n; i++){
        cin>>arr[i];
        sum+=arr[i];
    }

    sort(arr, arr+n);
    int l=0; int r=n-1;
    
    int extra=0;

    while(l<r){
      if(arr[l]+arr[r]>m){
        extra+=1;
      }
      l++;
      r--;
    }
    
    extra+=1;
    cout<<sum+extra<<endl;
}

int main(){
    // int t; cin>>t;
    // while(t--) 
    solve();

    return 0;
}