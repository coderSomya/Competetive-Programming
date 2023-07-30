#include <bits/stdc++.h>
using namespace std;

set<pair<int,int>> deleted;

void dfs(int src, int par, vector<vector<pair<int,int>>> &adj, vector<pair<int, pair<int,int>>> &v){

    for(auto x: adj[src]){
        if(x.first==par || deleted.count({min(x.first, src), max(x.first, src)})!=0) continue;

        else{
            v.push_back({x.second, {x.first, src}});
            dfs(x.first, src, adj, v);
        }
    }
}

void solve(){

    int m; cin>>m;
    int n; cin>>n;

    vector<vector<pair<int,int>>> adj(m+1);

    vector<int> ans(n);


    for(int i=0; i<m-1;i++){
        int u, v, w; cin>>u>>v>>w;

         adj[u].push_back({v,w});
         adj[v].push_back({u,w});
    }
   
   int arr[n];
   for(int i=0; i<n; i++)cin>>arr[i];

   for(int i=0; i<n; i++){
    vector<pair<int, pair<int,int>>> v;
    dfs(i, 0, adj, v);
    
    sort(v.begin(), v.end());
    deleted.insert({min(v[0].second.first, v[0].second.second), max(v[0].second.first, v[0].second.second)});

    ans[i]=v[0].first;
   }

   sort(ans.begin(), ans.end());
   int sum=0; 
   for(int i=0; i<ans.size()-1; i++) sum+=ans[i];

   cout<<sum<<endl;

}

int main(){

    int t; cin>>t;
    while(t--) solve();

    return 0;
}

/*

1
5
2
1 2 8
1 4 10
4 0 12
4 3 13
0 3

*/