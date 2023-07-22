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


int check (vector<int> &a, vector<int> &b){
    int n=a.size();
    int m=b.size();

    if(n!=m) return -1;

    unordered_map<int,int> as;
    unordered_map<int,int> bs;
  set<int> st;

    for(int i=0; i<n; i++)
    {
        as[a[i]]++;
        st.insert(a[i]);
    }

    for(int i=0; i<n; i++){
        bs[b[i]]++;
        st.insert(b[i]);
    }

  vector<int> aa;
  vector<int> bb;

  for(auto x: st){
    if(as[x]==bs[x]) continue;
    
    else if(as[x]>bs[x]) {
        for(int i=0; i<(as[x]-bs[x])/2; i++){
            aa.push_back(x);
        }
    }
    else{
       for(int i=0; i<(bs[x]-as[x])/2; i++){
            bb.push_back(x);
        } 
    }
  }

 


  if(aa.size()!=bb.size()){
    return -1;
  }
  sort(aa.begin(), aa.end());
  sort(bb.begin(),bb.end());
  int i=0;
  int j=bb.size()-1;
  
  int ans=0;

  while(i<n && j>=0){
    ans+=min(aa[i], bb[j]);

    i++; j--;
  }



  /*
  2 
  1
  */
return ans;
    


}
 
 
void solve(){
    vector<int> a{4,2,2,2};
    vector<int> b{1,4,1,2};
    int ans = check(a,b);
    cout<<ans<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}