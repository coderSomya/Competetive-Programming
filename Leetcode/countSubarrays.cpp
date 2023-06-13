/*
problem link->
https://leetcode.com/problems/count-subarrays-with-score-less-than-k/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
   int bs(int pos, int sum, vector<long long>&pref, int k, int n){
       int l=pos; int h=n;
       int ans=pos;
       while(l<=h){
           int mid=(l+h)/2;

           if((pref[mid]-pref[pos])*(mid-pos)<k){
               l=mid+1;
               ans=mid;
           }
           else h=mid-1;
                  }

                  return ans;
   }
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans=0;
        int n=nums.size();
        vector<long long> pref(n+1); pref[0]=0;
        for(int i=1; i<=n; i++){
            pref[i]=pref[i-1]+nums[i-1];
        }

       if(n==1){
           if(nums[0]<k) return 1;
           else return 0;
       }
        for(int i=1; i<=n; i++){
            int idx=bs(i-1,pref[i-1], pref, k, n);
            ans+=idx-i+1;
        }
        return ans;
    }
};