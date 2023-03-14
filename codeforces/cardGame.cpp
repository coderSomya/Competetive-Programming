/*
problem link ->
https://codeforces.com/problemset/problem/1739/C
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
  
  
const int mod= 998244353;
const int inf= 1e15;
 
vector<vector<int>> fact(61,vector<int>(61,0));
vi alex(61);

void solve(){
  
  take_n
  int a,b,c;
  a=alex[n]%mod;
  b= fact[n][n/2]-1-alex[n];
  b%=mod;
  c=1;

  cout<<a<<" "<<b<<" "<<c<<endl;
  

}
  
  
int32_t main(){
fact[2][0]=1; fact[2][1]=2;fact[2][2]=1;
loop(i,0,61) fact[i][0]=1;
loop(i,3,61){
    loop(j,1,i+1){
        fact[i][j]=fact[i-1][j]+fact[i-1][j-1];
    }
}
alex[2]=1;
alex[4]=3;
for(int i=6; i<=60; i+=2){
    alex[i]=fact[i-1][(i-1)/2]+(fact[i-2][(i-2)/2]-1-alex[i-2]);
}

int t;
cin>>t;
while(t--) solve();
return 0;
}