/*
problem link->
https://codeforces.com/problemset/problem/1536/C
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
    string s; cin>>s;
    unordered_map<string, int>mp;
    set<pair<int,int>> st;
    vi ans;
    int l=0,k=0; int inf=0, inv_inf=0;
    loop(i,0,n){
        l+=s[i]=='D';
        k+=s[i]=='K';

        if(k==0){
            ans.pb(inv_inf+1);
            inv_inf++; continue;
        }
        else if(l==0){
            ans.pb(inf+1);
            inf++; continue;
        }

        if(st.find({l/__gcd(l,k), k/__gcd(l,k)})!=st.end()){
            string temp= "0" +
           to_string(l/__gcd(l,k))+ ":" + to_string(k/__gcd(l,k));
           ans.pb(mp[temp]+1);
           mp[temp]++;
        }

        else{
           string temp= "0" +
           to_string(l/__gcd(l,k))+ ":" + to_string(k/__gcd(l,k));
           mp[temp]++;

           ans.pb(1);
           st.insert({l/__gcd(l,k), k/__gcd(l,k)});
        }
    }

    loop(i,0,n) cout<<ans[i]<<" ";
    cout<<endl;


}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}