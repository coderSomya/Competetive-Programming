/*
problem link ->
https://codeforces.com/problemset/problem/1695/C
*/

#include <bits/stdc++.h>
using namespace std;

const int inf=1e9;

vector<vector<int>> grid;
int n,m;

bool safe(int x, int y){
    return x<n && y<m;
}


bool dfs(int sx, int sy, int sum){

  
  if(sx==n-1 && sy==m-1) return (sum+grid[sx][sy]==0);
  
  sum+= grid[sx][sy];
  bool temp=false;

  if(safe(sx+1,sy)) temp=temp||dfs(sx+1,sy,sum);

  if(safe(sx,sy+1)) temp=temp||dfs(sx,sy+1,sum);

  sum-=grid[sx][sy];
  return temp;

}

void solve(){

    cin>>n>>m;
    grid.clear();
    grid.resize(n,vector<int> (m));
    for(int i=0; i<n; i++) for(int j=0;j<m; j++) cin>>grid[i][j];


    if(dfs(0,0,0)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}

