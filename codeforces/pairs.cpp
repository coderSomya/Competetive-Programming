#include <bits/stdc++.h>
using namespace std;

bool see(int i, vector<pair<int,int>> &v){
    unordered_map<int,int> kk;
    int maxi=0;
    int ct=0;
    for(auto x: v){
        if(x.first==i || x.second==i) continue;

        kk[x.first]++;
        kk[x.second]++;
        maxi=max({maxi, kk[x.first], kk[x.second]});
        ct++;
    }

   return maxi==ct;
}

#define vi vector<int>

void check(int a, int b, int c, int d, vector<pair<int,int>> &v){

    //a
    bool ans= see(a,v);
    ans= ans|see(b,v);

    if(ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main(){
    
    int n,m; cin>>n>>m;
    
    vector<pair<int,int>> v;
    for(int i=0; i<m; i++){
        int s,t; cin>>s>>t;
        v.push_back({s,t});
    }
    
    if(m<2){
        cout<<"YES"<<endl;
        return 0;
    }
    
    unordered_map<int,int> mp;
    for(int i=0;i<2; i++){
        mp[v[i].first]++;
        mp[v[i].second]++;
    }
    
    int x=mp.size();
    if(x==4){
       //ac or ad or bc or bd
       check(v[0].first, v[0].second, v[1].first, v[1].second, v);
       return 0;
    }
    else if(x==3){
        //a b , a c
     
        vi h;
        int a, b, c;
        b=c=-1;
        for(auto u: mp ){
            if(u.second==2){
                a=u.first;
            }
            else{
                if(b==-1) b=u.first;
                else c=u.first;
            }
        }
        
         //if a is one
         unordered_map<int,int> j;
         int ct=0;
         int maxi=0;
         for(int i=2; i<m; i++){
             if(v[i].first==a || v[i].second==a) continue;
             else{
                 j[v[i].first]++;
                 j[v[i].second]++;
                 maxi=max({maxi,j[v[i].second], j[v[i].first] });
                 ct++;
             }
         }
         
         if(maxi==ct){
             cout<<"YES"<<endl;
             return 0;
         }
         
         //a is not one, so has to be b or c
         for(int i=2; i<m; i++){
             if((v[i].first-b)*(v[i].first-c)*(v[i].second-b)*(v[i].second-c)!=0){
                 cout<<"NO"<<endl;
                 return 0;
             }
         }
         cout<<"YES"<<endl;
         return 0;
        
        
    }
    else{
        
        int res= see(v[0].first, v)||see(v[0].second, v);
        if(res) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        return 0;
    }
  
    
    
    return 0;
}