#include <bits/stdc++.h>
using namespace std;

int n; 
const int N  = 400;

const int inf = 1e9;

int arr[N];

int dp[N][N];

int rec(int i, int last){
    if(i==n) return 0;

    if(last==N) return inf;
   int temp=inf;

   if(dp[i][last]!=-1) return dp[i][last];

    for(int j=last+1; j<N; j++){
        temp=min(temp, abs(arr[i]-j) + rec(i+1, j));
    }

    return dp[i][last]=temp;
}

void solve(){
    cin>>n;
   
    for(int i=0; i<n; i++) cin>>arr[i];
    sort(arr, arr+n);

    memset(dp, -1, sizeof(dp));

    int ans=rec(0,0);
    cout<<ans<<endl;
}

int main(){
    int t; cin>>t;
    while(t--)
    solve();

    return 0;
}