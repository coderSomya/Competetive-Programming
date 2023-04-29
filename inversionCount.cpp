#include <bits/stdc++.h>
using namespace std;


int merge(int a[], int s, int e){
   
   int mid=(s+e)/2;
   int i=s;
   int j=mid+1;
   int k=s;

   int temp[100000];

   int ct=0; //store cross inversions

   while(i<=mid && j<=e){
    if(a[i]<a[j]){
        temp[k++]=a[i++];
    }
    else{
        ct+=mid-i+1;
        temp[k++]=a[j++];
    }
   }

   while(i<=mid) temp[k++]=a[i++];
   while(j<=e) temp[k++]=a[j++];

   for(int i=s; i<=e; i++) a[i]=temp[i];

   return ct;

}

//using merge sort type algorithm
int mergeSort(int a[], int s, int e){
    if(s>=e) return 0;

    int mid=(s+e)/2;

    int x= mergeSort(a,s,mid);
    int y= mergeSort(a,mid+1,e);

    int z= merge(a,s,e);

    return x+y+z;
}


int main(){
    int n; cin>>n; 
    int arr[n]; 
    for(int i=0; i<n; i++) cin>>arr[i];

    int ans=mergeSort(arr,0,n-1);
    cout<<ans<<endl;
    

}


