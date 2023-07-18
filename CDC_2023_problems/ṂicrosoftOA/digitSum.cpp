/*
https://www.desiqna.in/13267/microsoft-coding-oa-sde-1-may-3-2023
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
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    sort(v.begin(), v.end());

    vector<vector<int>> freq(100);

    for(auto x: v){
        int dig_sum=0;

        int y=x;
        while(y!=0){
            int rem= y%10;
            y/=10;
            dig_sum+=rem;
        }

        freq[dig_sum].push_back(x);
    }

   int ans=-1;
    for(int i=0; i<100; i++){
         if((int)freq[i].size() >=2){
            int a=freq[i].back();
            freq[i].pop_back();
            int b=freq[i].back();

            ans=max(ans, a+b);
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