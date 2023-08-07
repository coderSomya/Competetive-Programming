#include <bits/stdc++.h>
using namespace std;

#define int long long 

const int N=3e5+5;
const int M=11;

long long dp[N][M];

int n,m,k;

/*

dp[i][j]=arr[i] + dp[i-1][j-1]
dp[i][0]=arr[i]+dp[i-1][m-1];
*/

void kadane(int arr[]){

    
    int dp[n];
    dp[0]=arr[0];
    int ans=max((int)0, dp[0]);

    for(int i=1; i<n; i++){
        dp[i]=max(dp[i-1]+arr[i], arr[i]);

        ans=max(ans, dp[i]);
    }


    cout<<ans<<endl;
    return;
}

void solve(){
    cin>>n>>m>>k;
    memset(dp,0, sizeof(dp));

    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    if(m==1){
    for(int i=0; i<n; i++) arr[i]-=k;
    kadane(arr);
    return;
    }

    if(m!=1) dp[0][1]=arr[0] -k;
    else dp[0][0]=arr[0] - k;


    int ans=0;

    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            if(j==1) dp[i][1]= max(arr[i]+dp[i-1][0]-k, (long long) arr[i]-k);
            else if(j==0) dp[i][j]=arr[i]+dp[i-1][m-1];
            else dp[i][j]=arr[i]+ dp[i-1][j-1];

            ans=max(1ll*ans, dp[i][j]);
        }
    }

    cout<<ans<<'\n';


}

int32_t main(){
  solve();
  return 0;
}