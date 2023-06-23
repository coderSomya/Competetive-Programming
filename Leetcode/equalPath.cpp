#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        
        //no of elements = 2power level
       vector<int> arr(cost);
        int total_levels= log2(n+1);

       int ans=0;
         for(int level=1; level<total_levels;level++){
             int i= (1<<level)-1;
             int sum=0;int maxi=-1;
             for(int j=0;j<(1<<level); j++){
                  sum=sum+arr[i+j];
                  maxi=max(maxi, arr[i+j]);
             }

             ans+= maxi*(1<<level)-sum;
         }
        return ans;
    }
};