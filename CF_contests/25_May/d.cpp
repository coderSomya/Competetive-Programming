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
unordered_map<char,int> mp;

void toggle(){
    int x=mp['('];
    int y=mp[')'];
    mp['(']=y;
    mp[')']=x;
}
 
void solve(){
    int n; cin>>n;
    string s; cin>>s;

    int ans=1;
   
    vector<int> v;
     vector<int> res;
    int start=0;
      int color=1;
    mp[s[0]]=1;
    if(s[0]=='(') mp[')']=-1;
    else mp['(']=-1;
    res.push_back(color);
    int curr=mp[s[0]];
    for(int i=1; i<n; i++){
       if(curr+mp[s[i]]<0){
        ans++;
        toggle();
        color=color^3;
        curr=mp[s[i]];
        v.push_back(i);
       }

        else{
          curr+=mp[s[i]];
         
        }
         res.pb(color);
    }

   if(curr!=0) {
    ans=-1;
   }
    cout<<min(ans,(int)2)<<endl;
  
   

  if(ans!=-1){
   for(int i=0; i<n; i++){
    cout<<res[i]<<" ";
   }
     cout<<endl;
  }





   
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}