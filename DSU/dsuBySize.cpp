#include <bits/stdc++.h>
using namespace std;

//option 1-> small to large

struct{
    int elemIn[100005];
    set<int> st[100005];

    void init(){
        for(int i=1; i<100005; i++){
            elemIn[i]=i;
            st[i].insert(i);
        }
    }

    int find(int x){
     return elemIn[x];
    }

    int unite(int x, int y){
       int setx=elemIn[x];
       int sety=elemIn[y];

       if(st[setx].size()<st[sety].size()){
        swap(setx, sety);
       }

       for(auto elem: st[sety]){
        elemIn[elem]=setx;
        st[setx].insert(elem);
       }
       st[sety].clear();

    }
};

void solve(){

}

int main(){
    
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}