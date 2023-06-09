/*
problem link ->
https://codeforces.com/problemset/problem/1478/C
*/

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
    take_n
    set<int>st;
    map<int,int> freq;
    bool flag=false;
    loop(i,0,2*n){
        int x; cin>>x;
        st.insert(x);
        freq[x]++;
        flag|=(freq[x]>2);
    }
    
    if(flag){
      cout<<"NO"<<endl;
      return;
    }
    if(st.size()!=n){
        cout<<"NO"<<endl;
        return;
    }
    vi v;

    for(auto x: st) v.pb(x);
    sort(v.rbegin(), v.rend());

    int curr=0;
    set<int>s;
    for(int i=0; i<n; i++){
        //2*(n-i)*a+curr=v[i];
        if((v[i]-curr)%(2*(n-i))==0){
             int m=(v[i]-curr)/(2*(n-i));
             s.insert(m);
             if(m<=0){
                cout<<"NO"<<endl;
                return;
             }
             curr+=2*m;
        }
        else{
            cout<<"NO"<<endl;
            return;
        }
    }

    if(s.size()!=n){
        cout<<"NO"<<endl;
        return;
    }

    cout<<"YES"<<endl;
    
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}