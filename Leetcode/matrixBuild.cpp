/*
problem link->
https://leetcode.com/problems/build-a-matrix-with-conditions/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> radj(k+1);
        vector<vector<int>> cadj(k+1);

        vector<int> rid(k+1,0);
        vector<int> cid(k+1,0);

        for(vector<int>x: rowConditions){
            int up=x[0]; int down=x[1];

            rid[down]++;
            radj[up].push_back(down);
            radj[down].push_back(up);
        }

        
        for(vector<int> x: colConditions){
            int left=x[0]; int right=x[1];

            cid[right]++;
            cadj[right].push_back(left);
            cadj[left].push_back(right);
        }

        queue<int> rq;
        vector<int> rows;
        for(int i=1; i<=k; i++){
            if(rid[i]==0) rq.push(i);
        }
        vector<int> rvis(k+1,0);
        vector<int> cvis(k+1,0);

        while(!rq.empty()){
            int x= rq.front();
            rq.pop();
            rvis[x]++;
            for(auto y: radj[x]){
                if(!rvis[y]){
   rid[y]--;
                if(rid[y]==0) rq.push(y);
                }
             
            }
            
            rows.push_back(x);
        }

        

        queue<int> cq;
        vector<int> cols;
        for(int i=1; i<=k; i++){
            if(cid[i]==0) cq.push(i);
        }

        while(!cq.empty()){
            int x= cq.front();
            cq.pop();
         cvis[x]++;
            for(auto y: cadj[x]){
                if(!cvis[y]){
cid[y]--;
                if(cid[y]==0) cq.push(y);

                }
                
            }
            
            cols.push_back(x);
        }

       unordered_map<int,int> rowno;
       for(int i=0; i<k; i++){
           rowno[rows[i]]=i;
       }


       vector<vector<int>> res(k, vector<int> (k));

       for(int i=0; i<k; i++){
          res[rowno[cols[i]]][i]=cols[i];
       }
     for(int i=0; i<k; i++){
         for(int j=0; j<k;j++) cout<<res[i][j]<<" ";
         cout<<endl;
     }
       return res;


    }
};