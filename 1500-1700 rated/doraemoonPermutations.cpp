/*
problem link->
https://codeforces.com/problemset/problem/1330/B
*/

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;
    int arr[n]; for(int i=0; i<n; i++) cin>>arr[i];
    
    int i=0;
    int pref[n];
    int maxi=0;
    int ct=0;
    unordered_map<int,int>freq;
    while(i<n){
      
      freq[arr[i]]++;
      if(freq[arr[i]]>1){
        break;
      }
      ct++;
      maxi=max(maxi, arr[i]);
      if(maxi==ct) pref[i]=true;
      else pref[i]=false;
     
      i++;

    }

    while(i<n) {
        pref[i]=false;
        i++;
    }

    int j=n-1;
    int m=0;
    int c=0;
    int suff[n];
   unordered_map<int,int> freq2;
    while(j>=0){
        freq2[arr[j]]++;

     if(freq2[arr[j]]>1){
        break;
      }
      c++;
      m=max(m, arr[j]);
      if(m==c) suff[j]=true;
      else suff[j]=false;
     
      j--;

    }

    while(j>=0){
        suff[j]=false; j--;
    }
    
    vector<pair<int,int>> ans;

    for(int i=0; i<n-1; i++){
        if(pref[i]==1 && suff[i+1]==1) ans.push_back({i+1, n-(i+1)});
    }

    cout<<ans.size()<<endl;
    for(auto x: ans) cout<<x.first<<" "<<x.second<<endl;


}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}