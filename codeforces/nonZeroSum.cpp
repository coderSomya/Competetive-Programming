/*
problem link -
https://codeforces.com/problemset/problem/1753/A1
*/

//n should be even

//1 -1 or -1 1 we put the segment[1][-1] or [-1][1]

//1 1 or -1 -1 we put the segment [1 1] or [-1 -1]

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
    int n; cin>>n;
    take_arr

    if(n%2){
        cout<<"-1"<<endl;
        return;
    }

    vector<pair<int, int>> v;
    
    for(int i=0; i<n; i+=2){
       if(arr[i]==arr[i+1]){
        v.pb({i+1,i+2});
       }
       else {
        v.pb({i+1,i+1});
        v.pb({i+2, i+2});
       }
    }

    cout<<v.size()<<endl;
    loop(i,0,v.size()){
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}