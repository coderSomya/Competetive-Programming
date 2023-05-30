/*
problem link->
https://codeforces.com/problemset/problem/1609/D
*/

#include <bits/stdc++.h>
using namespace std;

//dsu problem

int n,d;
int par[1005];
int size[1005];

void init(){
  for(int i=1; i<=n; i++) par[i]=i;
  for(int i=1; i<=n; i++) size[i]=1;
}

int Get(int a){
    if(a==par[a]) return a;
    return par[a]= Get(par[a]);
}

void Union(int a, int b){
    int pa=Get(a);
    int pb=Get(b);

    if(pa==pb) return;

    if(size[pa]<size[pb]) swap(pa,pb);

    size[pa]+=size[pb];
    par[pb]=pa;
}

int Findmax(){
    int maxi=0;
    for(int i=1; i<=n; i++){
     maxi=max(maxi, size[i]);
    }

    return maxi;
}



void solve(){
    
    cin>>n>>d;
    vector<vector<int>> adj(n+1);

    init();
    while(d--){
      int x,y; cin>>x>>y;

      //for all x...y add them to the same bundle
      for(int i=x; i<y; i++) Union(i,i+1);
      
      int maxi= Findmax();
      cout<<maxi-1<<endl;
      
    }
    
}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}
