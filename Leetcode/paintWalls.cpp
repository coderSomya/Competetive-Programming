#include <bits/stdc++.h>
using namespace std;

class Solution {
    int solve(int i, int req,vector<int>& cost, vector<int>& time, vector<vector<int>> &dp){
        int n=cost.size();
        if(req<=0) return 0;
        if(i==n) return 2e9;
        if(dp[i][req]!=-1) return dp[i][req];
        return dp[i][req]= min(solve(i+1, req, cost, time, dp), cost[i]+ solve(i+1, req-1-time[i], cost, time, dp ));
    }
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n=cost.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1,-1));
        int ans= solve(0,n,cost, time, dp);

        return ans;
    }
};