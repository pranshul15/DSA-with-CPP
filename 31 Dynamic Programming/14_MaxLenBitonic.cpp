/*
Given an array of n numbers. Find the maximum length of bitonic subsequence. A
Subsequence is bitonic if it is first strictly increasing and then strictly decreasing
or entirely increasing or decreasing
*/ 
#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi > vvi;
#define rep(i,a,b) for(int i=a ; i<b ; i++)
#define ff first
#define ss second
#define N (int)1e3+2
#define INF (int)1e9

int dp1[N][2];

int longestDecSubseq(vector<int> &a,int n){
    if(dp1[n][1] != -1)
        return dp1[n][1];

    dp1[n][1] = 1;

    for(int i=n+1;i<a.size();i++){
        dp1[n][1] = max(dp1[n][1],(int)(a[n]>a[i])+longestDecSubseq(a,i));
    }

    return dp1[n][1];
}

int longestIncSubseq(vector<int> &a,int n){
    
    if(dp1[n][0] != -1)
        return dp1[n][0];

    dp1[n][0] = 1;

    for(int i=0;i<n;i++){
        dp1[n][0] = max(dp1[n][0],(int)(a[n]>a[i])+longestIncSubseq(a,i));
    }

    return dp1[n][0];
}

int longestBitonicSeq(vector<int> &a,int n){
    int ans = 0;
    for(int i=0;i<n;i++){
        ans = max(ans,longestIncSubseq(a,i)+longestDecSubseq(a,i)-1);
    }
    return ans;
}

int main(){
    rep(i,0,N)
        dp1[i][0] = dp1[i][1] = -1;

    int n;cin>>n;
    vector<int> a(n);

    for(int i=0;i<n;i++)
        cin>>a[i];

    vvi dp2(n,vi(2,0));
    dp2[0][0] = 1; // longest increasing subseq
    dp2[n-1][1] = 1; // longest decreasing subseq

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            dp2[i][0] = max(dp2[i][0],dp2[j][0] + (int)(a[i]>a[j]));
            dp2[n-i-1][1] = max(dp2[n-i-1][1],
                            dp2[n-j-1][1] + (int)(a[n-i-1]>a[n-j-1]));
        }
    }

    int ans = 0;
    for(int i=0;i<n;i++){
        ans = max(ans,dp2[i][0]+dp2[i][1]-1);
    }
    cout<<ans<<endl;
    return 0;
}

/*
10
10 22 9 33 21 50 41 60 80 3
*/ 