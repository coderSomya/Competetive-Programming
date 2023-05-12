/*
problem link ->
https://codeforces.com/problemset/problem/1766/D
*/

#include <bits/stdc++.h>
using namespace std;
vector<int>primes;
const int N= 1e7;

#define int long long

int lcm(int x, int y){
    return x*y/(__gcd(x,y));
}

void solve(){
   
   int a, b;
   cin>>a>>b;
   int ans=1e9;

   if(__gcd(a,b)!=1){
    cout<<0<<endl;
    return;
   }

   int m=primes.size();
   int x=abs(a-b);

   int alpha=-1;
   for(int i=0; i<m; i++){
     if(x%primes[i]==0){
   
        alpha=primes[i];
        ans=min(ans,((min(a,b)+alpha-1)/alpha) *alpha - min(a,b));
     }
   }

   if(alpha==-1){
    cout<<-1<<endl;
    return;
   }
  
  cout<<ans<<endl;



}

int32_t main(){
    
    vector<int> count(N+5,1);

    for(int i=2; i<=N; i++){
        if(count[i]){
            primes.push_back(i);
            for(int j=i*i; j<=N; j+=i){
             count[j]=0;
            }
        }
    }

    // cout<<primes.size()<<endl;
    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}