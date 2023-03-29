/*
problem link ->
https://codeforces.com/problemset/problem/1627/C
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

vector<vector<pair<int,int>>> adj;
vi ans;
vi vis;


void fill(int i, int turn){

    if(vis[i]) return;
    vis[i]=1;
    for(auto x: adj[i]){
        int other= x.first;
        int number=x.second;
        if(vis[other]) continue;
        else{
            ans[number]= (turn==0 ? 2 : 3);
            fill(other,1-turn);
        }
    }
    
}

 
 
void solve(){
    take_n
    // unordered_map<vector<vector<int>>, int>edges;
    adj.clear(); adj.resize(n+1);
    int degree[n+1]={0};
    bool flag=false;
    loop(i,0,n-1){
        int x,y;
        cin>>x>>y;
        //  edges[{min(x,y), max(x,y)}]=i;
         adj[x].pb({y,i});
         adj[y].pb({x,i});
         degree[x]++;
         degree[y]++;
         if(degree[x]>2||degree[y]>2) flag=true;
    }

    if(flag){
        cout<<-1<<endl;
        return;
    }

 
    ans.clear(); ans.resize(n-1);
    vis.clear(); vis.resize(n+1);
   loop(i,0,n+1) vis[i]=0;
    
    int root=-1;
    loop(i,1,n+1){
        if(degree[i]==1){
            root =i; break;
        }
    }

    //dfs from the root with alternating 2 and 3
    fill(root, 0);


    

    loop(i,0,n-1) cout<<ans[i]<<" ";
    cout<<endl;

}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}