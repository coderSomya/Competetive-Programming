#include <iostream>
#include <bitset>
using namespace std;

//space optimized solution using bitset

bitset<100> col,ld,rd;

int ans=0;

void nQueen(int n, int r){
   
   if(r==n){
    ans++; return;
   }

   for(int c=0; c<n; c++){
    if(!col[c] && !ld[r-c+1+(n-1)] && !rd[r+c])
    {
        col[c]=ld[r-c+1+(n-1)]=rd[r+c]=1;
        nQueen(n, r+1);
        col[c]=ld[r-c+1+(n-1)]=rd[r+c]=0;
    }
   }
 
}


int main(){

    int n; cin>>n; 
    nQueen(n,0);
    cout<<ans<<endl;
    return 0;
}