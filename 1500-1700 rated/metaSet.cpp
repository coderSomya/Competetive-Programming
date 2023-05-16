#include <bits/stdc++.h>
using namespace std;

// int nc3(int a){
//     if(a<3) return 0;
//     return a*(a-1)*(a-2)/6;
// }

#define int long long

int nc2(int a){
    if(a<2) return 0;
    return a*(a-1)/2;
}

void solve(){
    int n,k; cin>>n>>k;
    
    vector<vector<int>> v(n, vector<int>(k));
    unordered_map<int, int> mp;

    for(int i=0; i<n; i++){
        
        for(int j=0;j<k;j++)
        {
            cin>>v[i][j];
        }
        int temp=0;
        for(int p=0; p<k; p++){
            temp+=v[i][p]*pow(3,p);
        }
        mp[temp]=i;
    }

    //we have the different sets
    vector<int>sets(n*n+3,0);
    for(int i=0;i<n; i++){
        for(int j=i+1; j<n; j++){
            int temp=0;
            for(int p=0; p<k;p++){
                if(v[i][p]==v[j][p]) temp+=v[i][p]*pow(3,p);
                else temp+=(3- v[i][p]-v[j][p])*pow(3,p);
            }
            if(mp.find(temp)!=mp.end() && mp[temp]>j){
              //found a good set
              sets[mp[temp]]++;
              sets[i]++;
              sets[j]++;
            }
        }
    }
   int res=0;
   
   for(int i=0; i<n*n+3; i++) res+=nc2(sets[i]);

   cout<<res<<endl;
   


}


int32_t main(){
    // int t; cin>>t;
    // while(t--) 
    solve();

    return 0;
}