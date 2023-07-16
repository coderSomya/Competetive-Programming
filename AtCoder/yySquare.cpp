#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int ans=0;

int rec(int i, int j, int prev, vector<vector<int>> &grid){
    
}


void solve()
{
    int h,w; cin>>h>>w;
    vector<vector<int>> v(h, vector<int> (w));
    for(int i=0; i<h; i++){
        string s; cin>>s;
        for(int j=0; j<w; j++)
        {
            v[i][j]=(s[i]=='Y');
        }
    }

   int ans= rec(0,0,0,v);
   cout<<ans<<endl;

}

int main(){
    // int t; cin>>t;
    // while(t--) 
    solve();

    return 0;
}