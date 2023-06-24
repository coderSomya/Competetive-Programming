#include <bits/stdc++.h>
using namespace std;

class Solution {
private: 
  int dp[23][2][2][500];
  const int mod= 1e9 + 7;
private: 
   int solve(int i, vector<int> &lower, vector<int> &higher, bool t1, bool t2, int sum, int n, int maxi, int mini){
       if (i==n)
       {
           if(sum<=maxi && sum>=mini) return 1;
           else return 0;
       }

       if(dp[i][t1][t2][sum]!=-1) return dp[i][t1][t2][sum];

       int lb= t1 ? lower[i] : 0;
       int ub= t2? higher[i] : 9;

       int temp=0;
       for(int digit= lb; digit<=ub; digit++){
           int t_t1= t1&& (digit==lb);
           int t_t2= t2&&( digit == ub);

           temp= temp+ solve(i+1, lower, higher, t_t1, t_t2, sum+digit, n, maxi, mini);
           temp%=mod;
       }

       return dp[i][t1][t2][sum] =temp;
   }
public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        

        vector<int> lower, higher;

        while(num1 != ""){
            int x=num1.back()-'0';
            lower.push_back(x);
            num1.pop_back();
        }

        while(num2!=""){
            int x=num2.back()-'0';
            higher.push_back(x);
            num2.pop_back();
        }

        // int n=max(lower.size(), higher.size());

        while(lower.size()<higher.size()){
            lower.push_back(0);
        }

        reverse(lower.begin(), lower.end());
        reverse(higher.begin(), higher.end());

        memset(dp, -1, sizeof(dp));

        for(auto x: lower) cout<<x<<" ";
        cout<<endl;
        for(auto x: higher) cout<<x<<" ";
        cout<<endl;
        int ans = solve(0,lower,higher, 1,1, 0 , lower.size(), max_sum, min_sum);

        return ans%mod;;
    }
};