#include <bits/stdc++.h>
using namespace std;


//detecting cylce in a directed graph

class Solution {
private: 
   int ans; int curr;

   void dfs(int src, vector<int> &edges, vector<int> &vis, vector<int>& pathvis, vector<int>& dist){
      
      vis[src]=1;
      pathvis[src]=1;

      
      int x=edges[src];
      if(x!=-1){
          if(!vis[x]){
              dist[x]=1+dist[src];
              dfs(x, edges, vis, pathvis, dist);
          }
          else if(pathvis[x])
          {
               ans=max(ans, abs(dist[src]-dist[x]+1));
          }
      }
    curr--;
    pathvis[src]=0;
   
   }

public:
    int longestCycle(vector<int>& edges) {
        ans=-1;
        int n=(int)edges.size();
        vector<int> vis(n, 0);
        vector<int> pathvis(n,0);
        vector<int> dist(n,0);

        for(int i=0; i<n; i++){
            if(!vis[i]){
dfs(i,edges, vis, pathvis, dist);
            }
        }

      return ans;
    }
};