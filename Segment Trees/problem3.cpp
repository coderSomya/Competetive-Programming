/*
queries-
1: x v
=> update arr[x]=v;

2: l r
=> find max sum subarray in the range l..r

*/

#include <bits/stdc++.h>
using namespace std;

//vector={prefmax, suffmax, maxsum ,totalsum}


void build(vector<vector<int>> &st, int arr[], int ss, int se, int idx, int stidx){

    if(ss==se){
        st[stidx]={arr[idx], arr[idx], arr[idx], arr[idx]};
        return;
    }

    int mid=(ss+se)/2;
    build(st,arr, ss, mid, idx,2*stidx);
    build(st,arr, mid+1, se, idx,2*stidx+1);
    
    int prefm= max({st[2*idx][0], st[2*idx][3]+st[2*idx+1][0], st[2*idx][3]});
    int suffm=max({st[2*idx+1][1], st[2*idx+1][3]+st[2*idx][1], st[2*idx+1][3]});
    int maxi=max(st[2*idx][2], st[2*idx+1][2]);
    int total=max(st[2*idx][3], st[2*idx+1][3]);

    //very poor implementation that.. duh

    st[idx]={prefm, suffm, maxi,total};
}

void solve(){
    
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int st[4*n+1];
    
}

int main(){

    int t; cin>>t;
    while(t--) solve();

    return 0;
}