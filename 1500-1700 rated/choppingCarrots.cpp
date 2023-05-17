/*
problem link ->
https://codeforces.com/problemset/problem/1706/D1
*/

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin>>arr[i];

    int ans=arr[n-1]-arr[0];

    for(int i=0;i<n;i++){
        //a[i] will be maximum

        int temp=arr[0];
        //temp will store min across all a[j]s

        //can we actually make this the maximum
        if(i!=n-1 && arr[n-1]/k>arr[i]) continue;

        for(int j=0;j<n; j++){
            if(i==j) continue;
            int opt=arr[j]/k;
            //opt will store max value we can obtain from this a[j] such that opt<=arr[i]
            //flag will store wether there exist an elemetn such that a[i] can't be made max

            int l=1; int r=k;

            while(l<=r){
                int mid=(l+r)/2;

                if(arr[j]/mid<=arr[i]){
                   opt=max(opt,arr[j]/mid);
                   r=mid-1;
                }
                else{
                  l=mid+1;
                }
            }
      temp=min(temp, opt);
        }

       ans=min(ans, arr[i]-temp);
    }

    std::cout<<ans<<endl;

}

   
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}