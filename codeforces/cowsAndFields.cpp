#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define loop(i,l,r) for(int i=l; i<r; i++)
#define pii pair<int,int>
#define ff first
#define ss second

const int inf=1e18;

void dijkstra(int src, vi &dist, vvi &adj){
   
   dist[src]=0;

   priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

   pq.push({0,src});

   while(!pq.empty()){
    

    pii x= pq.top();
    // cout<<x.ss<<endl;
    pq.pop();

    for(auto ch: adj[x.second]){
        if(dist[ch]>dist[x.second]+1){
            dist[ch]=dist[x.second]+1;
            pq.push({dist[ch], ch});
        }
    }
   }
}

void solve(){
    int n,m,k;cin>>n>>m>>k;
   
   vector<int> aks;
   for(int i=0; i<k; i++){
    int x; cin>>x;
    aks.push_back(x);
   }

   vector<vector<int>> adj(n+1);
   for(int i=0; i<m; i++){
    int u,v; cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
   }

   vector<int> d1(n+1,inf);
   vector<int> d2(n+1,inf);

   dijkstra(1,d1,adj);
   dijkstra(n,d2, adj);

   int ans=d1[n];

//    vi l,r,eq;

/*
d1[i]<d1[j]
d2[j]<d2[i]
d1[i]+d2[j]<d1[j]+d2[i]
(d1-d2)i < (d1-d2)j

*/

vector<pair<int,int>> v;

for(int i=0; i<k; i++){
    v.push_back({d1[aks[i]]-d2[aks[i]], aks[i]});
}

sort(v.begin(), v.end());

vi suff(k);
suff[k-1]=d2[v[k-1].second];

for(int i=k-2; i>=0; i--){
    suff[i]=max(suff[i+1], d2[v[i].second]);
}

int temp=-inf;

for(int i=0; i<k-1; i++){
    temp=max(temp, 1+d1[v[i].second]+suff[i+1]);
}

ans= min(ans, temp);



cout<<ans<<endl;
    
}

int32_t main(){
    solve();
    return 0;
}