//graph algorithm SSSP
//use it when there are negative edge weights, otherwise use Dijkstra's

//Time Complexity- O(VE)

/*
Algorithm:
1)Init dist of all nodes to inf, and source to 0.
2)Relax all edges V-1 times.
3)check negative weight cycle
*/

#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

vector<int> bellman_ford(int n, int src, vector<vector<int>> edges){

    //init
    vector<int> dist(n+1, inf);
    dist[src]=0;

    //relax
    for(int i=0; i<n-1; i++){
        for(auto x: edges){
            int u= x[0];
            int v=x[1];
            int w=x[2];

            if(dist[u]!=inf && dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
            }
        }
    }

    //check
    for(auto x: edges){
           int u= x[0];
           int v=x[1];
           int w=x[2];

           if(dist[u]!=inf && dist[v]>dist[u]+w){
            cout<<"Negative weight cycle found"<<endl;
            exit(0);
           }
    }

    return dist;

}
int main(){

    int n,m; cin>>n>>m;
    vector<vector<int>> edges;

    for(int i=0; i<m; i++){
        vector<int> edge(3);
        cin>>edge[0]>>edge[1]>>edge[2];
        edges.push_back(edge);
    }

    vector<int> dist= bellman_ford(n,1,edges);

    return 0;
}
