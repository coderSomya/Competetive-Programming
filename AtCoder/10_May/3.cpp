#include <bits/stdc++.h>
using namespace std;

void solve(){
   int n, m;
   cin>>n>>m;
   vector<int> a(n), b(m);
   vector<int>ans1(n), ans2(m);

   for(int i=0; i<n; i++) cin>>a[i];
   for(int i=0; i<m; i++) cin>>b[i];

   int x=0; int y=0;
   int z=1;
   while(x<n && y<m){
    if(a[x]<b[y]){
      ans1[x]=z;
      x++;
    }
    else{
    ans2[y]=z;
    y++;
    }
    z++;
   }

   while(x<n){
    ans1[x]=z;
    x++;
    z++;
   }
   while(y<m){
    ans2[y]=z;
    y++; z++;
   }

   for(auto i: ans1) cout<<i<<" ";
   cout<<endl;
   for(auto j: ans2) cout<<j<<" ";
   cout<<endl;
}
int main(){
    // int t; cin>>t;
    // while(t--) 
    solve();

    return 0;
}