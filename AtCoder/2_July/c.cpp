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

/*
1/1*2= 1 - 1/2
1/2*3= 1/2 - 1/3
1/3*4= 1/3 - 1/4


... = 1 - 1/5
.... = 1

*/
 
void solve(){
    int n; cin>>n;

    if(n==1){
        cout<<"Yes"<<endl;
        cout<<1<<endl;
        return;
    }

    if(n==2){
        cout<<"No"<<endl;
        return;
    }


    cout<<"Yes"<<endl;

   set<int> st;
    for(int i=1; i<n; i++)
    {
      st.insert(i*(i+1));
    }
    st.insert(n);
    if(st.size()==n){
        for(auto x: st) cout<<x<<" ";
        cout<<endl;
        return;
    }

    set<int> ast;

    st.insert(n-1);
    st.erase((n-1)*n);
    for(auto x: st){
        ast.insert(2*x);
    }

    ast.insert(2);
   for(auto x: ast) cout<<x<<" ";
    cout<<endl;

}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}