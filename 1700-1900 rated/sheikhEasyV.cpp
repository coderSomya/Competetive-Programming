/*
problem link->
https://codeforces.com/problemset/problem/1732/C1
*/

#include <bits/stdc++.h>
using namespace std;

int maxi;
pair<int,int> best;
const int inf= 1e9;

//ST[i] = {length, sum, xor, diff}

void buildST(vector<vector<int>> &ST, vector<int> &arr, int ss, int se,int stidx ){

    if(ss>se) return;

    if(ss==se){
        ST[stidx][0]=1;
        ST[stidx][1]=arr[ss];
        ST[stidx][2]=arr[ss];
        ST[stidx][3]=0;
        
        if(ST[stidx][3]>maxi){
        maxi=ST[stidx][3];
        best={ss,se};
        }
      return;
    }

    int mid=(ss+se)/2;

    buildST(ST, arr, ss, mid, 2*stidx);
    buildST(ST, arr,mid+1, se, 2*stidx+1);

    ST[stidx][0]=se-ss+1;
    ST[stidx][1]=ST[2*stidx][1]+ST[2*stidx+1][1];
    ST[stidx][2]=ST[2*stidx][2]^ST[2*stidx+1][2];
    ST[stidx][3]=ST[stidx][1]-ST[stidx][2];

   if(ST[stidx][3]>maxi){
    maxi=ST[stidx][3];
    best={ss,se};
   }
   else if(ST[stidx][3]==maxi){
    if(ST[stidx][0] < best.second-best.first+1){
    maxi=ST[stidx][3];
    best={ss,se};
    }
   }
}

void solve(){
    int n,q;
    cin>>n>>q;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    int l,r; cin>>l>>r;
    l--; r--;

    vector<int> v;
    for(int i=l ;i<=r; i++) v.push_back(arr[i]);

    n=v.size();
    maxi=-inf;
    best={-inf, inf};
    // cout<<"reached here"<<endl;

    vector<vector<int>>ST(4*n+1, vector<int> (4, 0));

//     buildST(ST, v, 0,n-1, 1);
//   cout<<"ans ....."<<maxi<<endl;
//     cout<<best.first+1<<" "<<best.second+1<<endl;
   
//    int mini=n;
//     for(auto x: ST){
//         if(x[3]==maxi){
//             cout<<x[0]<<endl;
//         }
//     }

//     cout<<mini<<endl;

vector<int> psums(n);
psums[0]=v[0];
for(int i=1; i<n; i++) psums[i]=psums[i-1]+v[i];

vector<int> pxors(n);
pxors[0]=v[0];
for(int i=1; i<n; i++) pxors[i]=pxors[i-1]^v[i];

}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}