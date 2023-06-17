/*
problem link ->
https://leetcode.com/problems/number-of-pairs-satisfying-inequality/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {

private:
int find_b(vector<int> &nums, int i, int n, int val){
    int l=i; int h=n-1;

    int ans=l;
    while(l<=h){
        int mid=(l+h)/2;

        if(nums[mid]<=val){
            ans=mid; l=mid+1;
        }
        else h=mid-1;
    }

    return ans;
}

int find_s(vector<int> &nums, int i, int n, int val){
    int l=0; int h=i-1; int ans=-1;

    while(l<=h){
        int mid=(l+h)/2;

        if(nums[mid]<val){
            ans=mid; 
            l=mid+1;
        }

        else{
            h=mid-1;
        }
    }

    return ans;
}
private: 
int N=1e4;

int BIT[(int)6e4+1]={0};

int query(int i){
    int sum=0;


    while(i>0){
        sum+= BIT[i];
        i-= i&(-i);
   
    }

    return sum;
}

void update(int i, int val){
 
    while(i<=6*N){
        BIT[i]+=val;
        i+= (i&(-i));
    }
}



public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int  n=nums1.size(); int k =diff;
        vector<int> nums(n);
        for(int i=0; i<n; i++) nums[i]=nums1[i]-nums2[i];

        long long ans=0;

       
        for(int i=n-1; i>=0; i--){
           ans+= query(6*N)- query(3*N + nums[i]-k-1);
           update(3*N+nums[i], 1);
        }

        return ans;
    }
};