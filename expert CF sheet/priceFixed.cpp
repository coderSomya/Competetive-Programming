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
  
  take_n 
  pair<int,int> arr[n];
  loop(i,0,n){
    int req,time;
    cin>>req>>time;
    arr[i]={time, req};
  }

  sort(arr,arr+n);

  deque<pair<int,int>>dq;

  for(int i=0; i<n; i++){
    dq.push_back({arr[i].first, arr[i].second});
  }

  int ans=0;

  int ct=0;
  while(!dq.empty()){
   
 

    if(dq.size()==1) break;

    if(dq.front().first<=ct){
      ans+=dq.front().second;
      ct+=dq.front().second;
      dq.pop_front();
    }

    else{
        if(ct+dq.back().second>dq.front().first){
            //sara mat hatao;
            //ct+x=dq.front.first
            int remove=dq.front().first-ct;
            ct+=remove;
            dq.back().second-=remove;
            ans+=2*remove;
        }
        else
        {
            //sara hatao;          
            ans+=2*(dq.back().second);
            ct+=dq.back().second;
            dq.pop_back();
        }
    }
  }


   if(!dq.empty() && ct>=dq.front().first){
        ans+=dq.front().second;
        dq.pop_back();
    }
  if(dq.size()==1){
   
    if( dq.front().first-ct>dq.front().second){
      ans+=2*(dq.front().second);
    }
    else{
     int rem= dq.front().first-ct;
     ans+=2*rem;
     dq.front().second-=rem;
     ans+=dq.front().second;
    }
  }

  cout<<ans<<endl;


}
  
  
int32_t main(){
// int t;
// cin>>t;
// while(t--) 
solve();
return 0;
}