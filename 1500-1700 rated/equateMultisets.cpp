/*
problem link->
https://codeforces.com/problemset/problem/1702/F
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
    take_n
    int a[n],b[n];
    loop(i,0,n) cin>>b[i];
    loop(i,0,n) cin>>a[i];

    unordered_map<int, int> mpb;
    unordered_map<int, int> mpa;
    for(int i=0;i<n; i++) mpb[b[i]]++;
    for(int i=0;i<n; i++) mpa[a[i]]++;

    for(int i=0;i<n; i++){

        //increment the element
        for(int j=0; j<=30; j++){
            if(mpb.find(a[i]*pow(2,j))!=mpb.end()){
                mpb[a[i]*pow(2,j)]--;
                mpa[a[i]]--;  
            }
        }

        //decrement the element 
         int x=a[i];
        for(int j=1;j<=30; j++){
            x/=2;
            if(mpb.find(x)!=mpb.end()){
                mpb[x]--;
                mpa[a[i]]--;
            }
        }
    }

    for(auto x: mpa) if(x.second>0){
        cout<<"b"<<" "<<x.first;
        cout<<"NO"<<endl;
        return;
    }
     for(auto x: mpb) if(x.second>0){
        cout<<"a"<<" "<<x.first;
        cout<<"NO"<<endl;
        return;
    }

    cout<<"YES"<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}