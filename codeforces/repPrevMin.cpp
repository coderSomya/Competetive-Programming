/*
problem link ->
https://codeforces.com/problemset/problem/1675/E
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
 
vi v(26);
string ans; string s;

void solve2(){
    for(int i=0; i<s.length(); i++){
        int mini=30;
     for(int j=s[i]-'a'; j<26; j++){
        mini=min(mini, v[j]);
     }
     ans+= mini+'a';
    }
}

void solve(){

    int n,k; cin>>n>>k;
     cin>>s;
    ans=""; v.clear();
    int rem=0;
    loop(i,0,26) v[i]=i; int maxi=-1; bool flag=true;
    loop(i,0,n){
         if(s[i]-'a'<=k){
            maxi = max(maxi, (long long)(s[i]-'a'));
         }
         else{
          
            if(maxi!=-1){
                v[maxi]=0;  
                k-=maxi; 
            }
            

                v[s[i]-'a']=s[i]-'a'-k;
            
            solve2(); flag=false;
            break;
         }
    }
   if(flag){
    loop(i,0,n) cout<<'a';
    cout<<endl;
    return;
   }
    cout<<ans<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}