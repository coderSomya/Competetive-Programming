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

set<int>st;


vi v;
int num;

unordered_map<int,int> mp;
unordered_map<int,int> mp2;

vector<vector<int>> fact(64);

int rec(int i, int mask){
    
    if(i==num){
        return 1;
    }


    bool flag=false;
    int temp=0;

    for(int bit=0; bit<16; bit++){
        //if bit is unset i would like to set it

        if((mask&(1<<bit))==0){
            ///i need to check if its factors are set or not
            bool ff=true;
          for(auto x: fact[mp[bit]]){
            if(mask&(1<<(mp[x]))==0){
                ff=false; break;
            }
          }
            if(ff){
                flag=true;
                int temp_mask=mask|(1<<bit);
                temp+=rec(i+1, temp_mask);
            }
        }
    }
    
    if(!flag) return 0;

    return temp;
    
}
 
void solve(){

    vector<int> all= {2,3,4,6,8,9,12,16,18,24,27,32,36,48,54,64};

    int ct=0; int ct2=0;
    for(auto x: all) mp[ct++]=x;
    for(auto x: all) mp2[x]=ct2++;

    for(auto x: all){
        for(int i=2; i*i<=x; i++){
            if(x%i==0) {
                fact[x].push_back(i);
                if(i*i!=x) fact[x].push_back(x/i);
            }
        }
    }


    v.clear();
    int n; cin>>n;
    for(int i=0; i<16; i++){
        if(all[i]<=n) v.push_back(v[i]);
        else break;
    }

    
   num=v.size();

}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}