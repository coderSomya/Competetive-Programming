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
 
const int N= 2e5;
 
void solve(){
    int n; cin>>n;
    set<int> st;

    vector<pair<int,int>> sd;
    vector<pair<int,int>> tc;

    for(int i=0; i<n; i++){
        int x,y; cin>>x>>y;
        sd.push_back({x,y});
        st.insert(x);
        st.insert(y);
    }

    for(int i=0; i<n; i++){
        int x,y; cin>>x>>y;
        tc.push_back({x,y});
        st.insert(x);
        st.insert(y);
    }

    unordered_map<int,int> mp;
   auto itr=st.begin(); int ct=1;
    while(itr!=st.end()){
        mp[*itr]=ct++;
        itr++;
    }

    multiset<int> mst;
    

    int used[4*N]={0};
    vector<vector<int>> all(4*N);
    vector<vector<int>> all2(4*N);

    for(int i=0; i<n; i++){
        tc[i].first=mp[tc[i].first];
        tc[i].second=mp[tc[i].second];
    }
     for(int i=0; i<n; i++){
        sd[i].first=mp[sd[i].first];
        sd[i].second=mp[sd[i].second];
    }

    for(int i=0; i<n; i++){
        all[tc[i].first].push_back(tc[i].second);
        mst.insert(tc[i].second);
    }

    for(int i=0; i<n; i++){
        all2[sd[i].first].push_back(sd[i].second);
        // mst.insert(tc[i].second);
    }

    int ans=0;

    for(int i=0; i<4*n; i++){
        for(auto x: all2[i]){
           if(mst.count(x)!=0){
            mst.erase(mst.find(x));
            ans++;
            used[x]++;
           }
        }

        for(auto x: all[i]){
            if(used[x]==0) mst.erase(x);
            else used[x]--;
        }
    }

    cout<<ans<<endl;

}

  
  
int32_t main(){
int t;
cin>>t;
while(t--)
solve();
return 0;
}