#include <bits/stdc++.h>
  using namespace std;
  
  const int inf = 2e9;
  int n;
  
void buildST(vector<int> &ST, vector<int> &arr, int ss, int se, int idx){
  
  if(ss>se) return;
  if(ss==se){
    assert(ss<n && ss>=0);
    ST[idx]=arr[ss];
    return;
  }
  
  int mid=(ss+se)/2;
  buildST(ST, arr, ss, mid, 2*idx+1);
  buildST(ST, arr, mid+1,se, 2*idx+2);
  
  ST[idx]=min(ST[2*idx+1], ST[2*idx+2]);
  
}

int query(vector<int> &ST, vector<int> &arr, int ss, int se, int ql, int qr, int idx){
  
  if(ss>qr || se<ql){
    return inf;
  }
  
  else if(ss>=ql && se<=qr){
    return ST[idx];
  }
  
  int mid =(ss+se)/2;
  
  int left= query(ST, arr, ss, mid, ql ,qr, 2*idx+1);
  int right= query(ST, arr, mid+1, se, ql ,qr, 2*idx+2);
  
  return min(left, right);
}

  int main() {

    int N, x;
    cin>>N>>x;
    
     n=N;
    
    vector<int> arr(N);
    long long ans = 3e13;
    for(int i=0; i<N; i++) cin>>arr[i];
    
    vector<int> ST(4*n+1);
    buildST(ST, arr, 0, n-1, 1);
    
    for(int i=0; i<N; i++){
      
      
      //we are performing operation for i times
      
      long long temp = i*x;
      
      for(int j=0; j< N; j++){
        
        //j.. j+i
        int a= j; int b= j+i;
        int c=0; int d=0;
        if(b>=n){
          b=n-1;
          c=0;
          d=(i - (b-a+1));
        }
        int mini= query(ST, arr, 0, n-1, a, b, 1);
        if(d!=0) mini=min(mini, query(ST, arr, 0, n-1, c, d, 1));
        
        temp+=mini;
      }
      
      ans=min(ans, temp);
      
      
    }
    
    cout<<ans<<endl;
    

  }