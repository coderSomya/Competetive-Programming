#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> pos(10);
 int n;
int m;
  string l, r;

int bs(vector<int> &v, int val){
    int l=0;
    int h=(int)v.size()-1;

    int ans=n;

    while(l<=h){
        int mid= (l+h)/2;

        if(v[mid]>val){
            // cout<<v[mid]<<" "<<val<<endl;
            ans=v[mid];
           h=mid-1;
        }

        else l=mid+1;
    }

    return ans;

}

bool rec(int mi, int si){
   
   if(mi==m){
// cout<<si<<endl;
return si==n;
   } 

   int lb=l[mi]-'0';
   int ub=r[mi]-'0';

   bool temp=false;

   for(int i=lb; i<=ub; i++){
     int nsi= bs(pos[i], si);

     temp= temp||rec(mi+1, min(nsi+1, n));

   }
   return temp;


}


void solve(){
    string s; cin>>s;
   n=s.length();
     cin>>m;
  
    cin>>l>>r;

  
pos.clear();
pos.resize(10);
    for(int i=0; i<n; i++){
        pos[s[i]-'0'].push_back(i);
    }

    // for(int i=0; i<10; i++){
    //     for(auto x: pos[i]) cout<<x<<" ";
    //     cout<<endl;
    // }
   bool res= rec(0, 0);

   cout<<(res? "YES" : "NO")<<endl;


}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}