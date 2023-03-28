/*
problem link ->
https://codeforces.com/problemset/problem/1579/C
*/

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
    int n,m,k; cin>>n>>m>>k;

    vector<vector<char>>v(n,vector<char>(m));
    loop(i,0,n) loop(j,0,m) cin>>v[i][j];
    
    vector<vector<bool>> vis(n,vector<bool>(m,0));

    for(int i=n-1; i>=0; i--){
        for(int j=m-1; j>=0;j--){
            if(v[i][j]=='*'){
            
              int h=1;
              while(i-h>=0 && j-h>=0 && j+h<m){
                if(v[i-h][j-h]=='*' && v[i-h][j+h]=='*'){
                  vis[i-h][j-h]=1;
                  vis[i-h][j+h]=1;
                  h++;
                }
                else{
                  
                    break;
                }
                    }
                  h--;
              
              if(vis[i][j]) continue;
              else{
                if(h<k){
                    cout<<"NO"<<endl;
                    return;
                }
                vis[i][j]=1;
              }
               
            }
        }
    }

    cout<<"YES"<<endl;
    
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}