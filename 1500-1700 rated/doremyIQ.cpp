#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<int> arr;
string s;
int dp[(int)1e5+5];

int check(int i ,int curr){ //returns max contests from pos=i, and strength=curr

    //base case
    if(i==n) return 0;

    if(curr<=0) return 0;

    //cache check
    if(dp[i]!=-1) return dp[i];

    //transition
    if(arr[i]<=curr){
        return dp[i]= 1+check(i+1, curr);
    }
    
    else{
        return dp[i]= max(check(i+1,curr), 1+check(i+1, curr-1));
    }


}
const int N= 1e5+5;
int dpp[N][2];
int check2(int i, int curr){

    if(i>=n || curr<=0){
        return dpp[i][0]=dpp[i][1]=0;
    }

    if(arr[i]<=curr){
        dpp[i][0]=check2(i+1,curr);
        dpp[i][1]=1+ check2(i+1, curr);
    }
    else{
        dpp[i][0]=check2(i+1,curr);
        dpp[i][1]=1+check2(i+1,curr-1);
    }

    return max(dpp[i][0], dpp[i][1]);

}

void solve(){

    cin>>n>>q;

    arr.clear(); arr.resize(n);
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n; i++) cin>>arr[i];

    int ans=check(0,q);

    string res="";
    int p=1;
    for(int i=n-1; i>=0; i--){
        if(dp[i]==p){
            res+="1";
            p++;
        }
        else{
            res+="0";
        }
    }

    reverse(res.begin(), res.end());

    memset(dpp, -1, sizeof(dpp));
    int ans2=check2(0,q);

    string t;
    for(int i=0; i<n; i++){
        if(dpp[i][0]<=dpp[i][1]) t+='1';
        else t+='0';
    }


    cout<<res<<endl;
    cout<<t<<endl;

}

int main(){
    int t; cin>>t;
    while(t--) solve();


    return 0;
}