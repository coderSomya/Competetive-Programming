/*
problem link ->
https://codeforces.com/contest/1832/problem/D1
*/

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,q; cin>>n>>q;

    vector<int>arr(n);

    for(int i=0; i<n; i++) cin>>arr[i];

    while(q--){
      vector<int> v(arr);
      int k; cin>>k;

      if(n==1){
        if(k%2){
            cout<<v[0]+k-k/2<<endl;
           continue;
        }
        else{
            cout<<v[0]-k/2<<endl;
            continue;
        }
      }

      int mini=0;
      k-=2*(v[1]-v[0])-1;
      if(k>=0){
        //operation was successfull
         v[mini]=v[mini+1];
         mini++;
      }
      else{
        cout<<v[0]<<endl;
        continue;
      }

      while(k>0 && mini<n-1){
           int gap=v[mini+1]-v[mini];

           int attempts=(mini+1)*gap*2;
           if(k-attempts>=0){
              k-=attempts;
              v[mini]=v[mini+1];
              mini++;

           }
           else{
             cout<<v[mini]<<endl;
           }
      }

      if(k>0){
        if(k%2){
           
        }
        else{
            int ans=v[mini]+k/2*n;
        }
      }



    }
}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}