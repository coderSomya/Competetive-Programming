/*
https://www.desiqna.in/15134/amazon-oa-sde-intern-may-2023-string-popularity-movies-kumar
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

    int n; cin>>n;
    string s; cin>>s;
    int diff; cin>>diff;
    int pref[n+1]={0};

    for(int i=1; i<=n; i++){
        pref[i]=pref[i-1]+(s[i-1]=='1');
    }

   int ans=0;
   for(int i=0; i<=n; i++){
    int r=i;
    //m*n + r -diff= 2*m*pref[n]+2*r*pref[r]
    //m*n-2*m*pref[n] = 2*r*pref[r]-r+diff

    int m; 
    int x= 2*r*pref[r]- r+diff;
    int y= n-2*pref[n];
    if(y==0){
        cout<<"-1"<<endl;
        return;
    }
    if(x<0) continue;
    if(x%y==0){
        ans++;
        if(x/y==0 && r==0) ans--;
    }
    
   }
   

   cout<<ans<<endl;

}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}