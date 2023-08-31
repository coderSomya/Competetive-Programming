#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define fl for(int i=0; i<n; i++)

int in[1000];
int out[1000];


void dfs1(int src, int par, vvi &adj){

    int temp=0;
    for(auto x: adj[src]){
        if(x!=par){
            dfs1(x, src, adj);
        }
    }

    for(auto x: adj[src]){
        if(x!=par) temp=max(temp, in[x]);
    }

    in[src]=1+temp;
}

vi parent(1000);

void dfs2(int src, int par, vvi &adj){

    int temp=0;
    parent[src]=par;

    if(par==-1){
        out[src]=0;
    }

    else{
     int tt=0;
     int flag=0;
     for(auto x: adj[par]){
        if(x!=src && x!=parent[par]){
            tt=max(tt, in[x]);
            flag=1;
        }
     }

     out[src]=1+max(1+tt, out[par]);
    }
    
    for(auto x: adj[src]){
        if(x!=par) dfs2(x, src, adj);
    }

}

vi ans;
int maxi=1e9;
int smaxi=1e9;



void dfs3(int src, int par, vvi &adj){

    int m=0; int sm=0;

    for(auto x: adj[src]){
        if(x!=par){
        if(in[x]>=m){
            sm=m;
            m=in[x];
        }
        else if(in[x]>sm){
            sm=in[x];
        }
        }
    }

    int p=out[src];
    if(p>=m){
        sm=m;
        m=p;
    }
    else if(p>sm){
        sm=p;
    }

    

    for(auto x: adj[src]){
       if(x!=par) dfs3(x, src, adj);
    }
}
void solve(){
    int n; cin>>n;
    

    vector<vector<int>> adj(n);
    for(int i=0; i<n-1; i++){
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs1(0, -1, adj);
    dfs2(0, -1, adj);

    // dfs3(0, -1, adj);

    ans.clear();

    fl{
        int m=max(in[i], out[i]);
        if(m<maxi){
            ans.clear();
            ans.push_back(i);
            maxi=m;
        }
        else if(m==maxi){
            ans.push_back(i);
        }
    }

    for(auto x: ans) cout<<x<<" ";
    cout<<"\n";

}


int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}