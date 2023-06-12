/*
problem link->
https://leetcode.com/problems/subarray-with-elements-greater-than-varying-threshold/
*/

//sparse table solution


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        //build a sparse table O(nlogn)
        int n=nums.size();
        int pow2[21];
        pow2[0]=1;
        for(int i=1; i<21; i++) pow2[i]=pow2[i-1]*2;

        int dp[n][21];
        //dp(i, j)-> min in the range i->i+pow(2,j)
        for(int i=0; i<n; i++){
            dp[i][0]=nums[i];
        }

        for(int j=1; j<=20; j++){
          for(int i=0; i<n; i++){
             if(i+pow2[j]>=n) continue;
              dp[i][j]=min(dp[i][j-1], dp[i+pow2[j-1]][j-1]);
          }
        }

        for(int i=0; i<n; i++){
            //for i to be the start of a subarray nums[i]>=(threshold)/x
            int x= (threshold+nums[i]-1)/nums[i];
             if(i+x>n) continue;
            //find nearest power of two of x
            int r=log2(x);
            int mini=min(dp[i][r],dp[i+x-1][r]);
            int s=threshold/x;
            if(mini>=s) return x;
        }

        return -1;
    }
};