/*
You are given an array, find the length of longest increasing
Subquence
Subarray : Continuous Block of elements
Subsequence: Path of the array in order
                It may or may not be continuous
                We can take any index but given index chosen
                    must be greater than last chosen index
*/ 
#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
#define rep(i,a,b) for(int i=a ;i<b; i++)
#define ff first
#define ss second
#define N (int)1e5+2
#define INF (int)1e9

int dp1[N];

int LongestIncSS(vi &a, int n){

    if(dp1[n] != (-1)) 
        return dp1[n];
    
    dp1[n] = 1;

    for(int i=1;i<=n;i++){
        dp1[n] = max(dp1[n],(a[n-1] > a[i-1])+LongestIncSS(a,i));
    }

    return dp1[n];
}

int main(){
    rep(i,0,N) dp1[i] = -1;
    
    int n;cin>>n;
    vi a(n);
    rep(i,0,n) cin>>a[i];

    cout<<LongestIncSS(a,n)<<endl;

    // tabulation
    vi dp2(n+1,1);

    rep(i,0,n+1){
        rep(j,0,i){
            dp2[i] = max(dp2[i],dp2[j]+(int)(a[i] > a[j]));
        }
    }
    cout<<dp2[n];
    return 0;
}

/*
9
10 22 9 33 21 50 52 60 80
*/