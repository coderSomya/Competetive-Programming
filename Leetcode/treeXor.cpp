/*
problem link->
https://leetcode.com/problems/minimum-score-after-removals-on-a-tree/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private: 
  void dfs(int i, int src, int par, vector<vector<int>> &tree, vector<vector<int>> &sub){

      sub[i][src]=1;
      for(auto x: tree[src]){
          if(x!=par){
              dfs(i,x,src,tree,sub);
          }
      }
  }
private: 
   void fill(vector<vector<int>> &tree, int n, vector<vector<int>> &sub, vector<int> &par){
       for(int i=0; i<n; i++){
           dfs(i,i,par[i], tree,sub);
       }
   }
private:
   void findXor(int src, int par, vector<vector<int>> &tree, vector<int> &val, vector<int> &nums){
      
      int temp=0;
      for(auto x: tree[src]){
          if(x!=par){
            findXor(x,src,tree,val,nums);
            temp=temp^val[x];
          }
      }
      val[src]=nums[src]^temp;
   }
private: 
  void makePar(int src, int par,vector<vector<int>> &tree, vector<int> &parent){
      parent[src]=par;
       
       for(auto x: tree[src]){
           if(x!=par){
               makePar(x,src, tree,parent);
           }
       }
  }
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n=nums.size();
        vector<vector<int>> tree(n);
        for(auto x: edges){
            int u=x[0]; int v=x[1];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
       
       vector<vector<int>> sub(n,vector<int>(n,0));
      vector<int> par(n,0);
      makePar(0,-1,tree,par);
       fill(tree,n,sub, par);
       int ans= 1e9;

       vector<int>val(n);
       findXor(0,-1,tree, val, nums);
       
       for(int i=0; i<n-1; i++){
         for(int j=i+1; j<n-1; j++){
             int x,y;
              x= (par[edges[i][0]]==edges[i][1])? edges[i][0]: edges[i][1];
              y= (par[edges[j][0]]==edges[j][1])? edges[j][0]: edges[j][1];

             int a=val[x];
             int b=val[y];
             int c=val[0];

             if(sub[x][y])
             {
                 a=a^b;
                 c=c^a;
             }
             else if(sub[y][x]){
                 b=b^a;
                 c=c^b;
             }
             else c=c^a^b;

             ans=min(ans, (max({a,b,c}) - min({a,b,c})));


         }
       }
   return ans;
    }
};