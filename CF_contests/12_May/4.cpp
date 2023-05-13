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

    int n,q;
    cin>>n>>q;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    sort(arr.begin(), arr.end());
    
    while(q--){
        vector<int> v(arr);
        int k; cin>>k;
        int ans;
        int mini=1;
        if(n==1){
             if(k%2){
            cout<<k/2+1+v[0]<<endl;
            continue;
           }
           else{
            cout<<v[0]-k/2<<endl;
            continue;
           }
        }
        k-=2*(v[1]-v[0])-1;
        if(k>=0) {
            v[0]=v[1];
        mini++;
        }

        while(mini<n && k>0){
           k-=2*((v[mini]-v[mini-1])*mini);
           if(k>=0){
           v[mini]=v[mini+1]; mini++;
           } 
        }
        if(k>0){
            ans=v[n-1]+k/(2*n);
        }

        ans=v[mini-1];

        cout<<ans<<endl;
    }
}
  
  
int32_t main(){
// int t;
// cin>>t;
// while(t--) 
solve();
return 0;
}