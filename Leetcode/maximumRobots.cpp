/*
problem link->

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private: 
  bool check(int len, vector<long long> &pref, vector<vector<int>> &maxi, int k, int n){
           int l=0; int h=len-1;
           cout<<"hello"<<endl;
           while(h<n){
               int sum=pref[h]-(l>0 ? pref[l-1] : 0);
               int r=log2(len);

               int m=max(maxi[l][r], maxi[h-(1<<r)+1][r]);

               if(m + 1ll*len*(sum) <=k) return true;
               l++; h++;
           }

           return false;

  }

public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
            int n=chargeTimes.size();
           vector<vector<int>> maxi(n, vector<int>(20));
        
           for(int i=0; i<n; i++) maxi[i][0]=chargeTimes[i];

           for(int j=1; j<20; j++){
               for(int i=0; i<n; i++){
                   if((i+(1<<j)-1)<n){
                       maxi[i][j]=max(maxi[i][j-1],maxi[i+(1<<(j-1))][j-1]);
                   }
               }
           }

           //bimary searc on k
           vector<long long> prefix(n);
           prefix[0]=runningCosts[0];
           for(int i=1; i<n; i++) prefix[i]=prefix[i-1]+runningCosts[i];

           int l=0; int h=n;
      int ans=0;
 
           while(l<=h){
               int mid=(l+h)/2;

               if(check(mid, prefix, maxi, budget,n)){
                   ans=mid; l=mid+1;
               }

               else h=mid-1;
           }

           return ans;

    }
};