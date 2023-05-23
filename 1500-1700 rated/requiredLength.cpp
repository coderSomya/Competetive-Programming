/*
problem link ->
https://codeforces.com/problemset/problem/1681/D
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

int s;
const int inf=2e9;



int count(int x, int mask){
    //returns min operations to go from log2(x)->log2(n) with current mask
    
    if(x>=s) return 0;

    int p=mask;
     int temp=inf;
    while(p){
        int y=p%10;
        p/=10;
        temp=min(temp, 1+ count(x+log2(y), mask*y));
    }

    return temp;

}

void solve(){
    int n;
    int x; cin>>n>>x;
    int r=pow(10,n);
    s=log2(r);

    int ans =0;
    bool flag=false;
 

   

    int ans =count(log2(x), x);



    

}

int main(){
  int t; cin>>t;
  while(t--) solve();

  return 0;
}