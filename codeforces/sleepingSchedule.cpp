#include <bits/stdc++.h>
using namespace std;

int n,h,l,r;
const int N = 3000;
int arr[N];

int dp[N][N];

int rec(int i, int curr){

    if(i==n) return 0;

    int t1= (curr+arr[i]);
    if(t1>h) t1-=h;
    int t2= (curr+arr[i]-1);
    if(t2>h) t2-=h;

    int c1= (t1<=r && t1>=l);
    int c2= (t2<=r && t2>=l);

    if(dp[i][curr]!=-1) return dp[i][curr];

    return dp[i][curr] = max(c1+rec(i+1, t1), c2+ rec(i+1, t2));
}

void solve(){
    cin>>n>>h>>l>>r;

    for(int i=0; i<n;i++) cin>>arr[i];
    

    memset(dp, -1, sizeof(dp));

    int ans = rec(0,0);
    cout<<ans<<endl;

}


int main(){
    solve();

    return 0;
}