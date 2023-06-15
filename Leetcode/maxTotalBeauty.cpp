/*
problem link->
https://leetcode.com/problems/maximum-total-beauty-of-the-gardens/
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
   int maxi(vector<int> &v, int i, vector<int> &pref,int sum){
      int l=0; int h=i-1; 
      int ans=l;

      while(l<=h){
          int mid=(l+h)/2;

          if(pref[mid]<=sum){
              ans=mid; l=mid+1;
          }
          else{
              h=mid-1;
          }
      }

      return ans;
   }
public:
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
     int ans=0;
     vector<int> v;
     for(int i=0; i<flowers.size(); i++){
         if(flowers[i]>=target) ans+=full;
         else v.push_back(flowers[i]);
     }

     sort(v.begin(), v.end());

     int n=(int)v.size();
     if(n==0){
         return ans;
     }

     if(n==1){
         if(newFlowers+v[0]>=target) return ans+max(full, (target-1)*partial);
         else return ans+(v[0]+newFlowers)*partial;
     }
     int suff[n]; suff[n-1]=v[n-1];
     for(int i=n-2; i>=0; i--) suff[i]=suff[i+1]+v[i];
     long long res=ans;

     vector<int> pref(n);
     pref[0]=0;
     for(int i=1; i<n; i++){
         pref[i]=i*(v[i]-v[i-1]);
     }

     for(int i=n-1; i>=0; i--){
         //i se n-1 tak full karo baki jitne bache unse partial maximize karo
         long long temp=0;
         int req=(n-i)*target - suff[i];
         if(newFlowers>=req) temp+=(n-i)*full;
         int left=newFlowers-req;
         if(i>0){
         int idx= maxi(v,i, pref, left);
         int rem=left-pref[idx];
         temp+=(min(target-1,v[idx]+ rem/(idx+1)))*partial;
         }

         res=max(res, ans+temp);
     }


     return res;
    }
};