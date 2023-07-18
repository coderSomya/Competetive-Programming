/*
problem link-
https://www.desiqna.in/13806/codekaze-coding-ninjas-hardest-question-solution-mentoring
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

vi maxi, maxir;

int k;
int n,m;

bool rec(int i, int left){

    int used=(maxi[i]-left)/k;

    if(i==0){
        if(left>0) return false;

        int right=maxi[0]- (n-1-used)*k ;

        if(right>0) return false;

        return true;
    }

    bool ans= rec(i-1, left-k)|| rec(i-1, left);

    return ans;
}
 
 
void solve(){
    cin>>n>>m;
    cin>>k;
    vi A(m), B(n), H(m);

    loop(i,0,m) cin>>A[i];
    loop(i,0,n) cin>>B[i];
    loop(i,0,m) cin>>H[i];

    umpii hlt;
    for(int i=0; i<m; i++)
    {
        hlt[B[i]]=H[i];
    }

    vector<pair<int,int>> v;
    for(int i=0; i<n; i++){
        v.push_back({A[i],0});
    }

    for(int i=0; i<m; i++){
     v.push_back({B[i], 1});
    }

    sort(v.begin(), v.end());

    int c=n+m;

    maxi.resize(c,0);

    if(v[0].second==0){
        maxi[0]=0;
    }

    else maxi[0]=hlt[v[0].first];

    for(int i=1; i<c; i++){
       if(v[i].second==0){
        maxi[i]=maxi[i-1];
       }

       else{
        maxi[i]=max(maxi[i-1], hlt[v[i].first]);
       }
    }



}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}