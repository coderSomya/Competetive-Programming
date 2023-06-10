#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    int b[n+1];
    sort(v.rbegin(), v.rend());
    int x=0;
   for(int ct=2; ct<=n; ct+=2){
    b[ct]=v[x];
    x++;
   }

  
for(int ct=1 ; ct<=n; ct+=2){
    b[ct]=v[x];
    x++;
      }

    vector<int> help;
    for(int i=2; i<=n; i+=2){
        help.push_back(b[i]);
    }

    sort(help.rbegin(), help.rend());
   for(int i=2; i<=n; i+=2){
    b[i]=help.back();
    help.pop_back();
   }
  help.clear();
   for(int i=3; i<=n; i+=2){
        help.push_back(b[i]);
    }
  sort(help.rbegin(), help.rend());
   for(int i=3; i<=n; i+=2){
    b[i]=help.back();
    help.pop_back();
   }
  help.clear();

      for(int i=1; i<=n; i++) cout<<b[i]<<" ";
      cout<<endl;   


}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}