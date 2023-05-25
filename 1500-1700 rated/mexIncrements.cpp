/*
problem link ->
https://codeforces.com/problemset/problem/1619/E
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int inf =1e9;

void solve(){
    int n;cin>>n;
    int arr[n];
    int freq[n+1]={0};  
    int initfreq[n+1]={0};  
    for(int i=0; i<n; i++) {
        cin>>arr[i];  freq[arr[i]]++; initfreq[arr[i]]++;
    }
    
    int f[n];
    //f[i]=min operations to have all elements from 0....i

    f[0]=(freq[0]>0)?0:inf;
    stack<int> st;
    freq[0]--;
    if(freq[0]>=1) st.push(0);

    for(int i=1; i<n; i++){
      if(freq[i]>0){
        f[i]=f[i-1];
        freq[i]--;
        if(freq[i]>0) st.push(i);
      }

      //warna chote nearest wale ko increment karo

      else{
        if(st.empty()) f[i]=inf;

        else{
            f[i]=f[i-1];
            int temp=st.top();
            st.pop();
            freq[temp]--;
            f[i]+=i-temp;
            if(freq[temp]>0) st.push(temp);
        }
      }
    }


    // for(int i=0; i<n; i++) cout<<f[i]<<" ";

    int ans[n];
     ans[0]=(initfreq[0]);
     for(int i=1; i<=n;i++){
        ans[i]=initfreq[i]+ f[i-1];
        if(ans[i]>=inf) ans[i]=-1;
     }

     for(int i=0; i<=n; i++){
        cout<<ans[i]<<" ";
     }
    cout<<endl;
}

int32_t main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}