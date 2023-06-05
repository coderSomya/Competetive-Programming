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
    
    int arr[n+1];
    for(int i=1; i<=n; i++)
    cin>>arr[i];
    int pref[n+1];
    pref[0]=0;
    loop(i,1,n+1) pref[i]=pref[i-1]+arr[i];

    int omin=inf; int emin=inf;

    int ans=inf;
    
    for(int i=1; i<=n; i++){
        //best ans till i
        if(i%2){
            omin=min(omin, arr[i]);
            
            if(i==1) continue;
            int odds=(i+1)/2;
            int evens=i/2;

            int temp=pref[i]-omin-emin;
            temp+=omin*(n-odds+1);
            temp+=emin*(n-evens+1);
            
            ans=min(ans, temp);

        }

        else{
          
          emin=min(emin, arr[i]);
          int odds=i/2;
          int evens=i/2;

          int temp=pref[i]-omin-emin;
          temp+=omin*(n-odds+1);
          temp+=emin*(n-evens+1);

          ans=min(ans, temp);
          
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