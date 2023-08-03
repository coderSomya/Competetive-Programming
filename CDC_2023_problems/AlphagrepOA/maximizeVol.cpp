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

int bs( vector<pair<int,pair<int,int>>> &vv, int val){

    int l=0; int h=vv.size()-1;

    int ans=h+1;

    while(l<=h){
        int mid=(l+h)/2;

        if(vv[mid].first>=val){
            ans=mid;
            h=mid-1;
        }
        else l=mid+1;
    }


    return ans;

}

int rec(int i, vector<pair<int,pair<int,int>>> &vv, int n){

    if(i==n) return 0;

    int temp= rec(i+1, vv, n);

    int idx=bs(vv, vv[i].first+vv[i].second.first);

    return max(temp, rec(idx, vv, n)+vv[i].second.second);
}


 
void solve(){

    int n; cin>>n;

    int s[n], d[n], v[n];

    loop(i,0,n) cin>>s[i];
    loop(i,0,n) cin>>d[i];
    loop(i,0,n) cin>>v[i];

    vector<pair<int,pair<int,int>>> vv;
    loop(i,0,n) vv.push_back({s[i],{d[i], v[i]}});

    sort(vv.begin(), vv.end());

    int ans = rec(0, vv, n);

    cout<<ans<<endl;


}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}