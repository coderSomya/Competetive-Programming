#include <bits/stdc++.h>
using namespace std;

#define loop(n) for(int i=0; i<n; i++)

vector<pair<pair<int,int>, int> >m;
int n;

int bs(int val){

    int l=0; int h=n-1;
    int ans=n;

    while(l<=h){
        int mid= (l+h)/2;

        if(m[mid].first.first>=val){
            ans=mid;
            h=mid-1;
        }
        else l=mid+1;
    }

    return ans;
}

const int N = 1e5;

int dp[N];
int rec(int i){

    if(i==n) return 0;

   if(dp[i]!=-1) return dp[i];

    int temp = rec(i+1);

    int idx=bs(m[i].first.second);

    temp= max(temp, m[i].second+ rec(idx));

    return dp[i]=temp;
}

void solve(){
    cin>>n;

    int p[n], s[n], e[n];
    loop(n) cin>>p[i];
    loop(n) cin>>s[i];
    loop(n) cin>>e[i];

     m.clear();
    loop(n){
        m.push_back({{s[i], e[i]}, p[i]});
    }

    sort(m.begin(), m.end());

    memset(dp, -1, sizeof(dp));

    int ans=rec(0);
    cout<<ans<<endl;


}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}

/*
1
3
17 5 8
1 3 6
11 5 10
*/