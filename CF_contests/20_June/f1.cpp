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
 

void solve(){

    take_n
vector<vector<int>> nodes(n+1, vector<int>(4,0));

    // vector<vector<Node>> adj(n+1);

    nodes[1]={1,0,0,1};
    int ct=1;

    while(n--){
        char ch; cin>>ch;
        if(ch=='+'){
            ct++;
            int v, x; cin>>v>>x;
            if(x==1){
              nodes[ct][3]=nodes[v][3]+1;
              nodes[ct][2]=nodes[v][2]+1;
              nodes[ct][1]=nodes[v][1];
              nodes[ct][0]=max(nodes[v][0], nodes[ct][3]);
}
            else{
              nodes[ct][3]=nodes[v][3]-1;
              nodes[ct][2]=nodes[v][2]-1;
              nodes[ct][1]=min(nodes[v][1], nodes[ct][2]);
              nodes[ct][0]=nodes[v][0];

            }
        }

        else{
            int u,v,k;
            cin>>u>>v>>k;
            
            if(k<=nodes[v][0] && k>=nodes[v][1]){
                cout<<"YES"<<endl;
            }
            else cout<<"NO"<<endl;
        }
    }



}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}