/*
problem link->
https://codeforces.com/problemset/problem/1381/B
*/

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;
    int a,b;
    a=b=n;
    int curr=0;
    //0->a, 1->b
    int arr[2*n];
    for(int i=0; i<2*n; i++) cin>>arr[i];
    int i=0;
    while(i<2*n){
        int t=1; 
        int x=arr[i];
       while(++i<2*n && arr[i]<x){
             t++;
       }
       if(curr==0){
         a-=t;
         cout<<"a== "<<a<<endl;
         if(a<0){
            cout<<"NO"<<endl;
            return;
         }
       }
       else{
        b-=t;
          cout<<"b== "<<b<<endl;
           
        if(b<0){
           cout<<"NO"<<endl;
            return;
        }
       }
      curr=1-curr;
    }

    cout<<"YES"<<endl;
}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}