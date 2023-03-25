/*
problem link->
https://codeforces.com/problemset/problem/1706/C
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
  vi v;
  for(int i=1; i<n-1; i++){
    v.pb(max((int)0, 1+ max(arr[i+1]-arr[i], arr[i-1]-arr[i])));
  }


}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}

//3 1 4 5 5 2

//4 2 1 1
//4 2 1 3 5 3 6 1
// 3 5 3 0 4 0
//3 5 6 5 10 5
//10 5 7 0 4 0


