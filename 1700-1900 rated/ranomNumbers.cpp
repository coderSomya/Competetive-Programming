#include <bits/stdc++.h>
using namespace std;
#define loop(i,l,r)     for(int i=l; i<r; i++)
#define int             long long
#define pb              push_back
#define vi              vector<int>
#define mkp             make_pair<int,int>
#define umpii           unordered_map<int,int>
#define maxheap         priority_queue<int>
#define minheap         priority_queue<int, vi,greater<int>>
#define setbits(x)      __builtin_popcountll(x)
#define zerobits(x)     __builtin_ctzll(x)
#define in_arr(A,n)     loop(i,0,n) cin>>A[i];
#define p_arr(A,n)      loop(i,0,n) cout<<A[i]
;
#define pln_arr(A,n)    loop(i,0,n) cout<<A[i]<<endl
#define take_n          int n; cin>>n;
#define take_arr        int arr[n]; loop(i,0,n) cin>>arr[i];
  
  
const int mod= 1e9+7;
const int inf= 1e15;


unordered_map<char, int> contri;

void solve(){
    
    string s; cin>>s;
    int n=s.length();

    int arr[n];
    int freq[5]={0};

    for(int i=n-1; i>=0; i--){
        int x=s[i]-'A';
        bool flag=false;
        for(int j=x+1; j<5; j++){
            if(freq[j]>0) flag=true;
        }
        
        if(flag) arr[i]=-contri['A'+x];
        else arr[i]= contri['A'+x];

        freq[x]++;
    }

    int suff[n];

    suff[n-1]=arr[n-1];
    for(int i=n-2; i>=0; i--)suff[i]=suff[i+1]+arr[i];
    
    // at i, we wanna increase its value above the maximum value found so far to the right
    //this will decrease the value of some of the previous values

    int maxi=-1;
    int res=suff[0];
    int pref[n][5]={0};
    for(int e=0; e<5; e++) pref[0][e]+= (s[0]=='A'+e);

    
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<5; j++){
            pref[i][j]=pref[i-1][j]+ (s[i]==('A'+j));
        }
    }

   
   int final=res;
    for(int i=n-1; i>=0; i--){
        int temp;
        for(int j=1+max(maxi,(int)(s[i]-'A')); j<5; j++){
            temp=res;
            temp-= arr[i];
            temp+= contri[j+'A'];
    
            for(int k=max(maxi, (int)(s[i]-'A'));k<j; k++){
                if(i==0) break;
                temp-=2*(pref[i-1][k]*contri[k+'A']);
            }
            final = max(final, temp);
        }

       


        maxi=max(maxi,(int)(s[i]-'A'));
        // final = max(final, temp);

    }

     //agar abhi tak ka max i hi hai to use decrease karke bhi dekh sakte hain
   
   maxi=0;
   for(int i=n-1; i>=0; i--){
       if(s[i]-'A' <=maxi) continue;
       int temp;
       for(int j=maxi; j<s[i]-'A'; j++){
        temp=res;
         temp-=arr[i];
         temp+=contri[j+'A'];
       
         for(int k=s[i]-'A'; k>=j; k--){
            if(i==0) break;
             temp+= 2*pref[i-1][k]*contri[k+'A'];
         }

         final=max(final, temp);
       }

       maxi=max(maxi, (int)(s[i]-'A'));
   }

//  cout<<suff[0]<<endl;
    cout<<final<<endl;
    

}
  
  
int32_t main(){
contri['A']=1;
contri['B']=10;
contri['C']=100;
contri['D']=1000;
contri['E']=10000;
int t;
cin>>t;
while(t--) solve();
return 0;
}