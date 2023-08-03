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

    int n; cin>>n;
    vector<int> v(n); 
    loop(i,0,n) cin>>v[i];

    sort(v.begin(), v.end());

    vector<pair<int,int>> t;
    t.push_back({v[0], 1});
    loop(i,1,n){
        if(v[i]==t.back().first){
            t.back().second++;
        }
        else t.push_back({v[i], 1});
    }
   vector<pair<int,int>> s=t;
    n=t.size();

    int l=0;
    int ans=0;
    int h=1;
    while(h<n){


        if(t[l].first==s[h].first) h++;

        if(t[l].second<=s[h].second){
            s[h].second-=t[l].second;
            ans+=t[l].second;
            l++;
        }

        else{
            ans+=s[h].second;
            t[l].second-=s[h].second;
            s[h].second=0;
            h++;
        }

    }

    cout<<ans<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}