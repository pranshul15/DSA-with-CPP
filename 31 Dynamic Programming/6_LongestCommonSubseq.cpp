/*
Given two strings s1 and s2
We need to output length of longest common subsequence
*/ 
#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
#define rep(i,a,b) for(int i=a ; i<b ; i++)
#define ff first
#define ss second
#define N (int)1e3+2
#define INF (int)1e9

// top-down approach
int dp1[N][N];

int longestCommonSubseq(string &s1,string &s2,int n,int m){
    if(n==0 || m==0)
        return 0;

    if(dp1[n][m] != -1)
        return dp1[n][m];
    
    dp1[n-1][m-1] = (int)(s1[n-1] == s2[m-1])+longestCommonSubseq(s1,s2,n-1,m-1);
    dp1[n-1][m] = longestCommonSubseq(s1,s2,n-1,m);
    dp1[n][m-1] = longestCommonSubseq(s1,s2,n,m-1);

    dp1[n][m] = max(dp1[n-1][m-1],max(dp1[n-1][m],dp1[n][m-1]));

    return dp1[n][m];
}

int main(){
    rep(i,0,N){
        rep(j,0,N)
            dp1[i][j] = -1;
    }
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.size(),m=s2.size();

    cout<<longestCommonSubseq(s1,s2,n,m)<<endl;

    // bottom-up approach
    // tabulation
    s1 = "0" + s1;
    s2 = "0" + s2;
    vvi dp2(n+1,vi(m+1,0));

    rep(i,1,n+1){
        rep(j,1,m+1){
            if(s1[i] == s2[j]){
                dp2[i][j] = 1 + dp2[i-1][j-1];
            }
            else{
                dp2[i][j] = max(dp2[i-1][j],dp2[i][j-1]);
            }
        }
    }

    cout<<dp2[n][m]<<endl;
    return 0;
}