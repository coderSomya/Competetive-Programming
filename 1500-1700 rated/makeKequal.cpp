/*
problem link->
https://codeforces.com/problemset/problem/1328/F
*/

#include <bits/stdc++.h>
using namespace std;

const int inf= 2e9;

void solve(){
    int n,k; cin>>n>>k;

    int arr[n];
    unordered_map<int,int> freq;
    for(int i=0;i<n; i++){
        cin>>arr[i]; freq[arr[i]]++;
    }
    
    

}


int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}