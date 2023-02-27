/*
problem link -
https://codeforces.com/problemset/problem/1742/F
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
    int q; cin>>q;
    int as=1;//ct of a in s
    int at=1;//ct of a in t
    int os=0;//ct of others in a
    int ot=0;//ct of others in b
    
    while(q--){
        int d,k;
        cin>>d>>k;

        string x; cin>>x;
        if(d==1){
        for(char ch:x){
           if(ch-'a') os+=k;
           else as+=k;
        }
        }
        else{
            for(char ch: x){
                if(ch-'a') ot+=k;
                else at+=k;
            }
        }

        if(ot>0){
            cout<<"YES"<<endl;
        }
        else{
            if(os==0 && as<at){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
    }
  
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}