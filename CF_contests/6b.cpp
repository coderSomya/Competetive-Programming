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

    int n,k; cin>>n>>k;
    int arr[n+1];
    loop(i,1,n+1) cin>>arr[i];
    vector<set<int>> v(k+1);
 
    for(int i=1; i<n+1; i++){
        if(i%k==0) v[k].insert(arr[i]);
        else v[i%k].insert(arr[i]);
    }

    // loop(i,0,k+1){
    //     for(auto x: v[i]) cout<<x<<" ";
    //     cout<<endl;
    // }

    int ct=0;

    for(int i=1; i<k+1; i++){
        //check the set of i
        //i, i+k,i+2k...should be present
        int p=v[i].size();
        for(int j=0; j<p; j++){
            if(v[i].find(i+j*k)==v[i].end()) ct++;
        }

    }

    if(ct==0){
        cout<<"0"<<endl;
    }
    else if(ct==2){
        cout<<"1"<<endl;
    }
    else{
        cout<<-1<<endl;
    }

}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}