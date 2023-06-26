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
    int n=s.length();
    for(int i=0; i<n; i++){
        if(s[i]!=s[n-1-i]) return false;
    }

    return true;
}
 
void solve(){
    int n; cin>>n;
    string s; cin>>s;
   int oggy=0; int jack=0;
    int z=0; int inc=0;
    for(int i=0; i<n; i++){
     z+= (s[i]=='0');
     inc+= (i<=(n-1)/2) && (s[i]!=s[n-1-i]);
    }

    // inc/=2;
  bool flag=false;
    if(n%2 && s[n/2]=='0'){
oggy++; flag=true;
    } 

    int rem= z- flag- inc;

    jack+= max((int)0,inc - (rem>0));
//   cout<<oggy<<" "<<jack<<endl;
    jack+= max((rem-2)/2, (int)0);
    oggy+= max((rem-2)/2, (int)0);
//   cout<<oggy<<" "<<jack<<endl;
    jack+=min(rem,(int)2);
    // cout<<rem<<endl;

    if(palin(s)) swap(oggy, jack);

    cout<<oggy<<" "<<jack<<endl;
 
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}