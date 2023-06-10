#include <bits/stdc++.h>
using namespace std;

int dp[100005][26];

bool check(int len, int k, int n){
   
   int maxi=-1; int smaxi=-1;
   for(int i=0; i<26; i++){
    if(dp[len-1][i]>=maxi){
       smaxi=maxi;
        maxi=dp[len-1][i]; 
    }
    else if(dp[len-1][i]>smaxi){
        smaxi=dp[len-1][i];
    }
   }

   if(maxi+smaxi+k>=len) return true;

   int l=1; int h=len;
   while(h<n){
    int mx=-1; int sm=-1;

    for(int i=0; i<26; i++){
    if(dp[h][i]-dp[l-1][i]>=mx){
       sm=mx;
        mx=dp[h][i]-dp[l-1][i]; 
    }
    else if(dp[h][i]-dp[l-1][i]>sm){
        sm=dp[h][i]-dp[l-1][i];
    }
   }

   if(sm+mx+k>=len) return true;
   l++; h++;
   }

   return false;
}

void solve(){
    int n, k; cin>>n>>k;

    string s; cin>>s;
    
    memset(dp, 0, sizeof(dp));

    dp[0][s[0]-'a']++;
    for(int i=1;i<n; i++){
        for(int j=0; j<26; j++){
            dp[i][j]=dp[i-1][j]+(s[i]==('a'+j));
        }
    }

    int l=2; int h=n;
    int ans =2;

    while(l<=h){
        int mid=(l+h)/2;

        if(check(mid, k, n))
        {
            ans=mid; l=mid+1;
        }
        else h=mid-1;
    }

    cout<<ans<<endl;

}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}