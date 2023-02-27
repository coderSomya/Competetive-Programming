/*
https://codeforces.com/problemset/problem/1679/C
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
    set<int> rows, columns;
    umpii mpr,mpc;

    while(q--){
        int t; cin>>t;
        switch(t){

         case 1:
            int x,y;
            cin>>x>>y;

            rows.insert(x);
            columns.insert(y);
            mpr[x]++; mpc[y]++;
            break;

         case 2:
            
            int a, b;
            cin>>a>>b;

            mpr[a]--; mpc[b]--;
            
            if(mpr[a]==0) rows.erase(a);
            if(mpc[b]==0) columns.erase(b);
            break;

         case 3:
            
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;

            //find largest no. just less than x2
             bool flag=false;
             loop(i,x1,x2+1){
                if(rows.find(i)==rows.end()){
                    // cout<<"No"<<endl;
                    flag=flag || false;
                    break;
                }
                flag=true;
             }

             loop(i,y1,y2+1){
                if(columns.find(i)==columns.end()){
                    // cout<<"No"<<endl;
                    flag=flag || false;
                    break;
                }
                flag=true;
             }

             if(flag) cout<<"Yes"<<endl;
             else cout<<"No"<<endl;
             break;

        }
    }
}
  
  
int32_t main(){
// int t;
// cin>>t;
// while(t--)
solve();
return 0;
}