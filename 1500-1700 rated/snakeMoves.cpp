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

#define debug(...) cout<<'[ '<<#__VA_ARGS__ ':'<<(__VA_ARGS__)<<' ]'<<endl;

  
  
const int mod= 1e9+7;
const int inf= 1e15;
 
 
void solve(){
    int n; cin>>n;
    string s; cin>>s;

    umpii mp;
    mp['R']=1;
    mp['L']=-1;
    mp['U']=1;
    mp['D']=-1;

    map<pair<int,int>, int> prev;
    prev[{0,0}]=0;
    pair<int,int> curr = {0,0};


   int maxi=-1;
   int left=-1;
    for(int i=0; i<n; i++)
    { 
       if(s[i]=='R' || s[i]=='L') curr.first+= mp[s[i]];
       else curr.second+= mp[s[i]];

       if(prev.find(curr)!=prev.end() && prev[curr]>=left){
        left=prev[curr]+1;
       }

       maxi=max(maxi, i-left);
       prev[curr]=i;
    }

    cout<<maxi<<endl;

}

void solve2(){
    int n; cin>>n;

    string s; cin>>s;

    vector<pair<int,int>> pref(n);

    
}
  
  
int32_t main(){
// int t;
// cin>>t;
// while(t--) 
solve();
return 0;
}