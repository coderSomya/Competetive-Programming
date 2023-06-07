/*
problem link->
https://codeforces.com/contest/1520/problem/F2
*/

//caching approach

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
 
map<pair<int,int>, int> cache;

void dec(int pos, int l, int r){
    cache[{l,r}]--;

    if(l!=r){
        int mid=(l+r)/2;
        if(pos<=mid){
            dec(pos,l,mid);
        }
        else{
            dec(pos,mid+1,r);
        }
    }

}




int dist(int a, int b) {
    return b-a+1;
}

int query(int l, int r){
    cout<<"?"<<" "<<l<<" "<<r<<endl;

    int res; cin>>res;

    return res;

}
 
void solve(){

    int n,t;
    cin>>n>>t;

    while(t--){
        int k; cin>>k;

        int l=1; int r=n;
        int ans=0;

        while(l<r){
            int mid=(l+r)/2;

            pair<int,int> range={l,mid};
            if(cache.find(range)==cache.end()){
                int res= query(l,mid);

                cache[range]=dist(l,mid)-res;
            }

            int value=cache[range];
            if(k<value){
                r=mid-1;
            }
            else{
                ans=mid;
                l=mid;
                k-=value;
            }

        }

        cout<<"!"<<" "<<ans<<endl;
        dec(ans,1,n);
    }

}
  
  
int32_t main(){

solve();
return 0;
}