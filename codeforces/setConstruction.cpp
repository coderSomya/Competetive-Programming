/*
problem link ->
https://codeforces.com/problemset/problem/1761/C
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
 
vector<vector<int>> g(102);
vector<int> indegree(102);
void solve(){
   
   take_n
   g.clear();
   indegree.clear();
   g.resize(n+1);
   indegree.resize(n+1);

   loop(i,1,n+1) {
   
    string s; cin>>s;
    for(int j=1; j<n+1; j++){
        int x=s[j-1]-'0';
    if(x==1) {
        g[i].pb(j);
        indegree[j]++;
    }
    }
   }

  

   queue<int> q;
   loop(i,1,n+1){
    if(indegree[i]==0) q.push(i);
   }

   unordered_map<int, int> mp;


   int d=1;
   while(!q.empty()){
    int x= q.front();
   mp[x]=d; d++;
   q.pop();

    for(auto y: g[x]){
        indegree[y]--;
        if(indegree[y]==0) q.push(y);
    }
   }
   
   for(int i=1; i<n+1; i++){
    cout<<mp[i]<<" ";
    for(int j=1; j<=mp[i]; j++){
        cout<<j<<" ";
    }
    cout<<endl;
   }
   
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}