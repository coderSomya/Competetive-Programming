#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

vector<vector<int>> adj(N);
vector<int> curr(N);
vector<int> past(N);

int dp[N][3][3];

bool rec(int src, int col, int par){
    //return is it possible to have a tree if we color the vertex col
    
   int ct=0;
   past[src]=col;

   //cout<<src<<endl;


   //what do you want? 

   //curr[src]
   if(dp[src][col][past[par]]!=-1) return dp[src][col][past[par]];


   for(auto x: adj[src]){
     if(x!=par){
        if(rec(x, curr[src], src)){
            continue;
        }
        else if(rec(x,1-curr[src], src)){
            ct++;
        }
        else return dp[src][col][past[par]] = false;
     }
   }


   if(ct + (past[par]!=curr[src]) > ((int)adj[src].size())/2){
    return dp[src][col][past[par]] = false;
   }

   return dp[src][col][past[par]] = true;

}

void solve(){

    int n; cin>>n;

    adj.clear();
    adj.resize(n+1);

    curr.clear();
    curr.resize(n+1);

    past.clear();
    past.resize(n+1);

    for(int i=0; i<n-1; i++){
        int u,v; cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    string s; cin>>s;

    for(int i=0; i<n; i++){
        curr[i+1]=(s[i]=='B');
    }

    for(int i=0; i<=n; i++){
        for(int j=0; j<3; j++) for(int k=0; k<3; k++) dp[i][j][k]=-1;
    }

    past[0]=2;

    if(rec(1,0,0)){
        for(int i=1; i<=n; i++){
         if(past[i]==1)cout<<'B';
         else cout<<'W';
        }
        cout<<endl;
        return;
    }
    
    // past.clear();
    // past.resize(n+1);
    // past[0]=-1;
    
    for(int i=0; i<=n; i++){
        for(int j=0; j<3; j++) for(int k=0; k<3; k++) dp[i][j][k]=-1;
    }
 
    if(rec(1,1,0)){
        for(int i=1; i<=n; i++){
         if(past[i]==1)cout<<'B';
         else cout<<'W';
        }
        cout<<endl;
        return;
    }

    cout<<-1<<endl;




}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}