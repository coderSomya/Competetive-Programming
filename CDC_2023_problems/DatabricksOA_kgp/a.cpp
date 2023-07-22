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
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}




int solution(vector<int> audiobooks, vector<string> logs) {

int n= audiobooks.size();
int m=logs.size();

vector<int> hrs(n, 0);

set<int> completed;
set<int> removed;

int curr=0;
for(int i=0; i<m; i++){
    string s= logs[i];
    if(s[0]=='L'){
        int x= s[7]-'0';
        
        hrs[curr]+=x;
        if(hrs[i]>=audiobooks[i]){
            hrs[i]=audiobooks[i];
            completed.insert(i);
        }
        curr++;
        
        while(removed.count(curr)!=0 || completed.count(i)!=0 ){
            curr++;
            if(curr==n){
                curr=0;
            }
        }
    }
    
    else{
        
        int x= s[5];
        
        removed.insert(x);
        
    }
}

int idx=-1;
int maxi=-1;

for(int i=0; i<n; i++){
    if(hrs[i]>=maxi){
        maxi=hrs[i];
        idx=i;
    }
}

return idx;


}
