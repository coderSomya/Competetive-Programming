/*
problem link->
https://leetcode.com/problems/shortest-impossible-sequence-of-rolls/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int ct=0;
        int n=rolls.size();

        set<int> st;
        for(int i=n-1; i>=0; i--){
            st.insert(rolls[i]);
            if(st.size()==k){
                ct++;
                st.clear();
            }
        }
        return ct+1;
    }
};