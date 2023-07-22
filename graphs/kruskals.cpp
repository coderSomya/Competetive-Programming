#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+4;

vector<int> par(N);
vector<int> rnk(N);

int get(int node){
    if(par[node]==node) return node;

    return par[node] = get(par[node]);
}

void merge(int a, int b){
    int pa= get(a);
    int pb= get(b);

    if(rnk[pa]<rnk[pb]){
       swap(pa, pb);
    }

    rnk[pa]+=rnk[pb];
    par[pb]=pa;
}

int spanningTree(vector<vector<pair<int,int>>> &adj,  vector<pair<int,pair<int,int>>> &edges){


    int sum=0;
int m= edges.size();
int n= adj.size()-1;
int ct=0;
    for(int i=0; i<m; i++){
        int x=edges[i].second.first;
        int y=edges[i].second.second;

        if(get(x)!=get(y)){
            ct++;
            merge(x, y);
            sum+=edges[i].first;
            // cout<<edges[i].first<<endl;
            if(ct==n-1) break;
        }
    }

    return sum;
}

void solve(){
    int n; cin>>n;

    vector<vector<pair<int,int>>> adj(n+1);

    vector<pair<int,pair<int,int>>> edges;

    int a[n], b[n];

    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cin>>b[i];

    vector<pair<pair<int,int>, int>> xs(n), ys(n);

    for(int i=0; i<n; i++){
        xs[i]={{a[i], b[i]}, i+1};
        ys[i]={{b[i], a[i]}, i+1};
    }

    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());




    for(int i=1; i<n; i++){
      
        int u= abs(xs[i].first.first - xs[i-1].first.first);
        int v= abs(xs[i].first.second - xs[i-1].first.second);
        adj[xs[i].second].push_back({xs[i-1].second,u});
        adj[xs[i-1].second].push_back({xs[i].second,u});

        // edges.push_back({u, {xs[i-1].second, xs[i].second}});
        edges.push_back({u, {xs[i].second, xs[i-1].second}});
    }
    
     for(int i=1; i<n; i++){
      
        int u= abs(ys[i].first.first - ys[i-1].first.first);
        int v= abs(ys[i].first.second - ys[i-1].first.second);
        adj[ys[i].second].push_back({ys[i-1].second,u});
        adj[ys[i-1].second].push_back({ys[i].second,u});

        // edges.push_back({v, {ys[i-1].second, ys[i].second}});
        edges.push_back({u, {ys[i].second, ys[i-1].second}});
    }


    for(int i=0; i<=n; i++) par[i]=i;

    sort(edges.begin(), edges.end());

    int ans= spanningTree(adj, edges);

    cout<<ans<<endl;
}

int main(){
    // int t; cin>>t;
    // while(t--) 
    solve();


    return 0;
}