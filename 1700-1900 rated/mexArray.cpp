#include <iostream>
#include <bits/stdc++.h>
using namespace std;


const int inf=1e9;

void buildST(vector<pair<int,int>> &ST, vector<int> &v, int ss, int se, int stidx){
    if(ss==se){
        ST[stidx]={v[ss], ss};
        return;
    }
    
    if(ss>se) return;
    
    int mid=(ss+se)/2;
    buildST(ST, v,ss,mid, 2*stidx);
    buildST(ST, v,mid+1,se, 2*stidx+1);
    
    if(ST[2*stidx+1].first < ST[2*stidx].first){
        ST[stidx]=ST[2*stidx+1];
    }
    else ST[stidx]=ST[2*stidx];
    
}

pair<int,int> query(vector<pair<int,int>> &ST, int ss,int se, int ql,int qr, int stidx){
    
    // cout<<ss<<" "<<se<<endl;
    if(ss>qr || se<ql){
        return {inf, -1};
    }
    
    if(ss>=ql && se<=qr){
         return ST[stidx];
    }
    
    int mid=(ss+se)/2;
    
    pair<int,int> left= query(ST,ss,mid, ql,qr,2*stidx);
    pair<int,int> right= query(ST,mid+1,se, ql,qr,2*stidx+1);
    
    if(right.first<left.first) return right;
    else return left;
}

void solve(){
    int n; cin>>n;
    vector<int>v(n+1, 0);
    for(int i=0; i<n; i++){
        int x; cin>>x;
        v[x]++;
    }
    int curr=-1;
    for(int i=0; i<=n; i++){
        if(v[i]==0){
            curr=i;
            break;
        }
    }
    
    int l=0; int r=curr;
    vector<int> ans;
    int used=0;

    vector<pair<int,int>> ST(4*n+5);
    buildST(ST,v,0,n,1);
// cout<<"here atleast"<<endl;
    int tot=0;

    // for(int i=0; i<n+1; i++) cout<<v[i]<<" ";
    // cout<<endl;

    // for(int i=0; i<5; i++){
    //     int l,r; cin>>l>>r;
    //     cout<<query(ST,0,n,l,r,1).first<<endl;
    // }
    
    while(r>0){
               
        pair<int,int>mini=query(ST, 0,n,0,r-1, 1);
        
        int new_r= mini.second;
        // cout<<"r before"<<r<<endl;
        int number=mini.first-used;
        tot+=number*r;
        for(int i=0; i<number; i++) ans.push_back(r);
        r=new_r;
        // cout<<"r after"<<r<<endl;
        used+=number;

    }
    
    int rem=n-tot;
    
    for(int i=0; i<rem; i++) ans.push_back(0);

    cout<<ans.size()<<endl;
    
    for(int i=0; i<ans.size(); i++) cout<<ans[i]<<" ";
    cout<<endl;
}

int main() {
	// your code goes here
	int t; cin>>t;
	while(t--) solve();
	return 0;
}
