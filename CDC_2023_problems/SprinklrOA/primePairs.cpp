#include <bits/stdc++.h>
using namespace std;

const int N =100005;
const int inf= 1e9;

int dp[N][2];
unordered_set<int> primes;

//dp(i,0) dist till first prime
//dp(i,1) dist till 2nd prime

void dfs(int src, int par, vector<vector<int>> &adj){

    for(auto x: adj[src]){
        if(x!=par){
            dfs(x, src, adj);
        }
    }


    int sum1=0; int sum2=0;
    for(auto x: adj[src]){
       if(x==par) continue;
       sum1+=1+dp[x][0];
       sum2+=1+dp[x][1];
    }

    if(primes.count(src)==0){
        dp[src][0]=sum1;
        dp[src][1]=sum2;
    }
    else{
        dp[src][0]=0;
        dp[src][1]=sum1;
    }
   
}

void init()
{
    vector<bool> all(N, false);
    for(int i=2; i<N; i++){
        if(!all[i]){
         primes.insert(i);
         for(int j=i*i; j<N; j+=i) all[j]=true;
        //  cout<<i<<endl;
        }       
    }
    cout<<(int)primes.size()<<endl;
}

void solve(){
    int n; cin>>n;
    vector<vector<int>> adj(n+1);

    for(int i=0; i<n-1; i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=0; i<N; i++) for(int j=0; j<2; j++) dp[i][j]=0;

   dfs(1,0,adj);
   int ans=0;

   for(int i=1; i<=n; i++) ans+=dp[i][1]-dp[i][0];

   for(int i=1; i<=n; i++) cout<<dp[i][0]<<" "<<dp[i][1]<<endl;


   cout<<ans<<endl;

}

int main(){
    init();
    int t; cin>>t;
    while(t--) solve();

    return 0;
}