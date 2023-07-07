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


#define INT_BITS 9


int gauss(vector<int> &set, int n)
{
	int index = 0;

	for (int i = INT_BITS-1; i >= 0; i--)
	{
		
		int maxInd = index;
		int maxEle = -inf;
		for (int j = index; j < n; j++)
		{
			if ( (set[j] & (1 << i)) != 0
					&& set[j] > maxEle )
				maxEle = set[j], maxInd = j;
		}


		if (maxEle == -inf)
		continue;
		swap(set[index], set[maxInd]);

		maxInd = index;

		for (int j=0; j<n; j++)
		{
		
			if (j != maxInd &&
			(set[j] & (1 << i)) != 0)
				set[j] = set[j] ^ set[maxInd];
		}


		index++;
	}

	// Final result is
	// XOR of all elements
	int res = 0;
	for (int i = 0; i < n; i++)
		res ^= set[i];
	return res;
}






 
 
void solve(){
  take_n
  take_arr
  vi v;
  int res=0;
  for(int i=0; i<n; i++)
  {
    v.pb(arr[i]);
    res=res^arr[i];
  }
 
   

//   int m=gauss(v,n);

for(int i=0; i<n; i++) v.pb(arr[i]);

  int dp[2*n];

  int maxi=0;
  dp[0]=arr[0];

  maxi=dp[0];

  for(int i=1; i<2*n; i++)
  {
   dp[i]=max(v[i], v[i]^dp[i-1]);
   maxi=max(maxi, dp[i]);
  }




 int dp1[n];

  int maxi2=0;
  dp1[0]=res^arr[0];

  maxi2=dp1[0];

  for(int i=1; i<n; i++)
  {
   dp1[i]=max(res^arr[i], res^arr[i]^dp1[i-1]);
   maxi2=max(maxi2, dp1[i]);
  }





//    int curr=arr[0];
//    maxi=curr;
//   for(int i=1; i<n; i++){
//     curr^=arr[i];
//     maxi=max(maxi, curr);
//   }
  cout<<maxi<<endl;
}
  
  
int32_t main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}