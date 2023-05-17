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

    int ans=1e9;

    for(int i=0;i<n;i++){
        //a[i] will be maximum

        int temp=arr[i];
        //temp will store next best across all a[j]s

        for(int j=0;j<n; j++){
            if(i==j) continue;
            int opt=-1;
            bool flag=false;
            //opt will store max value we can obtain from this a[j] such that opt<=arr[i]
            //flag will store wether there exist an elemetn such that a[i] can't be made max

            int l=1; int r=k;

            while(l<=r){
                int mid=(l+r)/2;

                if(arr[j]/mid<=arr[i]){
                   flag=true;
                   opt=max(opt,arr[j]/mid);
                   r=mid-1;
                }
                else{
                  l=mid+1;
                }
            }

            if(!flag){
                break;
            }
            else{
                temp=min(temp, opt);
            }
        }

       if(temp!=-1) ans = min(ans, arr[i]-temp);
    }

    cout<<ans<<endl;

}

   
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}