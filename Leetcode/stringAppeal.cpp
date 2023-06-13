/*
problem link->
https://leetcode.com/problems/total-appeal-of-a-string/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  long long solve(string s, int k){
      //return number of subarrays with k distinct characters
      int l=0; int r=-1;
      int ct=0;
      int freq[26]={0};
   
      int res=0;
      int n=s.length();
      
      while(r<n){
          while(r<n-1 && ct<=k){
              r++;
              freq[s[r]-'a']++;
              if(freq[s[r]-'a']==1) ct++;
              if(ct==k) res++;
          }
      if(ct>k) {
r--; freq[s[r]-'a']--;
ct--;
      }
              

          while(ct==k){
              res++;
              freq[s[l]-'a']--;
              if(freq[s[l]-'a']==0) ct--;
              l++;
          }

          r++;

          
    
      }

    
      return res;
}
public:
    long long appealSum(string s) {
        int ans=0;
        for(int i=1; i<=26; i++){
         int x= solve(s,i);
         cout<<"appeal of size "<<i<<"= "<<x<<endl;
         ans+= i*x;
        }

        return ans;
    }
};