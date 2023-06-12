#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
  int rec(int i, int x, vector<vector<int>> &adj, vector<vector<int>> &dp){
     if(i==1) return 1;
     long long temp=0;
    if(dp[i][x]!=-1) return dp[i][x];
     for(auto y: adj[x]){
         temp+=rec(i-1, y, adj, dp);
     }

     return dp[i][x]=temp;
  }
public:
    int idealArrays(int n, int maxValue) {
        int m=maxValue;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
       
        vector<vector<int>> adj(m+1);
        for(int i=1; i<=m; i++){
            for(int j=1; j*j<=i; j++){
                if(i%j==0){
                    adj[i].push_back(j);

                    if(j*j!=i) adj[i].push_back(i/j);
                }
            }
        }

        long long ans=0;
        for(int i=1; i<=m; i++){
            ans+=rec(n,i,adj,dp);
        }
        return ans;

        
    }
};