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

int check(int i, int j, int k, int l){
    return max(i-j, (int)0)+ max(k-l, (int)0);
}
 
 
void solve(){

   int n,m; cin>>n>>m;
   vector<int> arr(n);
   loop(i,0,n) cin>>arr[i];
   
   int a=arr[0]; int b=arr[1];
   vi v;
   loop(i,2,n) v.pb(arr[i]);

   sort(v.begin(), v.end());
   int ans=inf;

   int l=0; int h=m-1;
   while(h<n-2){
    int temp= check(a,v[l], v[h], b);
    ans=min(ans, temp);
    l++; h++;
   }

   cout<<ans<<endl;
}
  
  
int32_t main(){
// int t;
// cin>>t;
// while(t--) 
solve();
return 0;
}