/*
problem link->
https://codeforces.com/contest/1789/problem/C
*/

/*
um_nik solution
initially tried with dp, but couldn't solve
combinatorics problem
*/

/*
total elements ever seen - sum over x [c[x] choose 2]
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

int c[500000]; 
 
void solve(){

    int n,m;
    cin>>n>>m;
    int a[n];//current lot
    int b[n];//last change of each idx
    loop(i,1,n+m+1){
        c[i]=0;
    }

    loop(i,0,n){
       cin>>a[i];
       b[i]=0;
    }

    loop(i,1,m+1){
        int x; cin>>x;
        x--;
        c[a[x]]+= i-b[x];
        b[x]=i;
        cin>>a[x];
    }

    loop(i,0,n){
        c[a[i]]+= m+1-b[i];
    }

    int ans= (m+1)*m/2* (2*n);
    //2*n total in each pair

    loop(i,1,n+m+1){
        ans-= c[i]*(c[i]-1)/2;

        //remove intersections in contiguous arrays
    }

    cout<<ans<<endl;
    

}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}