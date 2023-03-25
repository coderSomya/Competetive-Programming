/*
problem link ->
https://codeforces.com/problemset/problem/1605/C
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
int arr[1000001][3];
int n; string s;
bool func(int i){
   
   int l=0; int r=i-1; int a=0; int b=0; int c=0;
   a=arr[r][0];
   b=arr[r][1];
   c=arr[r][2];
   while(r<n){
     if(a>b && a>c) return true;
    if(r==n-1) break;
    r++; a+=s[r]=='a'; b+=s[r]=='b';
    c+= s[r]=='c';
     
      
      a-=s[l]=='a'; b-=s[l]=='b'; c-=s[l]=='c';
      l++;
   }

   return false;
}


 
void solve(){

    cin>>n;
    cin>>s;
    

    loop(i,0,n) loop(j,0,3) arr[i][j]=0;
        arr[0][0]+= s[0]=='a';
        arr[0][1]+= s[0]=='b';
        arr[0][2]+= s[0]=='c';
    loop(i,1,n){
        arr[i][0]= arr[i-1][0]+ (s[i]=='a');
        arr[i][1]= arr[i-1][1]+ (s[i]=='b');
        arr[i][2]= arr[i-1][2]+ (s[i]=='c');
    }

   //ans cannot be more than 4
   //well it can be, sorry

   //atleast we can say that l,r will always be a,a

   vi v;
   loop(i,0,n) if(s[i]=='a') v.pb(i);

   if(v.size()<2){
    cout<<-1<<endl; return;
   }

   int ans=n+1;

  if(func(2)){
    cout<<2<<endl;
  }
  else if(func(3)){
    cout<<3<<endl;
  }
  else if(func(4)){
    cout<<4<<endl;
  }
  else if(func(7)){
    cout<<7<<endl;
  }

  else cout<<-1<<endl;
  


}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}