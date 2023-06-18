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

void dfs(int src, int par, vector<vector<int>> &adj, vector<vector<int>> &subtree, vector<int>& ch){

    subtree[src][ch[src]]++;

    for(auto x: adj[src]){
        if(x!=par){
            dfs(x, src, adj, subtree,ch );
        }
    }

    for(auto x: adj[src]){
        for(int i=0; i<26; i++){
            subtree[src][i]+=subtree[x][i];
        }
    }
}
 
void solve(){
    int n,q; cin>>n>>q;

    vector<vector<int>> adj(n+1);

    vector<int> ch(n+1);
    vector<int>target(26,0);
    
    for(int i=0; i<n; i++){
        char c; cin>>c;
       target[c-'a']++;
       ch[i+1]=c-'a';
    }

    


loop(i,0,n-1){
    int u, v;
    cin>>u>>v;
    adj[u].pb(v);
    adj[v].pb(u);
}

vector<vector<int>> subtree(n+1, vector<int>(26,0));

dfs(1,0, adj, subtree, ch);

while(q--){
    int r; string t;
    cin>>r>>t;
    
  int temp=0;
    vector<int> have=subtree[r];
   
    int g=t.length();
    for(int i=0; i<g; i++){
        have[t[i]-'a']--;
    }

    for(int i=0; i<26; i++){
        temp+= max((int)0, -have[i]);
    }
    

    cout<<temp<<endl;
}


}
  
  
int32_t main(){
// int t;
// cin>>t;
// while(t--) 
solve();
return 0;
}