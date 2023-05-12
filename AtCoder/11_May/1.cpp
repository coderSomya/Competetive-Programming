/*
problem link ->
https://atcoder.jp/contests/arc159/tasks/arc159_a
*/


#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>adj(100);
int n,k;
const int inf= 1e9;

vector<vector<int>> floyd_warshall(vector<vector<int>> &graph){
   
   vector<vector<int>> dist(graph);


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
void solve(){
    
  cin>>n>>k;
  vector<vector<int>> graph(n, vector<int>(n));
  for(int i=0; i<n; i++){
   for(int j=0; j<n; j++){
     int x; cin>>x;
     if(x==1) graph[i][j]=1;
     else graph[i][j]=inf;
   }
  }

  //floyd warshall to find distances between each
  vector<vector<int>> res= floyd_warshall(graph);
  
  int q;
  cin>>q;
  while(q--){
    // cout<<"inisde query"<<endl;
    int a,b; cin>>a>>b;
    a--,b--;
    int ans=res[a%n][b%n];
    if(ans >=inf) ans=-1;
    cout<<ans<<endl;
  }
}

int main(){
    // int t; cin>>t;
    // while(t--)
     solve();

    return 0;
}