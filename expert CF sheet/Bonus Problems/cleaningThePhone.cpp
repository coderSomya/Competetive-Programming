#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,m; cin>>n>>m;
    int a[n],b[n];

    for(int i=0; i<n;i++) cin>>a[i];
    for(int i=0; i<n;i++) cin>>b[i];

    vector<int> ones, twos;
    int sum=0;

    for(int i=0; i<n; i++){
        if(b[i]==1) ones.push_back(a[i]);
        if(b[i]==2) twos.push_back(a[i]);
        sum+=a[i];
    }

    sort(ones.rbegin(), ones.rend());
    sort(twos.rbegin(), twos.rend());

    /*
    1= 2 2
    2= 3 1
    */
   if(sum<m){
    cout<<-1<<endl;
    return;
   }

   int i=0; int j=0;

   int curr=0;
   int ans=0;
    while(i<ones.size() && j<twos.size()){
    int c= (i+1<ones.size());
    int x=ones[i]+(i+1<ones.size() ? ones[i+1] : 0);
    int y=twos[j];

    if(curr+ones[i]>=m){
        ans+=1;
        curr+=ones[i];
        break;
    }

    if(curr+max(x,y)>=m){
        ans+=2;
        curr+=max(x,y);
        break;
    }
    if(curr+ones[i]+twos[j]>=m){
        ans+=3;
        curr+=ones[i]+twos[j];
        break;
    }

    if(ones[i]>=twos[j]){
        ans+=1;
        curr+=ones[i];
        i++;
        continue;
    }

    if(x>y){
        //take two/one from ones
        ans+=(1+c);
        curr+=x;
        if(curr>=m) break;
        i+=2;
    }
    else{
        ans+=2;
        curr+=y;
        if(curr>=m) break;
        j++;
    }

    }   
   while(curr<m && i<ones.size()){
    curr+=ones[i++];
    ans++;
   }

   while(curr<m && j<twos.size()){
    curr+=twos[j++];
    ans+=2;
   }


   cout<<ans<<endl;
}

int main(){
    int t; cin>>t;
    while(t--) solve();

    return 0;
}

