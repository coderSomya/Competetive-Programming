//Floyd Warshall Algorithm
//All pair shortest path

//Time Complexity- O(n^3)

#include <bits/stdc++.h>
using namespace std;

const int inf= 1e9;
int n,m;

vector<vector<int>> floyd_warshall(vector<vector<int>> graph){
   
   vector<vector<int>> dist(graph);

   //phases
   //in kth phase, we include vertices (1,2,3....k) as intermediate vertices


   for(int k=0; k<n; k++){
     for(int i=0; i<n;i++){
        for(int j=0; j<n; j++){
           
           //if vertex k is included can we minimize distance

           if(dist[i][j]>dist[i][k]+dist[k][j]){
             dist[i][j]= dist[i][k]+ dist[k][j];
           }
        }
    }
   }

   return dist;
}

int main(){

    cin>>n>>m;

    vector<vector<int>> graph(n, vector<int>(n,inf));

    for(int i=0; i<m; i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u][v]=w;
    }

    for(int i=0; i<n; i++){
        graph[i][i]=0;
    }

    vector<vector<int>> res=floyd_warshall(graph);

    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
        cout<<res[i][j]<<" ";
    }
    cout<<endl;
       } 
        



    return 0;
}
