/*
problem link ->
https://codeforces.com/problemset/problem/1625/C
*/

#include <bits/stdc++.h>
using namespace std;
int n,l,k;   int x[501]; int lim[501];

const int inf=2e9;

int dp[501][501];

//recursive appraoch

// int find(int last, int curr, int k)
// {
//   if(curr==n) return dp[last][curr][k]=(l-x[last])*lim[last];


//   if(dp[last][curr][k]!=-1) return dp[last][curr][k];

//   int temp1= (x[curr]-x[last])*lim[last]+ find(curr, curr+1, k);
  
//   int temp2=inf;
//   if(k>0) temp2=find(last, curr+1, k-1);

//   return dp[last][curr][k]= min(temp1, temp2);

// }


void solve(){
   cin>>n>>l>>k;

    for(int i=0;i<n;i++) cin>>x[i];
    for(int i=0;i<n;i++) cin>>lim[i];
    x[n]=l;
    for(int i=0; i<=n; i++)for(int j=0; j<=k; j++) dp[i][j]=inf;

    //  int res= find(0,1,k);

    //iterative approach
    dp[0][0]=0;
    for(int i=1; i<=n; i++){
        dp[i][0]=dp[i-1][0]+lim[i-1]*(x[i]-x[i-1]);
    }
    

    for(int i=1;i<=n; i++){
        for(int j=0;j<i; j++){
            for(int rem=min(i,k); rem>=0; rem--){
                dp[i][rem]=min(dp[i][rem], (x[i]-x[j])*lim[j]+ dp[i][rem-(i-j)]);
            }
        }
    }

    int res=inf;
    for(int i=0; i<=k;i++) res=min(res, dp[n][i]);

    cout<<res<<endl;


}

int main(){
    // int t; cin>>t;
    // while(t--)
    solve();

    return 0;
}