/*
problem link->
https://codeforces.com/problemset/problem/1519/C
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
    take_n
    int team[n],strength[n]; 
    for(int i=0; i<n; i++) cin>>team[i];
    loop(i,0,n) cin>>strength[i];

    vector<vector<int>>v(n+1);
    
    loop(i,0,n){
        v[team[i]].pb(strength[i]);
    }

    for(int i=0; i<=n; i++){
        sort(v[i].rbegin(), v[i].rend());
        for(int j=1; j<v[i].size(); j++) v[i][j]+=v[i][j-1];
    }

  

    vector<int> k(n+1, 0);
    for(int i=1; i<=n; i++){
        unordered_set<int> st;
        if(v[i].size()==0)continue;
        for(int j=v[i].size()-1; j>=0; j--){
            for(int l=1; l*l<=(j+1); l++){
          if((j+1)%l==0){
            if(st.find(l)==st.end()){
                 st.insert(l);
                 k[l]+=v[i][j];
            }
            if(st.find((j+1)/l)==st.end()){
                st.insert((j+1)/l);
            k[(j+1)/l]+=v[i][j];
            }
          }
            }
        }
    }

    for(int i=1; i<=n; i++) cout<<k[i]<<" ";
    cout<<endl;

}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}