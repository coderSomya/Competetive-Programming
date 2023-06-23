#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
       vector<int> v(value+1,0);
   for(auto x: nums){
        if(x>=0) v[x%value]++;
        //x+k*value>=0
        else{
int k=-x/value;
        v[(1ll*(x+ (k+1)*value))%value]++;
        }
        
   }
    
    if(v[0]==0) return 0;
  int mini=1e9;
    v[value]=v[0]-1;
    for(int i=1; i<=value; i++){
        mini=min(mini,v[i]);
    }

    int ans=value*mini;

    for(int i=1;i<=value; i++){
        v[i]-=mini;
        if(v[i]==0) {
            ans+= i;
            break;
        }
    }

    

      return ans;
    }
};