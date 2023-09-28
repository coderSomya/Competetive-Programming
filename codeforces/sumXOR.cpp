/*
problem link ->
https://codeforces.com/problemset/problem/1879/D
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod= 998244353;

int total(int n){
    return n*(n+1)/2;
}


void solve(){
    int n; cin>>n;
    int arr[n+1];
    for(int i=1; i<=n; i++) cin>>arr[i];

    int ans=0;

    
    for(int i=0; i<=30; i++){
        int fact=(1<<i);
       
        
    int number_of_odd_lengths=0;
    int number_of_even_lengths=0;
    int sum_of_odds=0;
    int sum_of_evens=0;



        for(int j=1; j<=n; j++){
            int dig=(arr[j]&(1ll<<i));

            if(dig){
               swap(number_of_even_lengths, number_of_odd_lengths);

               number_of_odd_lengths++;

               sum_of_odds=sum_of_evens+number_of_odd_lengths;
               sum_of_evens=total(j)-sum_of_odds;

               ans+=(fact*(sum_of_odds%mod))%mod;
               ans%=mod;
            }
            else{
                number_of_even_lengths++;

                sum_of_odds+=number_of_odd_lengths;
                sum_of_evens=total(j)-sum_of_odds;


                ans+=(fact*(sum_of_odds)%mod)%mod;
                ans%=mod;
            }
        }
    }


    cout<<ans<<endl;

}

int32_t main(){
    // int t; cin>>t;
    // while(t--)
    solve();

    return 0;
}



/*
12629774189

257421502

*/