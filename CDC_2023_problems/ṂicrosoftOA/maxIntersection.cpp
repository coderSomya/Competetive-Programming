#include <bits/stdc++.h>
using namespace std;

#define loop(i,l,r) for(int i=l; i<r; i++)

void solve(){
    int n; cin>>n;

    int arr[n];
    vector<int> v;
    set<int> st;
    loop(i,0,n) {
        cin>>arr[i]; st.insert(arr[i]);
    }
    unordered_map<int,int> start;
    unordered_map<int,int> end;

    

    loop(i,0,n-1){
       int st=min(arr[i], arr[i+1]);
       int en=max(arr[i], arr[i+1]);

       start[st]++;
       end[en]++;
    }

    int curr=0;
    int maxi=0;
    auto itr=st.begin();
    while(itr!=st.end()){
        curr+=start[*itr];
        if(end.find((*itr) - 1)!=end.end()){
            curr-=end[(*itr)-1];
        }
       
        maxi=max(curr, maxi);  
        curr-=end[*itr];
        itr++;
    }


    cout<<maxi<<endl;

}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}