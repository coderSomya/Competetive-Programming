#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const int N = 2e9+1;

void solve(){
    int n; cin>>n;

    int arr[n];

    for(int i=0; i<n; i++) cin>>arr[i];

    int freq[10];
    for(int i=0; i<n; i++)
    {
        freq[arr[i]]++;
    }

    int ans=0;

}

int main(){
   solve();

   return 0;
}