#include <bits/stdc++.h>
using namespace std;

const int mod= 1e9 + 7;

#define int long long


int binexpo(int a, int b){
   
   if(b==0) return 1;
   if(b==1) return a;

   int res= binexpo(a,b/2);
   res=res*res%mod;

   if(b%2) res*=a;

   res%=mod;

   return res;
}

void dfs(int src, int par, vector<vector<int>> &adj, vector<int> &subtree){

    int temp=0;

    for(auto x: adj[src]){
        if(x!=par){
           dfs(x, src, adj, subtree);
        }
    }

    for(auto x: adj[src]){
        if(x!=par) temp+=subtree[x];
    }

    subtree[src]=1+temp;
}

void solve(){
    int n,k; cin>>n>>k;

    vector<vector<int>> adj(n+1);
    for(int i=0; i<n-1; i++){
        int u,v; cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    if(k==1 || k==3){
        cout<<1<<endl;
        return;
    }

    vector<int> subtree(n+1);
    dfs(1,-1, adj, subtree);

    int ans=0;

    for(int i=1; i<=n; i++){
        ans+= subtree[i]*(n-subtree[i]+1) -1;
    }

    int num=ans; int denom= n*(n-1)/2;
cout<<num<<" "<<denom<<endl;
    int x=__gcd(num, denom);
    num/=x; denom/=x;
     num%=mod; denom%=mod;
    cout<<(num*binexpo(denom, mod-2))%mod<<endl;
}


int32_t main(){
    solve();

    return 0;
}