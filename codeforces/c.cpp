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

int n; 
int ans;
const int N = 20;
int arr[N];

void calc(int mask, int n){

    vector<int> v(n);
    v[0]=arr[0];
  
  for(int i=1; i<n-1; i++){
    if(((mask&(1<<i)) !=0 ) && v[i-1]%2==0 && arr[i+1]%2==0){
        v[i]=(v[i-1]+arr[i+1])/2;
    }
    else v[i]=arr[i];
  }
  v[n-1]=arr[n-1];

  int t1,t2;
  t1=t2=0;

  for(int i=0; i<n/2; i++)
  {
    t1+=v[i];
  }

  for(int i=n/2; i<n; i++){
    t2+=v[i];
  }

  if(n%2){
    t2-=v[n/2];
  }

//   ans=max(ans, abs(t1-t2));
if(abs(t1-t2)>ans){
    ans=abs(t1-t2);
    // cout<<mask<<endl;
    // for(auto x: v) cout<<x<<" ";
    // cout<<endl;
}
}

void rec(int i, int mask){
    if(i==n){
        calc(mask, n);return;
    }

    int m1=(mask<<1);
    int m2=m1+1;

    rec(i+1, m1);
    rec(i+1, m2);
}
 
void solve(){

    cin>>n;
    for(int i=0; i<n; i++) cin>>arr[i];
    ans=0;

    rec(0,0);

    cout<<ans<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}