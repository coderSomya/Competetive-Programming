#include <bits/stdc++.h>
using namespace std;


const int N = 2002; 
int n;
vector<int> arr(N);
vector<int> cost(N);
int k;

unordered_map<int,int> mini;

int dp[N][N];

int rec(int i, int num, vector<int> &pref_cost, vector<int> &pref_val){


    //dp[i][num] = (pref_val[i]+ k*num)*(pref_cost[i] - pref_cost[j-1]) + dp[j][num-1]

    //
}

void solve()
{
   cin>>n; cin>>k;
   for(int i=0; i<n; i++) cin>>arr[i];
   for(int i=0; i<n; i++) cin>>cost[i];

   mini.clear();
  memset(dp, -1, sizeof(dp));

  vector<int> pref_val(n,0);
  vector<int> pref_cost(n, 0);

  pref_val[0]=arr[0];
  for(int i=1; i<n; i++) pref_val[i]=pref_val[i-1]+arr[i];

  pref_cost[0]=cost[0];
  for(int i=1; i<n; i++) pref_cost[i]=pref_cost[i-1]+cost[i];



}

int main()
{
    int t; cin>>t;
    while(t--) solve();

    return 0;
}