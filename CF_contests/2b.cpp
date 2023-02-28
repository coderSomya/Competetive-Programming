/*
not a correct solution! <😞 > 
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
    take_n
    take_arr

    vi mini;//index of all the minimum elements
    vi others;//indes of other elements
    int x=2e9;
    loop(i,0,n){
        x=min(x, arr[i]);
    }

    loop(i,0,n){
        
        if(arr[i]==x) mini.pb(i);
        else others.pb(i);
    }

    if(others.size()==0) {
        cout<<0<<endl;
        return;
    }

    else if(x==1){
        cout<<-1<<endl;
        return;
    }

    vector<pair<int, int>>v;
    int ans=0;
    int k=arr[mini[0]];

    for(int a: others){

        int temp=0;
        while(arr[a]!=2){
            if(arr[a]==k){
                mini.pb(a);
                break;
            }
            arr[a]=(arr[a]+k-1)/k;
            temp++;
        }
        ans+=temp;
        v.pb({a, mini[0]});
    }

    // cout<<"here atleast"<<endl;
    if(mini.size()!=n){
    int y=arr[others[0]];
    for(int b: mini){
        int temp=0;
        while(arr[b]!=2){
            arr[b]=(arr[b]+y-1)/y;
            temp++;
        }

        ans+=temp;
        v.pb({b, others[0]});
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