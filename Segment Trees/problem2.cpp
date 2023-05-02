/*
queries-
1: l r v
=>for all i in l..r arr[i]+=v;
2: x
=>print arr[x]
*/

#include <bits/stdc++.h>
using namespace std;

//idea:
/*

range update on l..r can be thought of as point update on
arr[l]+=v and arr[r+1]-=v;

now finding the updated value of arr[x] can be thought of as range sum(0...x)

*/

void build(int st[], int arr[],int ss, int se, int idx, int stidx){

    if(ss==se){
        st[stidx]=arr[idx];
        return;
    }

    int mid= (ss+se)/2;
    build(st, arr,ss, mid, idx,2*idx);
    build(st, arr, mid+1, se, idx, 2*stidx+1);

    st[stidx]=st[2*stidx]+st[2*stidx+1];

    return;

}

int rangeSum(int st[], int ss, int se, int ql, int qr, int idx){
    
    //no overlap
    if(ss>qr || se<ql){
        return 0;
    }

    //complete overlap
    if(ss>=ql && se<=qr){
        return st[idx];
    }

    //partial overlap
    int mid=(ss+se)/2;
    int left=rangeSum(st, ss, mid, ql,qr, 2*idx);
    int right=rangeSum(st, mid+1, se, ql,qr, 2*idx+1);

    return left+right;

}

void update(int st[], int arr[], int ss, int se, int x, int val, int idx){

    if(ss==se){
        arr[x]=val;
        st[idx]=arr[x];
        return;
    }


    int mid=(ss+se)/2;

    update(st,arr,ss,mid, x, val,2*idx);
    update(st,arr,mid+1,se, x, val,2*idx+1);

    st[idx]=st[2*idx]+st[2*idx+1];
}


void solve(){

    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int q; cin>>q; 
    int st[4*n+1];
    build(st,arr,0,n-1,0,0);

    while(q--){
        char ch;
        cin>>ch;
        if(ch=='1'){
          int l,r,v;
          cin>>l>>r>>v;

          update(st, arr, 0,n-1,l,v,0);
          update(st, arr, 0,n-1,r+1,-v,0);

        } 
        else{
        int x; cin>>x;
        int ans= rangeSum(st,0,n-1,0,x,0);
          cout<<ans<<endl;
        }
    }
}

int main(){
    
    int t; cin>>t;
    while(t--) solve();
    return 0;
}