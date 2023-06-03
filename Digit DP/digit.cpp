//find number of integers between L,and R such that sum of digits= x

/*
1<=L<=R<=1e18
x<=180
*/

//digit dp

#include <bits/stdc++.h>
using namespace std;

int solve(string &num, int n, int x, int tight){   

    if(x<0) return 0;
    if(n==1){
      return (x<=9);
    }
    int len=num.length();
    int answer=0;
    int ub=tight?(num[len-n]-'0'):9;

    //max upper bound tak a ja sakte hain, agar tight hua to s[i] tak warna 9 tak

    for(int dig=0; dig<=ub; dig++){
        answer+=solve(num, n-1,x-dig, tight&(dig==ub));

        //agar tight zero hai to aage bhi zero hi rahega, or 1 hai and current wala bhi upper lim touch kar rha to tight 1 hoga aage ke liye
    }

    return answer;
}



int main(){
    string l,r;
    cin>>l>>r;
    int x; cin>>x;

    cout<<solve(r, r.length(),x, 1)<<endl;

    return 0;

}

