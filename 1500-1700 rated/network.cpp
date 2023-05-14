/*
problem link ->
https://codeforces.com/problemset/problem/1741/E
*/

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;
    int b[n];
    for(int i=0;i<n; i++){
        cin>>b[i];
    }

    //store the value i+arr[i]->potential starting 
    int dp[n][2]; set<int> ends; set<int>starts;
    ends.insert(-1);
    for(int i=0;i<n; i++){
       
      //for i to be a start
      if(ends.find(i-1)!=ends.end()){
        starts.insert(i);
        ends.insert(i+b[i]);
      }
      //for i to be end
      if(starts.find(i-b[i])!=starts.end()){
        ends.insert(i);
      }
    }

    if((ends.find(n-1)!=ends.end())){
          cout<<"YES"<<endl;
    }

    else cout<<"NO"<<endl;

     
}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}