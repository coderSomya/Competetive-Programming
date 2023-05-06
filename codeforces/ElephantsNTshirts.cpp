/*
100 tshirts, N elephants
*/

#include <bits/stdc++.h>
using namespace std;


int dp[101][2048];
vector<vector<int>> adj(101);

int ways(int i, int bitmask, int n){
  
    if(bitmask==((1<<n)-1)){
        //all people have been assigned tshirts
        return 1;
    }

    if(i>=100) return 0;

    if(dp[i][bitmask]!=-1) return dp[i][bitmask];
    int temp=ways(i+1, bitmask, n);
    //kisi ko mat do ye wala

    for(auto x: adj[i]){
        if((bitmask & (1<<(x))) == 0){
            temp+=ways(i+1, (bitmask | (1<<(x))), n);
        }
    }

    return dp[i][bitmask]=temp;
}

void solve(){
    int n;
    cin>>n;
    adj.clear();
  
    for(int i=0; i<n; i++){
       int x; cin>>x;
       for(int j=0;j<x; j++){
        int r; cin>>r;
        adj[r].push_back(i);
       }
    }

    memset(dp, -1, sizeof(dp));
  
   int ans= ways(0,0,n);
   cout<<ans<<endl;

}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}
