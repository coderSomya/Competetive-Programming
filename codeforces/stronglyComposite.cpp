/*
problem link ->
https://codeforces.com/problemset/problem/1823/C
*/

#include <bits/stdc++.h>
using namespace std;

const int N= 1e7+5;

vector<int> primes;

void solve(){
  
  int n; cin>>n;
  int arr[n];
  for(int i=0; i<n;i++){
    cin>>arr[i];
  }
  unordered_map<int,int> mp;
  for(auto x: arr){
    for(auto y: primes){
        int c=0;
        while(x>0 && x%y==0){
             x/=y;
             c++;
        }
        mp[y]+=c;
    }
  }


  priority_queue<pair<int, int>> pq;

  for(auto x: mp){
    int a=x.first;
    int b=x.second;
    if(b!=0)
    pq.push({b,a});
  }
   int ans=0;
  while(pq.size()>=1){
    int x=pq.top().first;
    int y=pq.top().second;

    pq.pop();

    if(x>=2){
        ans+=x/2;
        x=x%2;
        if(x) pq.push({1,y});
    }
    else if(x==1){
        if(pq.size()==0){
            break;
        }
    int s=pq.top().first;
    int t=pq.top().second;

    pq.pop();
    if(t!=2 && y!=2) ans+=1;

    }
  }

  cout<<ans<<endl;


}

int main(){
   
   vector<int> vis(N,1);
   for(int i=2; i*i<N; i++){
     if(vis[i]){
        primes.push_back(i);

        for(int j= i*i; j<N; j+=i){
            vis[i]=0;
        }
     }
   }

//    cout<<primes.size()<<endl;
   int t; cin>>t;
   while(t--) solve();
   return 0;
}