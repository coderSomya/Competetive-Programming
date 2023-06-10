#include <bits/stdc++.h>
using namespace std;
#define int long long
#define loop(i,l,r) for(int i=l; i<r; i++)

int ans;
int k;

void check(const vector<int> &v){
    int sum=0;
    for(auto x: v){
        sum+=x;
    }

    if(sum%k==0) ans++;
}

bool safe(int i, int j, int n, int m){
    return i>=0 && j>=0 && i<n && j<m;
}


void dfs(int sx, int sy, int n, int m,  vector<int> &v, vector<vector<int>> &grid){
   

   v.push_back(grid[sx][sy]);
     
   if(sx==n-1 && sy==m-1){
    check(v);
   }
   int xdir[]={0,1};
   int ydir[]={1,0};

   for(int i=0; i<2; i++){
        if(safe(sx+xdir[i], sy+ ydir[i],n,m)){
            dfs(sx+xdir[i], sy+ ydir[i],n,m, v, grid);
        }
   }

   v.pop_back();
}

void solve(){
    int n,m; cin>>n>>m>>k;
    ans=0;

    vector<vector<int>> grid(n, vector<int>(m));
    loop(i,0,n) loop(j,0,m) cin>>grid[i][j];
    vector<int> v;
    dfs(0,0,n,m, v,grid);

    cout<<ans<<endl;

}

int32_t main(){
   
    solve();

    return 0;
}