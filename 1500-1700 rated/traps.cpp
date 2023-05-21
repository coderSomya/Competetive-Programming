/*
problem link->
https://codeforces.com/problemset/problem/1684/D
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n,k; cin>>n>>k;

    int arr[n];
    for(int i=0;i<n; i++) cin>>arr[i];

    //try greedy
    

    vector<pair<int,int>> v;

    for(int i=0; i<n; i++) v.push_back({-arr[i]+(n-1-i), -i});

    sort(v.begin(), v.end());

    set<int> st;
    for(int i=0; i<k; i++) st.insert(-v[i].second);
    int ct=0;
    int sum=0;

    for(int i=0; i<n; i++){
    if(st.find(i)!=st.end()){
        ct++;
    }
    else{
        sum+=arr[i]+ct;
    }
    }

    cout<<sum<<endl;


  
}

int32_t main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}