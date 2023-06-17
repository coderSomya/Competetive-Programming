/*
problem link->
https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
bool isSafe(int i, int j, int n, int m) {
return i<n && j<m;
}

private: 


private:
  int solve(int i, int j, int n, int m,int rem_mod, vector<vector<int>>& grid, int k){
      if(!isSafe(i,j,n,m)) return 0;

      if(i==n-1 && j==m-1) return (grid[i][j]%k == rem_mod);

      int left= solve(i+1, j, n, m, (rem_mod - (grid[i][j]%k)+k)%k, grid,  k);
      int down= solve(i, j+1, n, m, (rem_mod - (grid[i][j]%k)+k)%k,  grid, k);

      return left+down;
  }
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();


        return solve(0,0,m,n,0,grid,k);
    }
};