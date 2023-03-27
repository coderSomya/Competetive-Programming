/*
problem link ->
https://codeforces.com/problemset/problem/1611/D
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
    int par[n+1]; loop(i,1,n+1) cin>>par[i];
    int p[n+1]; loop(i,1,n+1) cin>>p[i];
    
    int curr=0;
    vi dist(n+1, -1);
   
    int root=p[1];
    if(par[root]!=root){
        cout<<-1<<endl;
        return;
    }
    else{
        dist[root]=0;
        curr++;
    }

    for(int i=2; i<=n; i++){
        if(dist[par[p[i]]]==-1){
            cout<<-1<<endl; return;
        }
        dist[p[i]]=curr; curr++;
    }

    loop(i,1,n+1){
        cout<<dist[i]-dist[par[i]]<<" ";
    }
 
    cout<<endl;
     
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}