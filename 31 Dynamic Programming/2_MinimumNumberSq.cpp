/* Mimimum numbers of squares whose sum is equal to given number n */
#include<bits/stdc++.h>
using namespace std;

#define N (int)1e5+2
#define MOD (int)1e9

int dp1[N];

int MinSquares(int n){
    // base case
    if(n==0 || n==1 || n==2 || n==3){
        dp1[n] = n;
    }

    if(dp1[n] != MOD){
        return dp1[n];
    }

    for(int i=1; i*i<=n; i++){
        dp1[n]= min(dp1[n],1+MinSquares(n-(i*i)));
    }

    return dp1[n];
}

int main(){
    // for(int i=0;i<N;i++)
    //     dp1[i]=MOD;
    int n;
    cin>>n;
    // cout<<MinSquares(n)<<endl;

    // bottom up dynamic programming
    int dp2[N];
    for(int i=0;i<N;i++)
        dp2[i]=MOD;
    dp2[0]=0;
    dp2[1]=1;
    dp2[2]=2;
    dp2[3]=3;
    for(int i=4;i<=n;i++){
        for(int j=1;j*j<=i;j++){
            dp2[i] = min(dp2[i],1+dp2[i-(j*j)]);
        }
    }
    cout<<dp2[n]<<endl;
    return 0;
}