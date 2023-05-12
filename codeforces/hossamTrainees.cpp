#include <bits/stdc++.h>
using namespace std;

const int N= 31633; //sqrt(1e9)
vector<int> primes(N+1,1);
vector<int> check;
void solve(){
    int n; cin>>n; 
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    
    // cout<<check.size()<<endl;
    unordered_set<int> st;
    for(int i=0;i<n;i++){
        for(int j=0; j<check.size(); j++){
            if(arr[i]%check[j]==0){
                if(st.find(check[j])!=st.end()){
                    cout<<"YES"<<endl;
                    return;
                }
                st.insert(check[j]);
            }
        }
    }

    cout<<"NO"<<endl;
    
}

int main(){

    for(int i=2; i<N+1; i++
    ){
       if(primes[i]){
        for(int j=i*i; j<N+1; j+=i){
            primes[j]=0;
        }
       }
    }

    for(int i=2; i<primes.size(); i++) if(primes[i]) check.push_back(i);
    int t; cin>>t;
    while(t--) solve();


    return 0;
}