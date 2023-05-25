/*
problem link->
https://codeforces.com/problemset/problem/1633/D
*/

#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

vector<int> f(1001, inf);
int b[1001],c[1001];

bool cmp(pair<int,int> &a, pair<int,int> &b){
    if(a.first==a.second) return f[c[a.second]]>f[c[b.second]];

    else return a.first>b.first;
}

void solve(){
    int n,k; cin>>n>>k;
    
    for(int i=0; i<n; i++) cin>>b[i];
    for(int i=0; i<n; i++) cin>>c[i];
    
    //make a ratio vector
    vector<pair<int,int>>v;
    for(int i=0; i<n; i++){
        v.push_back({c[i]/f[b[i]],i});
    }

    sort(v.begin(), v.end(), cmp);

    int ans=0;
    int cost=0;
    for(int i=0; i<n; i++){
       cost+=f[b[v[i].second]];
       if(cost>k) break;
       else ans+=c[v[i].second];
    }

    cout<<ans<<endl;

}

int main(){

    //precompute costs;
    f[1]=0;
    queue<int>q;
    vector<int> vis(1001,0);
    q.push(1);
    vis[1]=1;

    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=1; i*i<=x; i++){
            //factor can be reached in one more step
            if(x%i==0){
               if(x+i<1001 &&!(vis[x+i]) && f[x+i]>f[x]+1){
                q.push(x+i);
                f[x+i]=f[x]+1;
                vis[x+i]=1;
               }
               if(x+x/i<1001 && !vis[x+x/i]&& f[x+x/i]>f[x]+1){
                q.push(x+x/i);
                f[x+x/i]=f[x]+1;
                vis[x+x/i]=1;
               }
            } 
        }
    }

   
    int t; cin>>t;
    while(t--) solve();

    return 0;
}