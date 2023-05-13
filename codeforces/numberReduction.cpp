/*
problem link->
https://codeforces.com/problemset/problem/1765/N
*/

#include <bits/stdc++.h>
using namespace std;

const int inf = 11;

void buildTree(pair<int,int> ST[], vector<int> & v, int ss, int se, int idx){

    if(ss==se){
        ST[idx]={v[ss], ss};
        return;
    }

    if(ss>se) return;

    int mid=(ss+se)/2;
    buildTree(ST, v,ss,mid,2*idx);
    buildTree(ST, v,mid+1, se,2*idx+1);

    if(ST[2*idx].first<=ST[2*idx+1].first){
        ST[idx]=ST[2*idx];
    }
    else
    {
         ST[idx]=ST[2*idx+1];
    }

}


pair<int, int> rangeQuery(pair<int, int> ST[], vector<int>&v, int ss, int se, int ql, int qr, int idx){
     
     //complete overlap
    if(ss>=ql && se<=qr){
        return ST[idx];
    }

     //no overlap
     if(ss>qr || se<ql){
        return {inf, -1};
     }


     //partial overlap
     int mid=(ss+se)/2;
     pair<int, int> left=rangeQuery(ST,v,ss,mid,ql,qr,2*idx);
     pair<int, int> right=rangeQuery(ST,v,mid+1,se,ql,qr,2*idx+1);

     if(left.first<=right.first) return left;
     else return right;
}

void solve(){
    string s;
    cin>>s;
    int k; cin>>k;
    int u=k;
     int n=s.length();
    vector<int> v;
    
    for(int i=0; i<n; i++){
        v.push_back(s[i]-'0');
    }
   

    //first find the smallest element in the first window of k+1 elements

    pair<int,int> init={inf,-1};
    for(int i=0; i<k+1; i++){
        if(v[i]!=0){
            if(v[i]<init.first){
                // cout<<v[i]<<endl;
                init={v[i], i};
            }
        }
    }

    k-=init.second;
    vector<int> ans;
    ans.push_back(init.first);
    pair<int,int> ST[4*n+1];
    //cout<<"before build"<<endl;
    buildTree(ST, v, 0, n-1, 1);
    //cout<<"after build"<<endl;
    int curr=init.second+1;
    
    while(k>0 && curr+k<n){
      pair<int,int> mini=rangeQuery(ST,v,0,n-1,curr,curr+k,1);
    //   if(mini.second==-1) break;
      k-=mini.second-curr; 
      ans.push_back(mini.first);
      curr=mini.second+1;
    }

   while(curr<n){
    ans.push_back(v[curr]);
    curr++;
   }
//     
 bool flag=false;
   while(ans.size()>n-u){
    ans.pop_back();
   }

   int x=ans.size();
   for(int i=0;i<ans.size(); i++) cout<<ans[i];
// for(int i=0;i<4*n+1; i++) cout<<ST[i].first<<" ";
   cout<<endl;



}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}