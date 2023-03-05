/*
problem link ->
https://codeforces.com/problemset/problem/1740/C
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
    take_arr

    sort(arr, arr+n);

    int ans=-1;

    loop(i,0,n){
        //w2=a[i] //w[3]=optimal(a[n],a[0])
        //w1=unoptimal of(a[i-1], a[i+1])
        int temp=0;

        if(i==0){

            temp+= arr[n-1]-arr[0];
            temp+=arr[1]-arr[0];

        }
        else if(i==n-1){
           
           temp+=arr[n-1]-arr[n-2];
           temp+=arr[n-1]-arr[0];
        }
        else{
            temp+=max(arr[n-1]-arr[i], arr[i]-arr[0]);
            temp+=min(arr[i]-arr[i-1], arr[i+1]-arr[i]);
        }

        ans=max(ans, temp);
    }

    cout<<ans<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}