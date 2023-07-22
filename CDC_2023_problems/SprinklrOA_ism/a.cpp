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
 
int timer=1;
vector<int> arti;

void dfs(int src, int par, vector<int> &vis, vector<vector<int>> &adj, int tin[], int low[]){
    vis[src]=1;
    tin[src]=low[src]=timer++;

    int child=0;

    for(auto x: adj[src]){
        if(x!=par) continue;

        if(vis[x]){
            low[src]=min(low[src], tin[x]);

            if(low[x]>=tin[src] && par!=0){
                arti.push_back(src);
            }
        }
        else{
            child++;
           dfs(x, src, vis, adj, tin,low);

           low[src]=min(low[src], low[x]);

           if(low[x]>=tin[src] && par!=0){
            arti.push_back(src);
           }
        }
    }

    if(par==0 && child>1) arti.push_back(1);
}
 
void solve(){

    int n,m; cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<int> vis(n+1);
    int tin[n+1];
    int low[n+1];

    vector<int> val(n+1, 0);
    for(int i=1; i<=n; i++) cin>>val[i];

    dfs(1,0,vis,adj,tin,low);

    unordered_map<int,int> mp;
    for(int i=1; i<=n; i++){
        mp[low[i]]+=val[i];
    }

    if(arti.empty()){
        sort(val.begin(), val.end());
        int p=0;
        for(int i=2; i<=n; i++) p+=val[i];

        cout<<"Alice=0"<<endl;
        cout<<"Bob="<<p<<endl;
        return;
    }

    int x= mp.size();
    vector<int> v(x+1,0);
    for(int i=1; i<=x; i++){
           v[i]=mp[i];
    }

    for(int i=1; i<=x;i++) v[i]+=v[i-1];

    int alice=-1, bob=-1;

    int total=v[x];

    for(auto x: arti){
         int temp = min(v[x-1], total- v[x-1]- val[x]);

         if(temp>alice){
            alice=temp;
            bob=max(v[x-1], total-v[x-1]- val[x]);
         }

         else if(temp==alice){
            if(max(v[x-1], total-v[x-1]-val[x]) >bob){
                bob=max(v[x-1], total-v[x-1]-val[x]);
                alice=temp;
            }
         }
    }

    cout<<"Alice="<<alice<<endl;
    cout<<"Bob="<<bob<<endl;

}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}