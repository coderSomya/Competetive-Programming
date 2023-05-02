/*
Design a data-structure which can answer the following queries:

Given an N-sized array:

1 x v: update pos x with v.
2 l r: return min element in l...r and no. of occurences of that element
*/

//Probably sounds like segment tree

/*
we can store min in a range l...r and no. of occurences of that, also , update will work normally
*/

#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

void update(vector<pair<int,int>> st, int arr[], int ss, int se, int x, int val, int idx){

    if(ss==se){
        //update the leaf
        st[ss]={val,1};
        arr[x]=val;
        return;
    }

    int mid=(ss+se)/2;
    if(x>mid){
        //go right
        update(st,arr, mid+1, se, x, val, 2*idx+1);
    }
    else{
        //go left
        update(st,arr, ss,mid, x, val, 2*idx);
    }

    if(st[2*idx].first<st[2*idx+1].first){
       st[idx]=st[2*idx];
    }
    else if(st[2*idx].first>st[2*idx+1].first){
       st[idx]=st[2*idx+1];
    }
    else{
        st[idx]={st[2*idx].first, st[2*idx].second+st[2*idx+1].second};
    }

}

pair<int,int> rangeQuery(vector<pair<int,int>> st, int ss, int se, int ql, int qr, int idx){

    //no overlap
    if(ss>qr|| se<ql){
        return {inf, 0};
    }

    //complete overlap
    if(ss>=ql && se<=qr) {
        return st[idx];
    }

    //partial overlap
    int mid=(ss+se)/2;
    pair<int,int> p1= rangeQuery(st, ss,mid, ql, qr, 2*idx);
    pair<int,int> p2= rangeQuery(st, mid+1,se, ql, qr, 2*idx+1);

    if(p1.first<p2.first) return p1;
    else if(p1.first>p2.first) return p2;
    else return {p1.first, p1.second+p2.second};

}

void buildTree(vector<pair<int,int>> st, int arr[], int l, int r, int idx){
   
   if(l==r){
     st[idx]={arr[l], 1};
     return;
   }

   int mid=(l+r)/2;
   buildTree(st,arr, l, mid, 2*idx) ;
   buildTree(st, arr, mid+1, r, 2*idx+1);
   if(st[2*idx].first<st[2*idx+1].first){
       st[idx]={st[2*idx].first, st[2*idx].second};
   }
   else if(st[2*idx].first==st[2*idx+1].first){
       st[idx]={st[2*idx].first, st[2*idx].second+st[2*idx+1].second};
   }
   else{
       st[idx]={st[2*idx+1].first, st[2*idx+1].second};
   }
   
   return;

}