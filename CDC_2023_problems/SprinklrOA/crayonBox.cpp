/*
https://www.thejoboverflow.com/p/p863/
*/

#include <bits/stdc++.h>
using namespace std;

int score(int x){
    return x*x;
}

int dp[60][60][60];

int rec(int i, int j, int extra, vector<pair<int,int>> &v){

    if(j<i) return 0;
    if(i==j) return dp[i][j][extra] = score(v[i].second+extra);

    if(dp[i][j][extra]!=-1) return dp[i][j][extra];

    int temp= score(v[i].second+extra) + rec(i+1, j, 0, v);


    for(int k=i+1; k<=j; k++){
      if(v[k].first==v[i].first){
        temp = max(temp, rec(i+1, k-1, 0, v)+ rec(k, j, extra+v[i].second, v));
      }
    }

    return dp[i][j][extra] = temp;

}

void solve(){
    int n; cin>>n;

    char arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    vector<pair<int,int>> v;
    v.push_back({arr[0]-'a', 1});
    for(int i=1; i<n; i++){
        if(arr[i]-'a'==v.back().first) v.back().second++;
        else v.push_back({arr[i]-'a', 1});
    }

    memset(dp, -1, sizeof(dp));
    

    int ans= rec(0, (int)v.size()-1, 0, v);

    cout<<ans<<endl;


}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}