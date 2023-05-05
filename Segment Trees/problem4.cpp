/*
queries->

1) + x -> add x to the set
2) ? k -> report kth element of the set
3) - x -> remove x from the set

*/

#include <bits/stdc++.h>
using namespace std;

int query(int st[], int ss, int se, int idx, int k){

    if(ss==se){
        return ss;
    }

    int left=st[2*idx];
    int mid=(ss+se)/2;
    if(left>=k){
        return query(st,ss,mid,2*idx, k);
    }
    else{
        return query(st,mid+1,se,2*idx+1,k-left);
    }
}

set<int> sett;

void build(int st[], int ss, int se, int idx){
    
    if(ss>se) return;
    if(ss==se){
        if(sett.find(ss)!=sett.end()) st[idx]=1;
        else st[idx]=0;
        return;
    }

    int mid=(ss+se)/2;

    build(st,ss,mid,2*idx);
    build(st,mid+1,se,2*idx+1);

    st[idx]=st[2*idx]+st[2*idx+1];

}

void add(int st[], int ss, int se, int idx, int x){
    cout<<ss<<" "<<se<<endl;
    cout<<st[idx]<<endl;
    if(ss>se) return;
    if(ss==se){
        st[idx]++;
        return;
    }

    int mid=(ss+se)/2;
    
    if(st[2*idx]>=x){
        add(st,ss,mid,2*idx, x);
    }
    else{
        add(st,mid+1,se, 2*idx+1, x-st[2*idx]);
    }

    st[idx]=st[2*idx]+st[2*idx+1];

}

void remove(int st[], int ss, int se, int idx, int x){
    
    if(ss==se){
        st[idx]--;
        return;
    }

    int mid=(ss+se)/2;
    
    if(st[2*idx]>=x){
        add(st,ss,mid,2*idx, x);
    }
    else{
        add(st,mid+1,se, 2*idx+1, x-st[2*idx]);
    }

    st[idx]=st[2*idx]+st[2*idx+1];

}

const int n=1e5+5;
void solve(){
   
//    int n; cin>>n;
//    for(int i=0; i<n; i++){
//     int a; cin>>a;
//     sett.insert(a);
//    }
   int st[100005];
   memset(st,0, sizeof(st));
//    build(st,0,n-1,0);
   int q; cin>>q;
   while(q--){
     char ch;
     cin>>ch;
     if(ch=='+'){
        int x; cin>>x;
 
        add(st,0,n-1,1,x);
     }
     else if(ch=='-'){
        int x; cin>>x;
        remove(st,0,n-1,1,x);
     }
     else{
        int k; cin>>k;
        cout<<query(st,0,n-1,1,k)<<endl;
     }
   }
}

int main(){

    int t; cin>>t;
    while(t--) solve();
}