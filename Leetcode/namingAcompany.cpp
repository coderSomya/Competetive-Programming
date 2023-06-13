/*
problem link->
https://leetcode.com/problems/naming-a-company/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long ans=0;
        int n=ideas.size();

        set <string> st;
        set <char> firsts;
        vector<vector<char>> v(n);
        for(auto x: ideas) {
          st.insert(x); firsts.insert(x[0]);
        }

        int dp[26][26]={0};


        for(int i=0; i<n; i++){
            string s=ideas[i];
            for(char ch : firsts){
              string t=""; t+=ch;
              for(int i=1; i<s.length(); i++) t+=s[i];

              if(st.find(t)==st.end()){
      v[i].push_back(ch);
     char x=s[0];
     dp[s[0]-'a'][ch-'a']++;
              }
            }
        }


        for(int i=0; i<n; i++){
            for(char ch: v[i]){
             char c=ideas[i][0];
            ans+= dp[ch-'a'][c-'a'];
            }
        }

        return ans;
    }
};