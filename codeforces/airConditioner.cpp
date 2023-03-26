/*
problem link ->
https://codeforces.com/problemset/problem/1547/E
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
    int n,k; cin>>n>>k;

    vi v(k); vi t(k);
    loop(i,0,k) cin>>v[i];
    loop(i,0,k) cin>>t[i];

    vector<pair<int,int>>x;
    loop(i,0,k) x.pb({v[i], t[i]});
    sort(x.begin(), x.end());
    x.pb({n+5, 2439393});

    int itr=0;

    vi left(n+1); left[0]=inf;

    loop(i,1,n+1){
        if(x[itr].first==i){
            left[i]=min(left[i-1]+1, x[itr].second);
            itr++;
        }
        else{
            left[i]=left[i-1]+1;
        }
    }

    x.pop_back();
    vi right(n+2); right[n+1]=inf;
    int itf=k-1;
    for(int i=n; i>0; i--){
        if(itf>=0 && x[itf].first==i){
            right[i]=min(right[i+1]+1, x[itf].second);
            itf--; 
        }
        else{
            right[i]=right[i+1]+1;
        }
    }

    loop(i,1,n+1) cout<<min(right[i], left[i])<<" ";
    cout<<endl;


}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}