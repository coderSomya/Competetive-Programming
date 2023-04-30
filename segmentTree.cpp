/*
segment tree implementation using lazy propagation...
*/

#include <bits/stdc++.h>
using namespace std;

int lazy[100000]={0};

const int inf= 1e9;

void updateRangeLazy(int st[], int ss, int se, int l, int r, int inc, int idx){
      
 //resolve the lazy value if exists
 if(lazy[idx]!=0){
    //update it
    st[idx]+=lazy[idx];

    //pass on the value to children
    if(ss!=se){
        lazy[2*idx]+=lazy[idx];
        lazy[2*idx+1]+=lazy[idx];
    }
    
    //clear the value now
    lazy[idx]=0;
 }

  //no overlap
  if(ss>r || se<l) return;

  //complete overlap
  if(ss>=l && se<=r){
    st[idx]+=inc;

    //create a new lazy value for children

    if(ss!=se){
        lazy[2*idx]+=inc;
        lazy[2*idx+1]+=inc;
    }

    return;
  }

  //partial overlap
  int mid=(ss+se)/2;
  updateRangeLazy(st,ss,mid,l,r,inc,2*idx);
  updateRangeLazy(st,mid,se,l,r,inc,2*idx+1);
  st[idx]=min(st[2*idx],st[2*idx+1]);

}

int queryLazy(int st[], int ss, int se, int ql,int qr, int idx){
  
  if(lazy[idx]!=0){
    st[idx]+=lazy[idx];

    if(ss!=se){
        st[2*idx]+=lazy[idx];
        st[2*idx+1]+=lazy[idx];
    }

    lazy[idx]=0;
  }

  //query logic

  //no overlap
  if(ss>qr|| se<ql){
     return inf;
  }

  //complete overlap
  if(ss>=ql && se<=qr){
      return st[idx];
  }

  //partial overlap
  int mid=(ss+se)/2;
  int l= queryLazy(st, ss, mid, ql,qr,2*idx);
  int r= queryLazy(st, mid+1,se, ql,qr,2*idx+1);
  return min(l,r);

}

void buildTree(int a[], int s, int e, int st[], int idx){

    if(s==e){
        st[idx]=a[s];
        return;
    }

    int mid=(s+e)/2;
    buildTree(a,s,mid,st,2*idx);
    buildTree(a, mid+1,e,st,2*idx+1);
    st[idx]=st[2*idx]+st[2*idx+1];
    return;
}

int main(){

    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int st[4*n+1];
    buildTree(arr, 0,n-1,st,1);

    return 0;
}