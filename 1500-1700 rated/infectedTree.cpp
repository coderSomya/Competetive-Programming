/*
problem link->
https://codeforces.com/problemset/problem/1689/C
*/

#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;


int dfs(int src, int par, vector<int> &size){  
   if(src!=1 && adj[src].size()==1) return size[src]=0;
   
   int temp=0;
   for(auto x: adj[src]){
    if(x!=par){
        temp+=dfs(x,src, size);
    }
   }


   return size[src]= 1+temp;

}

int height(int src, int par, vector<int>&heights){
    if(adj[src].size()==1) return heights[src]=1;

    int temp=1;
    for(auto x: adj[src]){
        if(x!=par){
            temp=max(temp,1+height(x, src, heights));
        }
    }

    return heights[src]=temp;
}

int ans;



void solve(){
   int n; cin>>n;
   adj.clear();
   adj.resize(n+1);

   for(int i=0; i<n-1; i++){
      int u,v; cin>>u,v;
      adj[u].push_back(v);
      adj[v].push_back(u); 
   }
   set<int> leaf;
   for(int i=1; i<=n; i++) if(adj[i].size()==1) leaf.insert(i);
   vector<int> size(n+1);
   vector<int> ht(n+1);

   dfs(1,0,size);
   cout<<"dfs ho gaya"<<endl;
   height(1,0,ht);
   cout<<"dusra dfs ho gaya"<<endl;

   ans=0;

   int root=1;
   int par=-1;
   int saved=0;
   while(leaf.find(root)==leaf.end()){
    vector<int> child;
     for(auto x: adj[root]){
         if(x!=par) child.push_back(x);
     }

     par=root;
     
     if(child.size()==1) {
        saved+= size[child[0]];
        break;
     }

     if(size[child[0]]<size[child[1]]){
     saved+=size[child[1]];
     root=child[0];
     }
     else if(size[child[0]]>size[child[1]]){
        saved+=size[child[0]];
        root=child[1];
     }
     else{
        if(ht[child[1]]<ht[child[0]]){
            saved+=size[child[1]];
            root=child[0];
        }
        else{
            saved+=size[child[0]];
            root=child[1]; 
        }
     }

   }

   cout<<saved<<endl;


}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}