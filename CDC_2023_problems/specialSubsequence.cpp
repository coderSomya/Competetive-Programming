//google nsut


#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9+7;

int fact(int n){
    // cout<<n<<endl;
    if(n==0) return 1;

    return n*fact(n-1);
}


int ncr(int n, int r){

    return fact(n)/(fact(r)*fact(n-r));
}

void solve(){
    int n,k; cin>>n>>k;
    string s; cin>>s;
    vector<int> freq(26, 0);

    for(int i=0; i<n; i++)
    {
           freq[s[i]-'a']++;
    }

    sort(freq.rbegin(), freq.rend());

    int ans=1;

    for(int i=0; i<k; i++){
        ans*=freq[i];
    }

    int last=freq[k-1];
    int idx=-1;

    for(int i=0; i<k; i++) {
        if(freq[i]==last) {
            ans/=freq[i];
        }

        if(freq[i]>last){
            idx=i+1;
        }

    }




   int ct=0; 
    for(int i=0; i<26; i++){
          if(freq[i]==last) {
            ct++;
          }
    }
   int pref=ncr(ct, k-idx);
   
   int temp=1;

    for(int i=0; i<26; i++){
        if(freq[i]==last){
            temp*=freq[i];
        }
    }

  ans*=pref*(temp);

    cout<<(ans%mod)<<endl;


    
}

int32_t main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}

/*
1
12
8
fpbavjsmppdt

ppp  fbavjsmdt

1....9
3*9*
28*27

3*(9c7)


1
16
7
ppzfsncqyzmuwrcv

pp zz cc fsnqyrmuwv

ppzfsncqyzmuwrcv


8*(10c4)

*/