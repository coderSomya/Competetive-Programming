/*
problem link->
https://codeforces.com/problemset/problem/1801/B
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
 
vi a,b;
int n;
int mini= 2e9;

//find smallest diff
//find second smallest diff

int low(int i){
    //last lowest
    int ans=-1;

    int l=0; int h=n-1;

    while(l<h){
        int mid=(l+h)/2;

        if(b[mid]<=a[i]){
            ans=mid;
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }

    return ans;

}

int high(int i){
    //first highest

        int ans=n+8;

    int l=0; int h=n-1;

    while(l<h){
        int mid=(l+h)/2;

        if(b[mid]>=a[i]){
            ans=mid;
            h=mid-1;
        }
        else{
            h=mid-1;
        }
    }

    return ans;
    
}


void solve(){
   cin>>n;
    umpii freq;
    a.clear(); b.clear();
    loop(i,0,n){
        int x,y; cin>>x>>y;
        a.pb(x); b.pb(y);
        freq[y]++;   
    }

    vi c= b;
    int ans=2e9;
    
    sort(b.begin(), b.end());
  
    //check for each i
   loop(i,0,n){
   
    set<int>st;
     int x= low(i);
     int y=high(i);

     if(x!=-1){
        st.insert(b[x]);
        x--;
     }
     if(x!=-1) st.insert(b[x]) ;

     if(y<n) {
        st.insert(b[y]);
        y++;}

    if(y<n) st.insert(b[y]);
  
  for(auto x: st)
   {
    if(c[i]==x && freq[x]==1) continue;

    ans=min(ans, abs(x-a[i]));
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