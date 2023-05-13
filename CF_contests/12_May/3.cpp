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
    take_arr

    vector<int> v;
    v.push_back(arr[0]);
    if(n>1) v.push_back(arr[1]);

    for(int i=2; i<n; i++){
        int x=v.back();
        v.pop_back();
        int y=v.back();
        v.pop_back();

        if((y>=x && x>=arr[i]) ||      (y<=x && x<=arr[i])){
           v.push_back(y);
           v.push_back(arr[i]);
        }
        else{
            v.push_back(y);
            v.push_back(x);
            v.push_back(arr[i]);
        }
    }

    if(v.size()==2){
        if(v[0]==v[1]) v.pop_back();
    }

    cout<<v.size()<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}