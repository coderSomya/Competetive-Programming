#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

vector<vector<pair<int,int>>> adj(N);

map<pair<int, int>,int> mp;

int up[N][21];
int lvl[N];

void levelling(int src, int par, int level){

    lvl[src]=level;

    for(auto x: adj[src]){
       if(x.first!=par)              levelling(x.first, src, level+1);
    }
}

void binary_lifting(int src, int par){
    
    up[src][0]=par;

    for(int i=1; i<21; i++){
       if(up[src][i-1]!=-1){
        up[src][i]=up[up[src][i-1]][i-1];
       }
       else up[src][i]=-1;
    }

    for(auto x: adj[src]){
        if(x.first!=par){
            binary_lifting(x.first, src);
        }
    }
}

int lift_node(int node, int step){

    for(int i=20; i>=0; i--){
        if(step==0 || node==1){
              break;
        }

        if(step>=(1<<i)){
            step-=(1<<i);
            node=up[node][i];
        }
    }

    return node;
}

int lca(int u, int v){
    if(lvl[u]<lvl[v]) swap(u,v);

    u = lift_node(u, lvl[u]- lvl[v]);

    if(u==v) return v;

    for(int i=20; i>=0; i--){
        if(up[u][i]!=up[v][i]){
            u=up[u][i];
            v=up[v][i];
        }
    }

    return lift_node(u, 1);
}



void dfs(int src, int par, int each, vector<int> &v){

    v[src]= v[par];
    
    if(src!=1) v[src] += abs(mp[{min(src, par), max(src, par)}]- each);

    for(auto x: adj[src]){
        if(x.first !=par) dfs(x.first, src, each, v);
    }

}



void solve()
{
    int n;cin>>n;

    adj.clear();
    adj.resize(n+1);
    
    int q; cin>>q;
    vector<pair<int,int>> queries(q);
    for(int i=0; i<n-1; i++){
        int u,v,w; cin>>u>>v>>w;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});

        mp[{min(u,v), max(u,v)}]=w;
    }

    for(int i=0; i<q; i++)
    {
        int x,y; cin>>x>>y;
        queries[i]={x,y};
    }

    mp[{0,1}]=0;
    
    vector<vector<int>> op(27, vector<int> (n+1, 0));

    //op[w][i] stores number of operations when every edge weight is w from root to i

    for(int i=0; i<=26; i++){
        dfs(1,0,i, op[i]);
    }
    

    memset(up, -1, sizeof(up));
    memset(lvl, -1, sizeof(lvl));

    levelling(1, 0, 0);
    binary_lifting(1, 0);

    
    for(int i=0; i<q; i++){
        int x= queries[i].first;
        int y= queries[i].second;

        int ans=1e6;

        for(int i=0; i<+26; i++){
            int temp= op[i][x]+ op[i][y] - op[i][lca(x,y)];

            ans=min(ans,temp);
        }

        cout<<ans<<endl;
    }

    
}

int main(){
    int t; cin>>t;
    while(t--)solve();

    return 0;
}