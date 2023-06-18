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
    string s, t;
    cin>>s>>t;

    //aage se
    int ans1=0;
    for(int i=0; i<n; i++){
        ans1+= (s[i]!=t[i]);
    }

    if(ans1==0) {
        cout<<0<<endl; return;
    }

    if((ans1-1 )%2){
        ans1= 2*ans1;
    }
    else ans1 = 2*ans1-1;

    int ans2=0;
    for(int i=0; i<n; i++){
        ans2+= (s[i]!=t[n-1-i]);
    }

    ans2=max(ans2, (int)1);

     if((ans2-1)%2){
        ans2=2*ans2-1;
    }
    else ans2=2*ans2;

    cout<<min(ans1,ans2)<<endl;


}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}