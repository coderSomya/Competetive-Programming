#include <bits/stdc++.h>
using namespace std;

#define int long long
const int inf = 1e9;



void solve(){
  int n; cin>>n;

  vector<int> diff;
  vector<int> diff2;
  int off, on;
  off=on=0;
  int total=0;

  for(int i=0; i<n; i++){
    int x,y; cin>>x>>y;

    if(x>y){
        on++; diff.push_back(x-y);
    }
    else{
        off++;
        diff2.push_back(y-x);
    }

    total+= max(x,y);
  }

  if(on%2==0){
        cout<<total<<endl;
        return;
  }

  sort(diff.begin(), diff.end());
  sort(diff2.begin(), diff2.end());
  
  total-= min(on  ? diff.front() : inf, off ? diff2.front() : inf);

  cout<<total<<endl;
}

int32_t main(){
//   int t; cin>>t;
//   while(t--)
   solve();

  return 0;

}