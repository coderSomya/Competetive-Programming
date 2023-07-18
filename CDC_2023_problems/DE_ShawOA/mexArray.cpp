/*
https://www.desiqna.in/14025/de-shaw-coding-oa-solution-july-2023-sde1-38-lac-ctc
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

    int n; cin>>n;
    vector<int> arr(n+1);
    umpii pos;
    for(int i=0; i<n; i++){
        cin>>arr[i+1];
        pos[arr[i+1]]=i+1;
    }

    int res[n+1]={0};
    res[0]=0;
  set<int> st;
    for(int i=1;i<=n; i++){
        int x= pos[i];
    if(st.empty()){
        res[i]+= (pos[i]-1)*(pos[i])/2;
        res[i]+= (n-pos[i])*(n-pos[i]+1)/2;
    }
    else{
       int ff= *st.begin();
       auto l= st.end();
       l--;
       int ll= *l;

       if(pos[i]>ff && pos[i]<ll){
        res[i]=0;
       }
       else{
        if(pos[i]>ll){
        //ff....ll.. pos
         int strt= ff;
         int end= pos[i]-ll;
         res[i]= strt*end;
        }
        if(pos[i]<ff){
         //pos...ff..ll
         int strt=ff-pos[i];
         int end= n-ll+1;
         res[i]+= strt*end;
        }
       }

    //    st.insert(pos[i]);
    }

    st.insert(pos[i]);
    }


   int k; cin>>k;

   int curr=0;
   int ans=-1;

   for(int i=1; i<=n; i++){
    if(curr+res[i]>=k){
        ans=i; break;
    }
    curr+=res[i];
   }
   cout<<ans<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}