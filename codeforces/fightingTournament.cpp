/*
problem link ->
https://codeforces.com/problemset/problem/1719/C
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
    int n,q; cin>>n>>q;
    take_arr
    umpii mp;
    loop(i,0,n) mp[arr[i]]=i;
    int pref[n];
    pref[0]=arr[0];
    vi dist(n+1,n-1); 
    loop(i,1,n){
        if(arr[i]>pref[i-1]) dist[pref[i-1]]=i-1; 
 pref[i]=max(arr[i], pref[i-1]);
    }
    int helper[n+1]={0}; 
    //stores no. of wins of arr[i] in the first n-1 attempts
    deque<int> dq;
    loop(i,0,n) dq.pb(arr[i]);
    
    for(int i=0; i<n-1; i++){
       int x=dq.front();
       dq.pop_front(); 
       int y=dq.front();
       dq.pop_front();
       helper[max(x,y)]++;
       dq.push_front(max(x,y));
       dq.push_back(min(x,y));
    }

    int maxid;
    loop(i,0,n) if(arr[i]==n) maxid=i;

    while(q--){
        int i,k; cin>>i>>k;
        i--;

        if(k<n){
            if(pref[i]!=arr[i]){
            
                cout<<0<<endl;
            }
            else if(i>k) {
              
                cout<<0<<endl;
            }
            else{
                
                int temp=(i>0); int j=1;
                // int fights=i;
                // while(fights<k && i+j<n && pref[i+j]==arr[i]){
                //     temp++;
                //     j++; fights++;
                // }

                temp+= min(k-i,dist[arr[i]]-i);
                
                cout<<temp<<endl;
            }
        }
        else{
            if(i==maxid){
                 int temp= helper[arr[i]]+k-(n-1);
                 
                 cout<<temp<<endl;
            }
            else{
              
                cout<<helper[arr[i]]<<endl;
            }
        }
    }
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}