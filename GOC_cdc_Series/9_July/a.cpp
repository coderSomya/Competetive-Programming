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

int n;
string s;

int dp[100005][3][3];

int rec(int i, int veg, int nonveg){

    if(veg>2 || nonveg>2) return 0;
    if(i==n) return dp[i][veg][nonveg] = (nonveg==2);
   if(dp[i][veg][nonveg]!=-1) return dp[i][veg][nonveg];

    if(s[i]=='V'){
      if(veg<2){
          int p1=rec(i+1,veg+1,nonveg);
          int p2=rec(i+1,veg, nonveg);

          return dp[i][veg][nonveg] = p1+p2;
      }
      else{
        return dp[i][veg][nonveg] = rec(i+1,veg, nonveg);
      }
    }

    else if(s[i]=='M'){
          if(veg<2) return dp[i][veg][nonveg] =  rec(i+1,veg,nonveg);

          else{
            int q1= rec(i+1,veg,nonveg+1);
            int q2=rec(i+1,veg, nonveg);

           return dp[i][veg][nonveg] =  q1+q2;
          }
    }

    else return 0;
}

int rec2(int i, int nonveg, int veg){

    
    if(i==n) return dp[i][nonveg][veg] = (veg==2);
   if(dp[i][nonveg][veg]!=-1) return dp[i][nonveg][veg];

    if(s[i]=='M'){
      if(nonveg<2){
          int p1=rec(i+1,nonveg+1,veg);
          int p2=rec(i+1,nonveg, veg);

          return dp[i][nonveg][veg] = p1+p2;
      }
      else{
        return dp[i][nonveg][veg] = rec(i+1,nonveg, veg);
      }
    }

    else if(s[i]=='V'){
          if(nonveg<2) return dp[i][nonveg][veg] =  rec(i+1,nonveg,veg);

          else{
            int q1= rec(i+1,nonveg,veg+1);
            int q2=rec(i+1,nonveg,veg);

           return dp[i][nonveg][veg] =  q1+q2;
          }
    }

    else return 0;
}
 
 
void solve(){

    cin>>n;
    cin>>s;


    memset(dp,-1, sizeof(dp));

    int ans=rec(0,0,0);
    string s2="";

    for(int i=0; i<n; i++){
        if(s[i]=='M') s2+='V';
        else s2+='M';
    }
    memset(dp,-1, sizeof(dp));
    // s=s2;
    while(!s.empty()) s.pop_back();

    for(int i=0; i<n; i++) s+=s2[i];
    int ans2 = rec(0,0,0);


    cout<<ans+ans2<<endl;


}

void solve2(){
    int n; cin>>n;

    cin>>s;

    vector<pair<int,int>> v;
    int nv=0; int veg=0;

    for(int i=0; i<n; i++)
    {
      nv+=(s[i]=='M');
      veg+= (s[i]=='V');

      v.push_back({veg, nv});
    }


    vector<pair<int,int>> v2;
  nv=0; veg=0;
     for(int i=n-1; i>=0; i--)
    {
      nv+=(s[i]=='M');
      veg+= (s[i]=='V');

      v2.push_back({veg, nv});
    }

    int ans=0;

    for(int i=0; i<n; i++){
        if(s[i]=='M'){
            int t1= v[i].second-1;
            int t2=v2[i].first;


            ans+= max((int)0,t1*(t2*(t2-1)/2));
        }

        else{
            int t1=v[i].first-1;
    int t2= v2[i].second;
ans+= max((int)0,t1*(t2*(t2-1)/2));

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