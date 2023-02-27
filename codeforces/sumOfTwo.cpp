/*
problem link -
https://codeforces.com/contest/1788/problem/B
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
    string s; cin>>s;
    string a="", b="";
    int turn =0;
    int n=s.length();

    for(int i=n-1; i>=0; i--){
        int x= s[i]-'0';
        if(x%2){
          if(turn==0){
            a+=(x-1)/2 + '0';
            b+= (x+1)/2 + '0';
          }
          else{
            b+=(x-1)/2 + '0';
            a+= (x+1)/2 + '0';
          }

          turn = 1- turn;
        }
        else{
        a+= x/2+ '0';
        b+= x/2+ '0';

        }
    }

    while(a[a.length()-1]=='0' && a.length()>1){
        
        a= a.substr(0, a.length()-1);
    }

    while(b[b.length()-1]=='0' && b.length()>1){
        b= b.substr(0, b.length()-1);
    }

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());


    cout<<a<<" "<<b<<endl;

}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}