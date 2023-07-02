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

vector<int> v;
umpii mp;
int n,c; 

bool check(int k){
  
  //mark everything in desc order top k elements
//   cout<<"k==" <<k<<endl;

  vector<int> res(n);
  for(int i=0; i<n; i++){
    if(mp[v[i]]<=k) res[i]=1;
    else res[i]=0;
  }

//   cout<<"res="<<endl;


  vector<int> pref(n);
  pref[0]=res[0];
  for(int i=1; i<n; i++) pref[i]=pref[i-1]+res[i];



  if(pref[c-1]>c/2) return true;

  int l=0; int h=c;
  while(h<n)
  {
    if(pref[h]-pref[l] > c/2) {
        cout<<l<<" "<<h<<endl;
        return true;
    }
    l++;
    h++;
  }

  
 
  return false;

}
 
 
void solve(){

    cin>>n>>c;

    v.clear();
    v.resize(n);

    loop(i,0,n) cin>>v[i];

    mp.clear();

    vector<int> help(v);
    sort(help.rbegin(), help.rend());
    int p=1;
    for(int i=0; i<n;i++){
        if(mp.find(help[i])!=mp.end()){
            continue;
        }
  mp[help[i]]=p;
  p++;
    }

    int ans=n;

    int l=1; int h=n;
    while(l<=h){
        int mid=(l+h)/2;

        if(check(mid)){
          ans=mid;
          h=mid-1;
        }
        else l=mid+1;
    }

    
    cout<<ans<<endl;

}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}