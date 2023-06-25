#include <bits/stdc++.h>
using namespace std;
#define loop(i,l,r)     for(int i=l; i<r; i++)
#define int             long long
#define pb              push_back
#define vi              vector<int>
#define mkp             make_pair<int,int>
#define umpii           unordered_map<int,int>
#define maxheap         priority_queue<int>
#define minheap         priority_queue<int, vi,greater<int>>
#define setbits(x)      __builtin_popcountll(x)
#define zerobits(x)     __builtin_ctzll(x)
#define in_arr(A,n)     loop(i,0,n) cin>>A[i];
#define p_arr(A,n)      loop(i,0,n) cout<<A[i]
;
#define pln_arr(A,n)    loop(i,0,n) cout<<A[i]<<endl
#define take_n          int n; cin>>n;
#define take_arr        int arr[n]; loop(i,0,n) cin>>arr[i];
  
  
const int mod= 1e9+7;
const int inf= 1e15;
 
 
void solve(){
    string s,t; cin>>s>>t;
    
    // vector<int> need(26,0);
    vector<int> have(26,0);
    vector<int> need(26,0);

    loop(i,0,s.length()){
        have[s[i]-'a']++;
    }

    loop(i,0,t.length()){
        need[t[i]-'a']++;
    }
  int mini = 1e9;
    loop(i,0,26){
        if(need[i]>have[i]){
            cout<<0<<endl;
            return;
        }
        if(need[i]==0) continue;

        mini=min(mini, have[i]/need[i]);
    }
    
    
    cout<<max((int)0,mini)<<endl;

}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}