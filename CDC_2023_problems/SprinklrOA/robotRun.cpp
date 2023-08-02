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

    int n, q; cin>>n>>q;

    map<pair<pair<int,int>, pair<int,int>>,vector<pair<int,int>>>mp;

    vector<pair<int,int>> v;

    for(int i=0; i<q; i++){
       int x,y; cin>>x>>y;
       v.push_back({x,y});
    }
cout<<"\n";
    for(int i=0 ;i<q; i++){
        for(int j=i+1; j<q; j++){
        int x1=v[i].first;
        int y1=v[i].second;
        int x2=v[j].first;
        int y2=v[j].second;
        int num= y2-y1;
        int denom= x2-x1;

        int g=__gcd(abs(num), abs(denom));

        num/=g;
        denom/=g;

        int p1= denom*y1-num*x1;
        int p2=denom;

        int gg=__gcd(abs(p1),abs(p2));

        p1/=gg;
        p2/=gg;
                
        mp[{{num, denom}, {p1,p2}}].push_back({i,j});
        }
    }

    int maxi=-1;

    for(auto x: mp){
        set<int> st;
        for(auto y: x.second)st.insert(y.first);
        for(auto y: x.second)st.insert(y.second);

        maxi=max(maxi, (int)st.size());
    }

    cout<<maxi<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}