/*
problem link->
https://codeforces.com/problemset/problem/1579/D
*/

#include <bits/stdc++.h>
using namespace std;
#define loop(i,l,r)     for(int i=l; i<r; i++)
#define int             long long
#define pb              push_back
#define vi              vector<int>
#define mkp             make_pair<int,int>
#define umpii           unordered_map<int,int>
#define maxheap         priority_queue<int>
#define minheap         priority_queue<int, vi,greater<int>>
#define setbits(x)      __builtin_popcountll(x)
#define zerobits(x)     __builtin_ctzll(x)
#define in_arr(A,n)     loop(i,0,n) cin>>A[i];
#define p_arr(A,n)      loop(i,0,n) cout<<A[i]
;
#define pln_arr(A,n)    loop(i,0,n) cout<<A[i]<<endl
#define take_n          int n; cin>>n;
#define take_arr        int arr[n]; loop(i,0,n) cin>>arr[i];
  
  
const int mod= 1e9+7;
const int inf= 1e15;
 
 
void solve(){
    take_n
    take_arr
     priority_queue<pair<int,int>>p;
     vector<pair<int,int>> ans;
    loop(i,0,n){
     p.push({arr[i],i+1});
    }
   int ct=0;
    while(p.size()>1){
        pair<int,int> x=p.top();
        p.pop();
        pair<int,int> y=p.top();
        p.pop();
        if(y.first>0){
            ct++;
            ans.pb({x.second, y.second});
        }

        x.first--; y.first--;
        if(x.first>0) p.push({x.first, x.second});
        if(y.first>0) p.push({y.first, y.second});
    }

    cout<<ct<<endl;
    loop(i,0,ct){
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}