/*
problem link->
https://codeforces.com/problemset/problem/1582/D
*/

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;
    int arr[n]; 
    for(int i=0; i<n; i++) cin>>arr[i];

    int b[n];
    if(n%2){
      for(int i=1; i<n-3; i+=2){
        b[i]=arr[i-1];
        b[i-1]=-arr[i];
      }
      
      if(abs(arr[n-1])==abs(arr[n-2]) &&abs(arr[n-2])==abs(arr[n-3])){
         
         b[n-3]=(arr[n-3]>0)?1:-1;
         b[n-2]=(arr[n-2]>0)?1:-1;
         b[n-1]=(arr[n-1]>0)?-2:2;
      }

      else{
      b[n-3]=arr[n-1];
      b[n-2]=arr[n-1];
      b[n-1]=-(arr[n-2]+arr[n-3]);
      }
     
    }

    else{
        for(int i=1; i<n; i+=2){
            b[i]=arr[i-1];
            b[i-1]=-arr[i];
        }
    }

   
    for(int i=0; i<n; i++) cout<<b[i]<<" ";

    cout<<endl;
}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}
