/*
problem link ->
https://codeforces.com/problemset/problem/1779/C
*/

#include <bits/stdc++.h>
using namespace std;

const int inf= 1e9+10;

void solve(){
    int n,m;cin>>n>>m;

    int arr[n+1];
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }

    if(n==1){
        cout<<0<<endl;
        return;
    }

     
     int curr=0;
     int ct=0;
     priority_queue<int, vector<int>, greater<int>> pq;
     for(int i=m+1; i<=n; i++){
       pq.push(arr[i]);
       curr+=arr[i];
       if(curr<0){
        ct++;
        int x=pq.top();
        pq.pop();
        curr+= -2*x;
       }      
    }

    // cout<<ct<<endl;

    //sorted for right part
    curr=0;
    priority_queue<int> pq2;
     for(int i=m; i>1; i--){
       pq2.push(arr[i]);
       curr+=arr[i];
       if(curr>0) {
        ct++;
        int x=pq2.top();
        pq2.pop();
        curr+=-2*x;
       }      
    }

    cout<<ct<<endl;

}

int main(){
    int t; cin>>t;
    while(t--) solve();


    return 0;
}