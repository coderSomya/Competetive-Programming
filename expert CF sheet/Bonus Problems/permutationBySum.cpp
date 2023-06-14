/*
problem link->
https://codeforces.com/problemset/problem/1512/E
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
const int N= 500;
const int SUM=N*(N+1)/2;

int sum(int l, int r){
    int x= l*(l+1)/2;
    int y= r*(r+1)/2;

    return y-x;
}
 
void solve(){
   int n,l,r,s;
   cin>>n>>l>>r>>s;

   int ans[n+1];

   int len=r-l+1;

   if(l==1 and r==n){
    if(s!=n*(n+1)/2) cout<<-1<<endl;
    return;
   }

   //there will always be either a subarray of elements

   //or a subarray to the left and subarray to the right immediate to an element

   //iterate on starting idx
  int idx=-1;
  bool flag=false;
  int total=n*(n+1)/2;
   for(int i=0;i<=n-len; i++){
       //i+1...i+len
       if(sum(i,i+len)==s){
        idx=i;
      
        break;
       }
   }
      int llen;
  
   if(idx==-1){
    
     //n^2 me search karo
     for(int i=2; i<=n-1; i++){
        for(int j=1; j<len; j++){
            //j = left side me length
            int rlen=len-j;
            int ll=i-j;
            int lr=i-1;
            int rl=i+1;
            int rr=i+rlen;

            if(sum(ll-1,lr)+sum(rl-1,rr)==s){
                idx=i; llen=j;
                flag=true;
                break;
            }
        }
     }
   }


   if(idx==-1){
    cout<<-1<<endl;
    return;
   }  



   int arr[n+1]={0};

   if(!flag){
    int j=l;
    set<int> st;
    for(int i=1; i<=n; i++) st.insert(i);
       for(int i=1; i<=len; i++){
  arr[j]=idx+i;
  j++; st.erase(idx+i);
       }

       for(int i=1; i<=n; i++){
        if(arr[i]==0){
            int x=*(st.begin());
            st.erase(x);
            arr[i]=x;
        }
       }
   }

   else{
    int j=l;
    set<int> st;
    for(int i=1; i<=n; i++) st.insert(i);
    for(int i=1; i<=llen; i++){
        arr[j]=idx-i; j++; st.erase(idx-i);
    }

    for(int i=1; i<=len-llen; i++){
        arr[j]=idx+i; j++; st.erase(idx+i);
    }

     for(int i=1; i<=n; i++){
        if(arr[i]==0){
            int x=*(st.begin());
            st.erase(x);
            arr[i]=x;
        }
       }
   
   }
   

   for(int i=1; i<=n; i++){
     cout<<arr[i]<<" ";
   }
      cout<<endl;


}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}