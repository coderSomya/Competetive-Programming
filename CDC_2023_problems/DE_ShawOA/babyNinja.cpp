/*
https://leetcode.com/discuss/interview-question/710709/de-shaw-oa
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

void buildST(vector<pair<int,int>> &ST, vector<int> &arr, int ss, int se, int stidx){
    if(ss>se) return;

    else if(ss==se) {
        ST[stidx]={arr[ss],ss};
        return;
    }

    int mid = (ss+se)/2;

    buildST(ST, arr, ss, mid, 2*stidx+1);
    buildST(ST, arr, mid+1, se, 2*stidx+2);

    if(ST[2*stidx+2].first > ST[2*stidx+1].first){
        ST[stidx] = ST[2*stidx+2];
    }

    else ST[stidx]= ST[2*stidx+1];
}


pair<int,int> query(vector<pair<int,int>> &ST,  int ss, int se, int ql, int qr, int stidx){
  
  if(ss>qr || se<ql) return {-inf, -1};

  if(ss>=ql && se<=qr){
    return ST[stidx];
  }

  int mid=(ss+se)/2;

  pair<int,int> left= query(ST, ss, mid, ql , qr, 2*stidx+1);
  pair<int,int> right= query(ST,  mid+1, se, ql , qr, 2*stidx+2);

  return max(left, right);
}


 
void solve(){
    int n; cin>>n;
    int k; cin>>k;
    int c; cin>>c;
    
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    int l=1; int r=0;

    int curr=c;
     int ans=c;

     vector<pair<int,int>> ST(4*n+1);
     buildST(ST, arr, 0, n-1, 1);
     

    while(r<n){
        if(r-l>=k){
            pair<int,int> res = query(ST,0, n-1, l+1, r, 1);
            l= res.second;
            if(curr+arr[l]<0) break;
            else curr+=arr[l];
        }

        if(arr[r]>0) curr+=arr[r];
        r++;

        ans=max(curr, ans);
    }


    cout<<ans<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}