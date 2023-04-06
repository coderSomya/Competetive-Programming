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
 
bool parity(int a, int b) {
    return a%2 == b%2;
}
void solve(){
    int n,k; cin>>n>>k;
    if(parity(n,k)){
        cout<<"YES"<<endl;
    }
    else{
       if(n%2==0){
        cout<<"YES"<<endl;
       }
        else{
            cout<<"NO"<<endl;
        }
    }

}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}