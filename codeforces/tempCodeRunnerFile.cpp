/*
problem link - 
https://codeforces.com/problemset/problem/1790/D
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
    umpii mp;
    loop(i,0,n){
        mp[arr[i]]++;
    }
    int ans=0;
    loop(i,0,n){
        if(mp.find(arr[i]-1)!=mp.end()) {
            mp[arr[i]-1]--;
            if(mp[arr[i]-1]==0) mp.erase(arr[i]-1);
        }
    }

    for(auto x: mp){
        cout<<x.first<<" "<<x.second<<endl;
        ans+= x.second;

    }

    cout<<ans<<endl;
    
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}