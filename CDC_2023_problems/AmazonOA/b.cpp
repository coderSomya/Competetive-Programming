/*
https://www.thejoboverflow.com/p/p595/
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

void build(vector<int> &ST, vector<int> &arr, int ss, int se, int idx){

    if(ss>se) return;
    if(ss==se) ST[idx]=arr[ss];

    int mid=(ss+se)/2;

    build(ST, arr, ss, mid, 2*idx+1);
    build(ST, arr, mid+1, se, 2*idx+2);

    ST[idx]=ST[2*idx+1]+ST[2*idx+2];
}

void update(vector<int> &ST, vector<int> &arr, int ss, int se, int idx,  int val){
    
     if(ss==se){
        ST[idx]+=val;
        return;
     }

     int mid= (ss+se)/2;
     if(mid>idx){
        update(ST, arr, ss, mid, 2*idx+1, val);
     }
     else update(ST,arr,mid+1,se,2*idx+2, val);

     ST[idx]=ST[2*idx+1]+ST[2*idx+2];


}

int query(vector<int> &ST, vector<int> &arr, int ss, int se, int ql,  int qr, int idx){
   
   if(ss>qr || se<ql){
    return 0;
   }

   if(ss>=ql && se<=qr){
    return ST[idx];
   }

   int mid=(ss+se)/2;

   int left= query(ST, arr, ss, mid, ql, qr, 2*idx+1);
   int right= query(ST, arr, mid+1, se, ql, qr, 2*idx+2);

   return left+right;
}
 
void solve(){
   
   int n; cin>>n;
   vector<vector<int>> v(26, vector<int> (n,0));
   string s; cin>>s;

   vector<int> arr(n);
   for(int i=0; i<n; i++) arr[i]=s[i]-'a';

   for(int i=0; i<n; i++){
    for(int j=0; j<26; j++){
        v[j][i]=(s[i]=='a'+j);
    }
   }

   vector<vector<int>> st(26, vector<int>(4*n+1));

   for(int i=0; i<26; i++){
    build(st[i], v[i], 0,n-1, 1);
   }
   
   int q; cin>>q;
   vector<vector<int>> queries(q);

   for(int  i=0; i<q; i++){
       for(int j=0; j<3; j++){
        cin>>queries[i][j];
       }
   }

  for(int i=0; i<q; i++){

    if(queries[i][0]==1){

        int l=queries[i][1];
        int r=queries[i][2];

        vector<int> temp;

        for(int j=0; j<26;j++){
            int x=query(st[j], v[j], 0,n-1, 0, r, 1);
            int y=query(st[j], v[j], 0,n-1, 0, l, 1);

            temp.push_back(x-y);
        }

        int ans=0;
        for(auto x: temp) ans^=x;

        cout<<ans<<endl;
    }


    else{
      
      int index=queries[i][1];
      int nw = queries[i][2];

      int prev=arr[index-1];
      update(st[prev], v[prev], 0, n-1, 1, -1);
      update(st[nw], v[nw], 0, n-1, 1, 1);

    }
  }
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}