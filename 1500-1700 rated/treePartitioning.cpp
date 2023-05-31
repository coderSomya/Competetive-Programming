/*
problem link->
https://codeforces.com/problemset/problem/1592/C
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
int subtreeXOR[100005];
int val[100005];

void dfs(int src, int par){
    int res=val[src];

    for(auto child: adj[src]){
        if(child!=par){
            dfs(child, src);
        }
    }

    for(auto x: adj[src]){
        res^=subtreeXOR[x];
    }

    subtreeXOR[src]=res;
    return;
}

bool flag;

int check(int src, int par, int target){
    
    int ct=0;
    for(auto child: adj[src]){
        if(child!=par){
            ct+= check(child, src, target);
        }
    }
    if(ct>=2) flag=true;
    if(ct>0) return 1;
    else return subtreeXOR[src]==target;
}


void solve(){
    int n,k; cin>>n>>k;

    adj.clear();
    adj.resize(n+1);
    memset(subtreeXOR, 0, sizeof(subtreeXOR));
    memset(val, 0, sizeof(val));
    
    
    int target=0;
    for(int i=1; i<=n; i++){
        cin>>val[i];
        target^=val[i];
    }

    for(int i=0; i<n-1; i++){
        int u, v;
         cin>>u>>v;
         adj[u].push_back(v);
         adj[v].push_back(u);
    }

    if(target==0){
        cout<<"YES"<<endl;
        return;
    }

    if(k-1<2){
        cout<<"NO"<<endl;
        return;
    }

    dfs(1, -1);
   
    //we must check if there is a node such that there are atleast two children with subtreeXOR == target
    flag=false;
    check(1, -1, target);

    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;



}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}