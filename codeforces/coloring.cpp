/*
problem link ->
https://codeforces.com/problemset/problem/1774/B
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
    int n,m,k; cin>>n>>m>>k;
    
    int arr[m];
    loop(i,0,m) cin>>arr[i];
    sort(arr, arr+m);


    int a =n/k;int b=n%k; int c=0;
    
    int i=0;
    while(m-1-i>=0 && b>0){
      arr[m-1-i]--;
      b--; i++;
    }

    

    loop(i,0,m){
        if(arr[i]>a){
            cout<<"NO"<<endl;
            return;
        }
        else if(arr[i]==a){
          c++;
        }
    }

  if(c>a){
    cout<<"NO"<<endl;
  }
  else cout<<"YES"<<endl;

}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}