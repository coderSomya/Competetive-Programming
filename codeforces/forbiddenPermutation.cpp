/*
problem link -
https://codeforces.com/problemset/problem/1778/B
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

    int n,m,d;
    cin>>n>>m>>d;

    take_arr
    int a[m];
    loop(i,0,m) cin>>a[i];

    umpii pos;

    loop(i,0,n) pos[arr[i]]=i;

    vi res;
    loop(i,0,m-1){
        int diff= pos[a[i+1]]-pos[a[i]];
        res.pb(diff);
    }

    sort(res.begin(), res.end());

    if(res[0]<=0 || res[m-2]>d){
        cout<<"0"<<endl;
        return;
    }

    //kisko aage/piche kar skte hain

 int mini= 1e9;

   loop(i,0,m-1){
      //a[i+1] ko aage shift kro so that d se zda ho jaye dist
      //a[i] ko piche shift kro so that d se zda ho jaye dist
      //a[i+1] ko a[i] ke just piche le aao hai naa

      //pos[a[i+1]]-pos[a[i]] -y =d+1
      int temp= pos[a[i+1]]-pos[a[i]];
      int x= d+1-(pos[a[i+1]]-pos[a[i]]);

      if(n-1- pos[a[i+1]]+pos[a[i]] >=x) temp=min(temp,x);
      
      if(pos[a[i+1]]+x <n || pos[a[i]]-x>=0) temp=min(temp, x);

      //-pos[a[i]]+r1 + pos[a[i+1]]+r2 = d+1

      mini=min(temp, mini);

   }

   cout<<mini<<endl;

}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}