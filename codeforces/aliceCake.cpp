/*
problem link ->
https://codeforces.com/problemset/problem/1654/C
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
    umpii mp; int sum=0;
    loop(i,0,n){
        int x; cin>>x; mp[x]++;
        sum+=x;
    }
    queue<int> q; q.push(sum); 
    while(n>1){
       if(q.size()>n) {
        cout<<"NO"<<endl; return;
       }
      
      int x= q.front(); q.pop();

         if(mp.find(x)!=mp.end()){
            mp[x]--; if(mp[x]==0) mp.erase(x); n--; 
         }
         else{
            
            q.push(x/2); q.push((x+1)/2);
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