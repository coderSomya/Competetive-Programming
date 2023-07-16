#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;

    vector<long long> v(n);
    for(int i=0; i<n; i++) cin>>v[i];

    vector<vector<int>> contri(15,vector<int>(10, 0));

    //contri[i][j] = number of js in ith pos 

    for(int i=0; i<n; i++){
        int x=v[i];
        int pos=0;
        while(x){
            int rem = x%10;
            contri[pos][rem]++;
            pos++;
            x/=10;
        }
    }

    int carry=0;

     int ans=0;
     for(int i=0; i<n; i++){
        int pos = 0;
       int x=v[i];
        while(x){
            int rem= x%10;
            contri[pos][rem]--;
            pos++;
            x/=10;
        }
        int c=v[i];
        int bit=0;
        while(c){
            int left= c%10;

            for(int i=0; i<10; i++){
                ans+= (i+left)*contri[bit][i];
                bit++;
                if(i+left >=10) carry+= contri[bit][i];
            }

            c/=10;
        }


         int ps = 0;
       int xx=v[i];
        while(xx){
            int rem= x%10;
            contri[ps][rem]++;
            pos++;
            xx/=10;
        }
     }

     ans-= 9*carry;

     cout<<ans<<endl;
}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}