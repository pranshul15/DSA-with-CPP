/*
Given a set of coins and a value 'V'.
Find the number of ways we can make change of 'V'
*/ 
#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define N (int)1e3+2
int dp1[N][N];

int CoinExchange(vi &a, int x, int v){
    if(v == 0)
        return 1;
    if(v < 0)
        return 0;
    if(x <= 0)
        return 0;

    if(dp1[x][v] != -1)
        return dp1[x][v];

    dp1[x][v] = CoinExchange(a,x,v-a[x-1]) + CoinExchange(a,x-1,v);

    return dp1[x][v];
}

int main(){
    rep(i,0,N){
        rep(j,0,N){
            dp1[i][j]=-1;
        }
    }


    int n;cin>>n;
    vector<int> denomination(n);

    rep(i,0,n) cin>>denomination[i];
    int v;cin>>v;

    // cout<<CoinExchange(denomination,n,v);

    vvi dp2(n+1,vi(v+1,0));

    dp2[0][0] = 1;

    rep(i,1,n+1){
        rep(j,0,v+1){
            if(j-denomination[i-1] >= 0)
                dp2[i][j] += dp2[i][j-denomination[i-1]];
            
            dp2[i][j] += dp2[i-1][j];
        }
    }
    return 0;
}