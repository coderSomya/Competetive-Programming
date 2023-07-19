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
 
int n,m,k; 

int sum(int r){
    return r*(r+1)/2;
}

bool check(int s){
    int mini, maxi;
    mini=0;
    maxi=s*n;
    if(k>=s){
        mini+=sum(s);
        mini+=k-s;
    }
    else{
       mini+=sum(s);
       mini-=(s-k);
    }

    if(n-k>=s-1){
       mini+=sum(s-1);
       mini+=n-k-s+1;
    }

    else{
       mini+=sum(s-1);
       mini-=sum(s-1-(n-k));
    }

    return m>=mini && m<=maxi;
}

void solve(){
   cin>>n>>m>>k;

   int l=1; int h=m;
   
   int ans=1;

   while(l<=h){
    int mid= (l+h)/2;

    if(check(mid)){
        ans=mid;
        l=mid+1;
    }
    else{
        h=mid-1;
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


/*

1 1 1 2 3 4 5 .. s s-1 s-2.. 1 1 1

minimum
= r + s*(s+1)/2 + s*(s-1)/2 + p



*/