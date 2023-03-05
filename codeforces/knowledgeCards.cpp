/*
problem link ->
https://codeforces.com/problemset/problem/1740/D
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


void print(int a){
    if(a) cout<<"YA"<<endl;

    else cout<<"TIDAK"<<endl;
}
 
void solve(){
   
   int n,m,k;
   cin>>n>>m>>k;

   int c=0;
   vi v(k);
   loop(i,0,k) cin>>v[i];
   int search=k;
   int t=n*m-3;
   maxheap mh;
   int i=0;
   int target=k+1;
   loop(i,0,k){
    int x=v[i];

    if(mh.size()==t){
        
        while(mh.size() && mh.top()==target-1){
            target--;
            mh.pop();
        }

        if(mh.size()==t){
            print(0);
            return;
        }
    }
    
    mh.push(x);
   }

   print(c<t);
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}