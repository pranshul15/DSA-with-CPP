/*
Given 3 strings of all having length < 100,the task is to find the longest
common sub-sequence in all three given sequences.
*/ 
#include<bits/stdc++.h>
using namespace std;

#define N (int)100

int dp[N][N][N];

int LCS(string &s1,string &s2,string &s3,int i,int j,int k){
    if(i==0 || j==0 || k==0)
        return 0;

    if(dp[i][j][k] != -1)
        return dp[i][j][k];

    dp[i-1][j-1][k-1] = (int)(s1[i-1]==s2[j-1]==s3[k-1])+LCS(s1,s2,s3,i-1,j-1,k-1);
    dp[i-1][j][k] = LCS(s1,s2,s3,i-1,j,k);
    dp[i][j-1][k] = LCS(s1,s2,s3,i,j-1,k);
    dp[i][j][k-1] = LCS(s1,s2,s3,i,j,k-1);

    dp[i][j][k] = max(max(dp[i-1][j-1][k-1],dp[i-1][j][k]),
                        max(dp[i][j-1][k],dp[i][j][k-1]));

    return dp[i][j][k];
}

int main(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++)
                dp[i][j][k] = -1;
        }
    }

    return 0;
}