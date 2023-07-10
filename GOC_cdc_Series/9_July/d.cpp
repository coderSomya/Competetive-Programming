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

int n;
int MAXI;

double dp[16][(1<<16)-1][16];
// double maxi;

vector<pair<int,int>> points;

double dist(int i, int j){
    int x1=points[i].first;
    int y1=points[i].second;
    int x2=points[j].first;
    int y2=points[j].second;
  setprecision(8);
    double dis = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    // cout<<dis<<endl;
    return dis;

}

int src;

double rec(int i, int mask, int src){
    if(mask==MAXI) return dp[i][mask][src]= dist(i,src);
    if(i==n) return dp[i][mask][src] = inf*(1.000);
   double res= inf*(1.0000);

   if(dp[i][mask][src]>=-1.000) return dp[i][mask][src];
    for(int j=0; j<n; j++){
        // cout<<(mask&(1<<j))<<endl;
        if((mask&(1<<j))==0){
            // cout<<"here"<<endl;
            int temp_mask=mask|(1<<j);
            res=min(dist(i,j)+rec(j,temp_mask, src), res);
        }
    }

    return dp[i][mask][src] = res;
}


 
void solve(){
     cin>>n;

    points.clear();
    
    for(int i=0; i<n; i++){
      for(int j=0; j<((1<<n)-1); j++)
      {
        for(int k=0; k<n; k++)
        dp[i][j][k]=-2.0000;
      }
    }
  
    for(int i=0; i<n; i++){
        int x; int y;
        cin>>x>>y;
        points.push_back({x,y});
    }
  
    int mask=0;
    MAXI = (1<<n)-1;

    double ans=inf*(1.0000);
    // cout<<ans<<endl;
    for(int i=0; i<n; i++){
        int new_mask= mask | (1<<i);
        //  cout<<new_mask<<endl;
        src=i;
        ans=min(ans, rec(i,new_mask, i));
    }


    cout<<floor(ans)<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}