/*
problem link ->
https://cses.fi/problemset/task/1137
*/

#include <bits/stdc++.h>
using namespace std;

//store the euler tour of the tree in an array
//sum of subtree is the sum of elements in the range i..i
//use segment tree for updation and query handling
vector<int> euler;
vector<int> in;
vector<int> out;
vector<int> values;
vector<vector<int>> adj;

void dfs(int src, int par){

    euler.push_back(values[src]);
    in[src]=euler.size()-1;

    for(auto x: adj[src]){
        if(x!=par) dfs(x, src);
    }
    euler.push_back(values[src]);
    out[src]=euler.size()-1;
}

void buildTree(int arr[], int ST[], int ss, int se, int idx){
    if(ss==se){
        ST[idx]=arr[ss];
        return;
    }

    int mid=(ss+se)/2;
    buildTree(arr, ST, ss, mid, 2*idx);
    buildTree(arr, ST, mid+1, se, 2*idx+1);
    ST[idx]=ST[2*idx]+ST[2*idx+1];
}

int query(int ST[], int idx, int ss, int se, int ql, int qr){
    if(ql>qr) return 0;
    if(ss==ql && se==qr) return ST[idx];
    
    int mid=(ss+se)/2;

    return query(ST, 2*idx, ss, mid, ql, min(qr, mid))+ query(ST, 2*idx+1,mid+1,se, max(qr,mid+1), qr);

}

void update(int ST[], int idx, int ss, int se, int pos, int val){
    if(ss==se){
        ST[idx]=val;
    }

    int mid=(ss+se)/2;
    if(pos<=mid) update(ST,2*idx, ss, mid, pos, val);
    else update(ST,2*idx+1,mid+1, se, pos,val);

    ST[idx]=ST[2*idx]+ST[2*idx+1];
}
void solve(){
  
   int n,q; cin>>n>>q;
   adj.clear();
   adj.resize(n+1);
   in.resize(n+1);
   out.resize(n+1);
   values.resize(n+1);
   for(int i=0; i<n; i++){
    cin>>values[i+1];
   }
   for(int i=0;i<n-1;i++){
    int x; int y;
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
   }

   dfs(1, -1);
   int ST[4*n+1];
   int helper[2*n];
   for(int i=0; i<2*n; i++) helper[i]=euler[i];
   buildTree(helper, ST, 0, n-1, 1);

   
   //build a segtree, fenwick tree
   //for sum_subtree(x)=sum(in[x]...out[x])
   //for update x->y
   //v[in[x]]=y, v[out[x]]=y
   while(q--)
   {
    int type; cin>>type;

    if(type==1){
        int s; int x;
        update(ST,1,0,n-1,in[s],x);
        update(ST,1,0,n-1,out[s],x);
    }
    else{
        int s;
        int ans=query(ST,1,0,n-1,in[s], out[s]);
        cout<<ans/2<<endl;
    }
   }
    

}

int main()
{
    int t; cin>>t;
    while(t--) solve();

    return 0;
}