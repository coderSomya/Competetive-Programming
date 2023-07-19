/*
problem link-
https://www.desiqna.in/13290/atlassian-oa-sde-2023
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

int ncr(int n, int r){

    if(r==1) return n;

    else if(r==2) return 1ll*n*(n-1)/2;

    else return 1ll*n*(n-1)*1ll*(n-2)/6;

}
 
 
void solve(){

    int n; cin>>n;
    vector<int> arr(n);

    loop(i,0,n) cin>>arr[i];

    vector<pair<int,int>> v(30, {0,0});

    //v[i] = {ones, zeroes}

    for(int i=0; i<n;i++){
        for(int bit=0; bit<30; bit++)
        {
            if(arr[i]& (1<<i)) v[bit].first++;
            else v[bit].second++;
        }
    }

    int ans=0;
    
    for(int bit=0; bit<30; bit++){
        int temp= ncr(v[bit].first, 3)+ ncr(v[bit].first, 1)*ncr(v[bit].second, 2);

        ans+= (1<<bit)*temp;
    }

    cout<<ans<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}