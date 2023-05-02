#include <bits/stdc++.h>
using namespace std;

//option 2-union find

int par[100005];
int size[100005];

void init(){
    for(int i=0; i<100005; i++){
        par[i]=i;
        size[i]=1;
    }
}

int find(int x){
    if(par[x]==x) return x;
    return par[x]=find(par[x]);
}

void unite(int x, int y){
    int rootx= find(x);
    int rooty= find(y);

    if(size[rootx]<size[rooty]) swap(rootx, rooty);

    size[rootx]+=size[rooty];
    par[rooty]=rootx;
}


void solve(){

}

int main(){
    
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}