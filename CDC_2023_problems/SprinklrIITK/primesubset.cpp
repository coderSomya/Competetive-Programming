/*




10^3*30
10^7 * 10
*/

#include <bits/stdc++.h>
using namespace std;

int MAXN;
int ans=0;
const int mod = 1e9+7;

int dp[30][(1<<11)];

vector<vector<int>> fact(31);

int rec(int i, int mask, vector<pair<int,int>>&v, vector<int> &primes){
    if(i==MAXN){
    return (mask!=0);
    }

    if(dp[i][mask]!=-1) return dp[i][mask];

    int temp=rec(i+1, mask, v, primes);
    bool flag=false;
    int temp_mask=mask;
   
   for(auto x: fact[v[i].first]){
    if((mask&(1<<x))!=0){
        flag=true;
        break;
    } 
    else temp_mask|= (1<<x);
   }

   if(!flag){
      temp+= 1ll*v[i].second*rec(i+1, temp_mask, v, primes);
      temp%=mod;
   }

   return dp[i][mask] = temp%mod;

}

set<int> st;

bool mult(int x){
    return (st.find(x)!=st.end());
}

void solve(){
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    map<int, int> mp;
//8 9 12 16 18 20 24 25 27 
    vector<int>primes{2,3,5,7,11,13,17,19,23,29};
    st.insert(4); 
    st.insert(12); 
    st.insert(16); 
    st.insert(8); 
    st.insert(9); 
    st.insert(18); 
    st.insert(20); 
    st.insert(24); 
    st.insert(25); 
    st.insert(27); 
memset(dp, -1, sizeof(dp));

    for(int i=2; i<=30; i++){
        for(int j=0; j<primes.size(); j++){
            if(i%primes[j]==0) fact[i].push_back(j);
        }
    }

    for(int i=0; i<n; i++){
        mp[arr[i]]++;
    }

    vector<pair<int,int>> v;
    for(auto x: mp){
        if(mult(x.first)) continue;
        v.push_back({x.first, x.second});
    }
  MAXN= v.size();

//   for(int i=0; i<n; i++){
//     for(int j=0; j<fact[v[i].first].size(); j++)cout<<j<<" ";
//     cout<<endl;
//   }

  int ans= rec(0,0,v, primes);

  cout<<ans<<endl;

}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}