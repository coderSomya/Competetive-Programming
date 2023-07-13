#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin>>n;
    int arr[n+1]={0};

    for(int i=1; i<=n; i++) cin>>arr[i];

    sort(arr, arr+n+1);

    //1.... (n+1)/2

    //(n+1)/2+1.....n
    int i=1; int j=(n+1)/2+1;

    while(j<=n){
        if(arr[j]>arr[i] && arr[j]>arr[i+1]) {
        
            i++; j++;
                continue;
        }

        cout<<"No"<<endl;
        return;
    }


    cout<<"Yes"<<endl;
}

int main(){
    solve();

    return 0;
}