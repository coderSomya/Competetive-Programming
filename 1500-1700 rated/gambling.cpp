/*
problem link ->
https://codeforces.com/problemset/problem/1692/H
*/

#include <bits/stdc++.h>
using namespace std;

const int inf= 1e9+5;


void solve(){
    int n; cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n; i++) cin>>arr[i];
    
    vector<int> hash(arr);
    sort(hash.begin(), hash.end());
    unordered_map<int,int>mp;
   int ct=0;
   mp[hash[0]]=ct;
   ct++;
   //coordinate compression
    for(int i=1;i<n; i++){
     if(hash[i]!=hash[i-1]){
        mp[hash[i]]=ct;
        ct++;
     }
    }

   vector<set<pair<int,int>>> v(n);
   unordered_map<int,int> freq;
   vector<int> check(n);
    for(int i=0;i<n; i++){
       freq[arr[i]]++;
     
       v[mp[arr[i]]].insert({(2*freq[arr[i]]-i), -i});
       check[i]=(2*freq[arr[i]]-i);
    }
   

 


  int maxi=-inf;
  int left=-1;
  int elem=-1;
   
  for(int i=0; i<n; i++){
     pair<int,int> right_guy= *(v[mp[arr[i]]].rbegin());
     int right=right_guy.first;
     int right_pos=-right_guy.second;

     if(right-check[i] >= maxi){
        maxi=right-check[i]+1;
        elem=arr[i];
        left=i;
     }
     v[mp[arr[i]]].erase({check[i], -i});
  }
  int c=0;
  int i;
  for(i=left; i<n; i++){
    if(arr[i]==elem) {
        c++;
    }
    else c--;
    if(c==maxi){
        break;
    }
  }

  cout<<elem<<" "<<left+1<<" "<<i+1<<endl;




    
}

int main(){
    int t; cin>>t;
    while(t--) solve();


    return 0;
}