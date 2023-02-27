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
 

//we can bring everything to 2, or itself

void solve(){
   int n; cin>>n; int arr[n];
   loop(i,0,n) cin>>arr[i];

   unordered_map<int, vi> mp;
   umpii freq;

   loop(i,0,n) {
    mp[arr[i]].pb(i+1);
    freq[arr[i]]++;
   }

   sort(arr, arr+n);

   if(arr[0]==1 && arr[n-1]!=1){
    cout<<-1<<endl; return;
   }

   if(arr[0]==arr[n-1]){
    cout<<0<<endl; return ;
   }
   int ans=0;
   vector<pair<int, int>> v;

  
 

   //ans exists and is equal to 2
 int last=-1;  
 loop(i,1,n){
    int x=arr[i];
    if(x>arr[0]){
        //make it 2
        int temp=0;

        while(arr[i]!=2){
            arr[i]=(arr[i]+arr[0]-1)/arr[0];
            temp++;
        }

        ans+=temp;

        

         v.pb({mp[arr[i]][freq[arr[i]]-1], mp[arr[0]][0]});

    
        freq[arr[i]]--;

    }
 
   
 }

 //now only thing is tomake arr[0]

 //==2

 for(int i=0; i<freq[arr[0]]; i++){
     //second = arr[freq[arr[0]]];
     int y= arr[freq[arr[0]]];
    int temp=0;
     while(arr[i]!=2){
        arr[i]= (arr[i]+y-1)/y;
        temp++;
     }

     ans+=temp;
     v.pb({mp[arr[0]][i], mp[y][0]});
 }




cout<<ans<<endl;

loop(i,0,v.size()){
    cout<<v[i].first<<" "<<v[i].second<<endl;
}

 }

//ab bus
   

 

  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}