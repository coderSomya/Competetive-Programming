/*
problem link -
https://codeforces.com/problemset/problem/1788/C
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
  int n,q;
  cin>>n>>q; 
  take_arr
  int sum=0;
  loop(i,0,n) sum+=arr[i];

  vector<pair<int, set<int>>>v;

  while(q--){
    int t; cin>>t;
    if(t==1){
       
       int idx; cin>>idx; idx--;
       int x; cin>>x; 
       //arr[idx] might have been changed
       //we need to know if there is a change 
       if(!v.empty()){
         int p=v.back().first;
         if(v.back().second.find(idx)!=v.back().second.end()){
            sum-=arr[idx];
          sum+= x;
         
         }
         else{
            sum-=v.back().first;
            sum+=x;
            v.back().second.insert(idx);
           
         }

       }
       else{
        sum-=arr[idx];
           sum+= x;
       }
      
       arr[idx]=x;
       
       cout<<sum<<endl;
    }
    else{
      int all; cin>>all;
      sum= n*all; set<int>st;
      v.pb({all, st});
      cout<<sum<<endl;
    }
  }

}
  
  
int32_t main(){
// int t;
// cin>>t;
// while(t--) 
solve();
return 0;
}