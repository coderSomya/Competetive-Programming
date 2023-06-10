#include <bits/stdc++.h>
using namespace std;
#define loop(i,l,r)     for(int i=l; i<r; i++)
#define int             long long
#define pb              push_back
#define vi              vector<int>
#define mkp             make_pair<int,int>
#define umpii           unordered_map<int,int>
#define maxheap         priority_queue<int>
#define minheap         priority_queue<int, vi,greater<int>>
#define setbits(x)      __builtin_popcountll(x)
#define zerobits(x)     __builtin_ctzll(x)
#define in_arr(A,n)     loop(i,0,n) cin>>A[i];
#define p_arr(A,n)      loop(i,0,n) cout<<A[i]
;
#define pln_arr(A,n)    loop(i,0,n) cout<<A[i]<<endl
#define take_n          int n; cin>>n;
#define take_arr        int arr[n]; loop(i,0,n) cin>>arr[i];
  
  
const int mod= 1e9+7;
const int inf= 1e15;

bool safe(int x, int y, int n, int m){
  return x>=0 && y>=0 && x<n && y<m;
} 

 
void solve(){
    int n,m,q; cin>>n>>m>>q;

    int grid[n][m];
    
   
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) cin>>grid[i][j];

    vector<vector<pair<int, int>>>v(100005);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int x=grid[i][j];
            v[x].push_back({i,j});
        }
    }


    while(q--){
        int srcx, srcy, dstx, dsty;
        cin>>srcx>>srcy>>dstx>>dsty;
        srcx--; srcy--; dstx--; dsty--;

    
        vector<vector<int>> mpp(n, vector<int>(m,-1));
  
        mpp[srcx][srcy]=0;
        queue<pair<int,int>>q;
        q.push({srcx,srcy});
       bool flag=false;
        while(!q.empty()){

            pair<int,int> curr=q.front();
            q.pop();
            int dist=mpp[curr.first][curr.second];
            //int dist=mpp[curr.first][curr.second]
            
            if(dist>4) break;
            if(curr.first==dstx && curr.second==dsty){
                flag=true;
                break;
            }
             int xdir[]={-1,1,0,0};
             int ydir[]={0,0,-1,1};
             for(int k=0; k<4; k++){
             int x=curr.first+xdir[k];
             int y=curr.second+ydir[k];
             if(safe(x,y, n, m)){
                //if(mpp[x][y]!=-1)
                if(mpp[x][y]==-1){
            mpp[x][y]=dist+1;
                q.push({x,y});
                }
                
             }
             }
             //push factors
             int val=grid[curr.first][curr.second];

             for(int i=1; i*i<=val; i++){
                  
                  if(val%i==0){
                    for(auto x: v[i]){
                        if(mpp[x.first][x.second]==-1){
                            q.push(x);
                            mpp[x.first][x.second]=dist+1;
                        }
                    }

                    for(auto x: v[val/i]){
                         if(mpp[x.first][x.second]==-1){
                            q.push(x);
                            mpp[x.first][x.second]=dist+1;
                        }
                    }
                  }
             }
             //factors done
            
        }

      if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
   
         } 
        
         }

 
  
int32_t main(){
// int t;
// cin>>t;
// while(t--) 
solve();
return 0;
}