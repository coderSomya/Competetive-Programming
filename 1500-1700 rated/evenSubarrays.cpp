/*
problem link ->
https://codeforces.com/problemset/problem/1731/C
*/


#include <bits/stdc++.h>
using namespace std;

const int N= 1e5;
vector<int> squares;
set<int> sq;

void solve(){
  int n; cin>>n;
  int arr[n];
  for(int i=0; i<n; i++)cin>>arr[i];


  int pref[n];
  pref[0]=arr[0];

  for(int i=1; i<n; i++){
    pref[i]=pref[i-1]^arr[i];
  }

  int ans=0;
  unordered_map<int,int> mp;
    mp[0]=1;
  for(int i=0; i<n; i++){
  
   
    for(auto x: squares) {
        if(mp.find(pref[i]^x)!=mp.end())
        {
         ans+=mp[(pref[i]^x)];
        }

    }
    // for(auto x: squares) if(mp.find(pref[i]+x)!=mp.end()) ans+=mp[(pref[i]+x)];

    

    mp[pref[i]]++;
  }

  int res=n*(n+1)/2-ans;
  cout<<res<<endl;
}


int main(){

 
    
     for(int i=0; i*i<=2*N; i++){
       squares.push_back(i*i);
       sq.insert(i*i);
    }
   
    int t; cin>>t; while(t--) solve();


    return 0;
}