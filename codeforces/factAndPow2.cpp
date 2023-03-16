/*
problem link->
https://codeforces.com/problemset/problem/1646/C
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
 
vi v;

int p;
int dp[53][1000000];


int rec(int i, int sum){
    //returns min more no.s to take if we are at i, and need a sum =n
   
   if(i>p) return dp[i][sum]= inf;
    if(v[i]>sum) return dp[i][sum]=  inf;

    if(v[i]==sum) return dp[i][sum]=  1;

    if(dp[i][sum]!=-1) return dp[i][sum];
   
    else return dp[i][sum]=  min(rec(i+1, sum), 1+ rec(i+1, sum-v[i]));
}

void solve(){

    take_n
    p=v.size();
    
    memset(dp, -1, sizeof(dp));

    cout<<rec(0,n)<<endl;

}
  
  
int32_t main(){
int x=1; set<int> st;
loop(i,0,40){
    st.insert(x);
    v.pb(x);
    x*=2;
}

int y=1;
loop(i,1,15){
  y*=i;
  if(st.find(y)==st.end()) v.pb(y);
}
  sort(v.begin(), v.end());

int t;
cin>>t;
while(t--) solve();
return 0;
}