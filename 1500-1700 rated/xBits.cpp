/*
problem link ->
https://codeforces.com/problemset/problem/1658/D1
*/

#include <bits/stdc++.h>
using  namespace std;

void solve(){
   int l,r; cin>>l>>r;
   int a[r+1];
   int maxi=log2(r)+1;
   for(int i=0; i<r+1; i++) cin>>a[i];

   int arr[maxi];
   int brr[maxi];
   for(int i=0; i<maxi;i++){
    for(int j=0;j<=r; j++){
        if(j&(1<<i)==0) arr[i]++;
    }
   }

   //arr[i]= no. of elements in 0...r that have ith bit set

   for(int i=0; i<maxi; i++){
    for(int j=0;j<=r; j++){
        if(a[j]&(1<<i)==0) brr[i]++; 
    }
   }

   int ans=0;
   int pow2[maxi]; pow2[0]=1;
   for(int i=1; i<maxi; i++) pow2[i]=pow2[i-1]*2;

   for(int i=0; i<maxi; i++){
    if(arr[i]==brr[i]) ans+=pow2[i];
   }
   
   cout<<ans<<endl;
}

int main(){
    int t;cin>>t;
    while(t--) solve();


    return 0;
}