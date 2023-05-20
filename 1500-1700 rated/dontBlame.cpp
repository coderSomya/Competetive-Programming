/*
problem link ->
https://codeforces.com/problemset/problem/1829/H
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
int ans;

const int mod=1e9+7;


int count(int i,int arr[],int k, int n, int mask, vector<vector<int>> &dp){

    
    if(i==n) return dp[i][mask]= (__builtin_popcount(mask)==k);
    if(dp[i][mask]!=-1) return dp[i][mask];
     dp[i][mask]= count(i+1,arr,k,n,mask, dp);
    int temp_mask=mask&(arr[i]);

    dp[i][mask]+= count(i+1,arr,k,n,temp_mask, dp);
    dp[i][mask]=dp[i][mask]%mod;

    return dp[i][mask];

}

vector<int> v;
void solve(){
    int n; int k; cin>>n>>k;
    int arr[n];
    ans=0;
    for(int i=0; i<n; i++) cin>>arr[i];

    v.clear();

    for(int i=0;i<(1<<6); i++){
        if(__builtin_popcount(i)==k) v.push_back(i);
    }

    

   vector<vector<int>> dp(n+1, vector<int>(64,-1));

   int res=count(0,arr,k,n,(1<<6)-1,dp);

   if(k==6) res--;
   cout<<res%mod<<endl;

}

int32_t main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}