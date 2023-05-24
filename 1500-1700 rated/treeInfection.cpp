/*
problem link->
https://codeforces.com/problemset/problem/1665/C
*/

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;
    int child[n+1]={0};
    child[0]=1;
    for(int i=1; i<n; i++){
        int x; cin>>x;
        child[x]++;
    }

    priority_queue<int> pq;
    priority_queue<int> pq2;
    for(int i=0; i<=n; i++){

       if(child[i]!=0) pq.push(child[i]);
    } 
    int ans=0;
    
    while(!pq.empty()){
     int x=pq.top();
     pq.pop();
     ans++;
     x--;
     x-=pq.size();
     if(x!=0) pq2.push(x);
    } 

    int ct=0;

    while(!pq2.empty()){
     ct++;
     int x=pq2.top();
     pq2.pop();
  
     
     if(x-ct>=0){
        ans++;
     }
     x--;

     if(x>ct) pq2.push(x);
    }

    cout<<ans<<endl;
      


}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}