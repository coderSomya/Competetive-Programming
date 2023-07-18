/*
problem link -
https://www.desiqna.in/13820/google-oa-sde2-jan-2023
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


int nc2(int n){
    return n*(n-1)/2;
}
 
 
void solve(){

    int n; cin>>n;
    vector<int> v(n+1);
    for(int i=1; i<=n; i++){
        cin>>v[i];
    }

    vector<vector<int>> adj(n+1);

    for(int i=1; i<=n; i++){
       adj[i].push_back(v[i]);
    }

    int ans=0;

    umpii mp;

    for(int i=1; i<=n; i++)
    {   
        int x= i;
        for(int j=0; j<4; j++){
            x=adj[x][0];
        }

        mp[x]++;
    }

    for(auto x: mp){
        ans+= nc2(x.second);
    }

    cout<<ans<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}


/*
1 3 2 5 6 4

1-1

2-3-2

4-5-6-4

A[A[A[1]]]
A[A[1]]
A[1]
1

A[A[A[2]]]
A[A[3]]
A[2]
3

A[A[A[3]]]
A[A[2]]
A[3]
2

A[A[A[4]]]
A[A[5]]
A[6]
4

A[A[A[5]]]
A[A[6]]
A[4]
5

A[A[A[6]]]
A[A[4]]
A[5]
6


4 2 1 2

3-1-4-2=2


1 3 2 4 5

1=1

2=3

4=4

5=5


*/