#include <bits/stdc++.h>
using namespace std;

#define loop(i,l,r) for(int i=l; i<r; i++)
// #define int long long
#define vi vector<int>
#define pb push_back

const int inf = 1e9;

void solve(){
    int n; cin>>n;
    
    vi v;
    loop(i,0,n){
        int x; cin>>x;
        if(v.empty() || v.back()!=x) v.pb(x);
    }
    
    n=(int) v.size();

    
    
    int dp[n][n][2];

    for(int i=0; i<n; i++) for(int j=0; j<n; j++) for(int k=0; k<2; k++) dp[i][j][k]=inf;
    
    for(int i=0; i<n; i++) dp[i][i][0]=0;
    for(int i=0; i<n; i++) dp[i][i][1]=0;


    for(int len=2; len<=n; len++){
        for(int i=0; i<n-len+1; i++){
            int j=len+i-1;
            
            int add= 1- (v[i]==v[j]) ;
            dp[i][j][0]=min(dp[i][j][0], dp[i+1][j][0]+1);
            dp[i][j][0]=min(dp[i][j][0], dp[i+1][j][1]+add);
            
            dp[i][j][1]=min(dp[i][j][1], dp[i][j-1][1]+1);
            dp[i][j][1]=min(dp[i][j][1], dp[i][j-1][0]+add);
        }
    }

    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<n; j++) for(int k=0; k<2; k++) cout<<dp[i][j][k];
    //     cout<<endl;
    // }

    
    
    int ans= min(dp[0][n-1][0], dp[0][n-1][1]);
    cout<<ans<<endl;
}

int32_t main(){
    solve();
    
    return 0;
}