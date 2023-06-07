#include<bits/stdc++.h>
using namespace std;

#define int long long
 
void solve(){
   int n , k , q,count;
   cin>>n>>k>>q;
   int a[n];
   long long sum=0;
   count=0;
   for( int i =0 ; i< n ; i++)
   {
       cin>>a[i];
   }
   
   
   
   
   
    for( int i =0 ; i< n ; i++)
    {
    
            
    if(a[i] > q){
        
        if(count>=k) 
        {    
              count = max((int)0, count - k+1);
              sum = sum + count*(count+1)/2 ;
             
            
        }
         count=0;
            continue;
        }
        count++;
        
 }
    count =max((int)0, count - k+1);
    sum = sum +count*(count+1)/2;
    
    if(*min_element(a, a+ n) > q ) cout<<0<<"\n";
    else cout<<sum<<"\n";

   
}
 
int32_t main()
{
int t;
cin>>t;
 
while(t--) solve();
    
    return 0;
 
}