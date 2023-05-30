/*
problem link ->
https://codeforces.com/problemset/problem/1607/E
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
    int n,m; cin>>n>>m;
    
    string s; cin>>s;
    int len=s.length();
    set<int> setx, sety;
    int x=0; int y=0; int ansx=-1, ansy=-1;
    for(int i=0; i<len; i++){
       if(s[i]=='D'|| s[i]=='U'){
          if(s[i]=='D') y++;
          else y--;

          if(y<0){
        
         int rem= abs(y);
         sety.insert(rem);
        if(sety.size()==n && ansy==-1) ansy=rem;
          }
          if(y>0){
     int rem=n+1-y;
     sety.insert(rem);
     if(sety.size()==n && ansy==-1) ansy=rem;
          }
       }
       else{
       if(s[i]=='L') x--;
       else x++;

       if(x>0){
     int rem=m+1-x;
     setx.insert(rem);
     if(setx.size()==m && ansx==-1) ansx=rem;
       }
       if(x<0){
     int rem=abs(x);
     setx.insert(rem);
     if(setx.size()==m && ansx==-1) ansx=rem;
       }
       }
    }

    if(setx.size()!=m){
        for(int i=1; i<=m; i++){
            if(setx.find(i)==setx.end()){
                ansx=i;
                break;
            }
        }
    }

    if(sety.size()!=n){
        for(int i=1; i<=n; i++){
            if(sety.find(i)==sety.end()){
                ansy=i;
                break;
            }
        }
    }

   cout<<ansy<<" "<<ansx<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}