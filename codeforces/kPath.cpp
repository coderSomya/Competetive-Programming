/*
problem link ->\https://codeforces.com/problemset/problem/1196/F
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
    int n,m,k; cin>>n>>m>>k;

    vector<vector<pair<int,int>>> adj(n+1);
    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>> , greater<pair<int, pair<int,int>>>> pq;
  set<pair<int,int>> vis;
    loop(i,0,m){
        int x,y,w;
        cin>>x>>y>>w;
        adj[x].pb({w,y});
        adj[y].pb({w,x});
        pq.push({w,{x,y}});
        vis.insert({min(x,y), max(x,y)});
    }



    int ct=0;
    while(!pq.empty()){
        auto x=pq.top();
        pq.pop();
        ct++;
        if(ct==k){
            cout<<x.first<<endl;
            return;
        }
        int weight=x.first;
        int a=x.second.first;
        int b=x.second.second;
      

        for(auto y: adj[a]){
           if(vis.find({min(a,y.second), max(a, y.second)})==vis.end()){
              vis.insert({min(a,y.second), max(a, y.second)});
              pq.push({weight+y.first, {a, y.second}});
           }
        }

        
        for(auto y: adj[b]){
           if(vis.find({min(b,y.second), max(b, y.second)})==vis.end()){
              vis.insert({min(b,y.second), max(b, y.second)});
              pq.push({weight+y.first, {b, y.second}});
           }
        }


    }

}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}