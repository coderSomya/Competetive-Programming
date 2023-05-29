/*
problem link ->
https://codeforces.com/problemset/problem/1622/C
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int inf= 1e14;

void solve(){
    int n,k; cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

  sort(arr, arr+n);
   int suff[n+1]; suff[n]=0;
   for(int i=n-1; i>=0; i--) suff[i]=suff[i+1]+arr[i];
   int ans= 2*inf;
   int curr=suff[0];
   int req=curr-k;
   for(int r=0; r<n; r++){
       
    int l=0; int h=1e9;

    while(l<=h){
        int mid=(l+h)/2;

        int mini=arr[0]-mid;
        int decrement= suff[n-r]-(mini*r) + mid;

        if(decrement>=req){
            ans=min(ans, mid+r);
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }



   }

   
    cout<<ans<<endl;
    

}


int32_t main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}