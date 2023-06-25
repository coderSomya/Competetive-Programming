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

bool palin(string s){
    
}
 
void solve(){
    int n; cin>>n;
    string s; cin>>s;
   int oggy=0; int jack=0;
    if(palin(s)){

    }

    else{ 

        int inc=0;
        int zeroes=0;

        for(int i=0; i<n; i++){
 zeroes+= s[i]=='0';
 if(s[i]!=s[n-1-i]) inc++;
        }

       
        inc/=2;
         if(zeroes-inc>0){
    oggy+= inc>=1;
        jack+= inc-1;

        int rem=zeroes-inc;

         }
    




    }
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}