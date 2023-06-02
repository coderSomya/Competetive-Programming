/*
problem link->
https://codeforces.com/problemset/problem/1583/C
*/

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,m; cin>>n>>m;
    char grid[n][m];
    int dp[n][m];
    for(int i=0; i<n; i++){
        string s; cin>>s;
        for(int j=0;j<m; j++){
           grid[i][j]=s[j];
        }
    }

    for(int j=0; j<m; j++) dp[0][j]=0;
    for(int i=0; i<n; i++) dp[i][0]=0;

    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
          if(grid[i-1][j]=='X' && grid[i][j-1]=='X') dp[i][j]=dp[i][j-1]+1;
          else dp[i][j]=dp[i][j-1];
        }
    }

    vector<int>cols(m);
    for(int j=0; j<m; j++){
        int temp=0;
        for(int i=0; i<n; i++) temp+=dp[i][j];

        cols[j]=temp;
    }


 

    int q; cin>>q;
    while(q--){
        int l,r; cin>>l>>r; l--; r--;

        if(cols[r]-cols[l]==0){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
}

int main(){
    // int t; cin>>t;
    // while(t--) 
    solve();

    return 0;
}