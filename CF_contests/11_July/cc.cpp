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
    int n; cin>>n;

    int arr[n];
    for(int i=0; i<n; i++){
      cin>>arr[i];
    }

 bool flag= true;

  for(int i=0; i<n; i++){
    if(arr[i]>0){
        flag=false;
    break;
    }
  }

  if(flag){
    int maxi= -inf;
     for(int i=0; i<n; i++){
    maxi=max(maxi, arr[i]);
  }

  cout<<maxi<<endl;
  return;
  }

   int ans=0;

vector<vector<int>> v(n);

int ct=0;

v[0].push_back(arr[0]);

for(int i=1; i<n; i++){
    if(arr[i]*arr[i-1]<0){
        ct++;
    }

    v[ct].push_back(arr[i]);
}
int last;
for(int i=0; i<n; i++){
    if(v[i].empty()){
        last=i-1;
    }
}


for(int i=0; i<=last; i++){
    // if(v[i].empty()) break;

    if(v[i][0]<0){
       if(i==0 || i==last || v[i].size()%2){
         continue;
       }

       else {
        vector<int> vv=v[i];
       sort(vv.begin(), vv.end());
       ans+= vv[0];
       }
    }

    else{
       int odd=0; int even=0;

       for(int j=0; j<v[i].size(); j++){
           odd+= (j%2)*v[i][j];
           even+=  (1- (j%2))*(v[i][j]);
       }

       ans+=max(even, odd);
    }
}





    cout<<ans<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}