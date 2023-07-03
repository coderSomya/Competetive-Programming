#include <bits/stdc++.h>
using namespace std;

const int mod= 998244353;

void solve(){
    int n,k; cin>>n>>k;
    

    vector<vector<int>> dp(3002, vector<int>(3002, 0));
 

    //dp(i,j)-> number of ways to get sum j by using i elements

    dp[0][0]=1;
    for(int i=1; i<=n; i++){
        for(int j=i; j>=1; j--){
            dp[i][j]=dp[i-1][j-1];
            if(2*j<=n) dp[i][j]+=dp[i][2*j];
            dp[i][j]%=mod;
        }
    }

    cout<<dp[n][k]<<endl;
}

int  main(){
    // int t; cin>>t;
    // while(t--) 
    solve();


    return 0;
}

