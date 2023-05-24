/*
problem link->
https://codeforces.com/problemset/problem/1660/E
*/

#include <bits/stdc++.h>
using namespace std;

void solve(){
    
    int n; cin>>n;
    int arr[2*n][2*n];
    int ones=0;

    //make a 2n*2n matrix
    for(int i=0; i<n; i++)
    {
    string s; cin>>s;

    for(int j=0; j<n; j++) {
        int x=s[j]-'0';
        arr[i][j]=x;
        arr[i+n][j]=x;
        arr[i][j+n]=x;
        arr[i+n][j+n]=x;
        ones+=(x==1);
    }
    }

    //make prefix diagonals
    
     for(int i=2*n-2; i>=0; i--){
        for(int j=0;j<2*n; j++){
              arr[i][j]+=arr[i+1][(j+1)%(2*n)];
        }
     }

     //find maximum diagonal prefix

     int maxi=0;
     for(int i=2*n-2; i>=0; i--){
        for(int j=0;j<2*n; j++){
            int temp=arr[i][j];
            int left=(i<n ? arr[i+n][(j+n)%(2*n)]:0);
            temp-=left;
            maxi=max(maxi, temp);
        }
     }
//   cout<<ones<<" "<<maxi<<" "<<endl;
     int ans=n+ones - 2*maxi;
     cout<<ans<<endl;

}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}