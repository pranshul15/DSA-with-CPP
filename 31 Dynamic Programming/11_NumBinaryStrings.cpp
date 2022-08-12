/*
Count the number of binary strings without consecutive 1's
Given a positive integer N, count all the possible distinct binary strings
of length N such that there are no consecutive 1's
*/
#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
#define rep(i,a,b) for(int i=a ; i<b ; i++)
#define ff first
#define ss second
#define N (int)1e5+2
#define INF (int)1e9

int dp1[N][2];

int Solver(int n,int i){
    if(n==1)
        return 1;

    if(dp1[n][i] != -1)
        return dp1[n][i];

    if(i==0){
        dp1[n][0] = Solver(n-1,0) + Solver(n-1,1);
        
        // dp1[n][0] = Solver(n-1,0) + Solver(n-2,0);
        // this makes it a fibonacci series
    }
    if(i==1){
        dp1[n][1] = Solver(n-1,0);
    }

    return dp1[n][i];
}

int BinaryStrings(int n){
    return Solver(n,0) + Solver(n,1);
}

int main(){
    rep(i,0,N)
        dp1[i][0] = dp1[i][1] = -1;
    
    int n;cin>>n;
    
    cout<<BinaryStrings(n)<<endl;

    vvi dp2(n+1,vi(2,0));

    dp2[1][0] = dp2[1][1] = 1;

    rep(i,2,n+1){
        dp2[i][0] = dp2[i-1][0] + dp2[i-1][1];
        dp2[i][1] = dp2[i-1][0];
    }

    cout<<dp2[n][0] + dp2[n][1]<<endl;
    return 0;
}