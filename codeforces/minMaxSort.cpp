/*
problem link -
https://codeforces.com/problemset/problem/1792/C
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
    take_arr

    //1 2 3 4 5 6
    


    umpii mp;
    loop(i,0,n) mp[arr[i]]=i+1;

    int ans=0;

    if(n%2){
        int pivl=mp[(n+1)/2];
        int pivr=mp[(n+1)/2];
    int l=(n+1)/2;
    int r= (n+1)/2;
      while(l>=0){
     
        if(mp[l]<=pivl && mp[r]>=pivr){
            pivl=mp[l]; pivr=mp[r];
         l--; r++;
         
        }
        else{
            // cout<<l<<" here"<<endl;
             ans=l;
             break;
        }
      }

    }
    else{
  
     int l=n/2; int r= n/2+1;
       int pivl=mp[l]; int pivr=mp[r];
       if(pivl>pivr){
        cout<<n/2<<endl;
        return;
       }
      while(l>=0){
        if(mp[l]<=pivl && mp[r]>=pivr){
 pivl=mp[l]; pivr=mp[r];
         l--; r++;
        }
        else{
             ans=l;
             break;
        }
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