#include <bits/stdc++.h>
using namespace std;

bool check(string &a, int b[], int upto, int n){
    bool simulate = false;
  
   vector<int> v(n, 0);
   vector<int>last (26, -1);
   int ls=-1;

   for(int i=0; i<=upto; i++){
    v[b[i]-1]++;
   }

//    cout<<"upto"<<upto<<endl;



   for(int i=0; i<n; i++){
     int x= a[i]-'a';
     
     if(last[x]==-1){
        last[x]=i;
     }

     else{
        int past= last[x];
        if(ls<past) {
           
            return false;
        last[x]=i;
     }

    
   }
 if(v[i]==1)ls=i;

}
return true;
}
void solve(){
    int n; cin>>n;
    int m; cin>>m;

    string a; int b[m];

   cin>>a;
    for(int i=0; i<m; i++) cin>>b[i];

    int l=0; int h=m-1;

    int ans= -2;

    while(l<=h){
        int mid=(l+h)/2;

        if(check(a, b, mid, n)){
            cout<<mid<<endl;
            ans=mid; 
            h=mid-1;
        }
        else l=mid+1;
    }

    cout<<ans+1<<endl;
}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}

/*

aabcba
0 2 1

for 0, 2



1
6
3
aabcba
1 3 2

*/