/*
problem link->
https://codeforces.com/problemset/problem/1734/D
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
   int n,k; cin>>n>>k;

   int arr[n+2];
   for(int i=1; i<=n; i++){
    cin>>arr[i];
   }
   //start from the right
   int l=k-1; int h=k+1;
   int curr=arr[k];
   while(h<n+1 && l>0){
    if(h<=n && curr+arr[h]<0) break;
      while(h<=n && curr+arr[h]>=0){
       curr+=arr[h];
       h++;
      }
      while(l>0 && curr+arr[l]>=0){
        curr+=arr[l];
        l--;
      }
      
   }

   if(h==n+1 || l==0){
    cout<<"YES"<<endl;
    return;
   }


   //start from the left

   l=k-1; h=k+1;
   curr=arr[k];
   while(l>0 && h<n+1){
    if(l>0 && curr+arr[l]<0) break;
    while(l>0 && curr+arr[l]>=0){
        curr+=arr[l];
        l--;
      }
    while(h<=n && curr + arr[h]>=0){
       curr+=arr[h];
       h++;
      }
   }

   if(h==n+1 || l==0){
    cout<<"YES"<<endl;
    return;
   }

   cout<<"NO"<<endl;

}

int32_t main(){
    int t; cin>>t;
    while(t--) solve();


    return 0;
}