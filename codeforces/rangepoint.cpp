/*
problem link -
https://codeforces.com/problemset/problem/1791/F
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

int findsum(int x){

    int res=0;

    while(x>0){
        int r= x%10;
        res+=r;
        x/=10;
    }

    return res;
}


 
void solve(){
   int n,q;
   cin>>n>>q;
   
   take_arr

   set<int>s;
   loop(i,0,n) if(arr[i]>9) s.insert(i);

   while(q--){

  int query; cin>>query;
   if(query==1){
    //do something
    int l,r; cin>>l>>r;
   
    l--; r--;
    int search=l;
    while(!s.empty()){
        auto it= s.lower_bound(search);
        if(it==s.end()||*it>r) break;

        arr[*it]=findsum(arr[*it]);
       int m= *it;
       s.erase(it);
       if(arr[m]>9) s.insert(m);
       search=m+1;

        search= *it+1;
    }
   }

   else{
    int x; cin>>x;
    x--;
    cout<<arr[x]<<endl;
   }

   }
   

}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}