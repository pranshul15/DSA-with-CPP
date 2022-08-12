#include<bits/stdc++.h>
using namespace std;

#define N (int)1e5+2
vector<int> dp(N,-1);
vector<int> dp2(N,-1);

// memoization, top down
int fib(int n){
    if(n==0)
        return 0;
    if(n==1)
        return 0;
    if(n==2)
        return 1;

    if(dp[n] != -1)
        return dp[n];

    dp[n] = fib(n-1)+fib(n-2);

    return dp[n];
}

int main(){
    int n;
    cin>>n;

// bottom up 
    dp2[0] = 0;
    dp2[1] = 0;
    dp2[2] = 1;
    for(int i=3;i<=n;i++){
        dp2[i] = dp2[i-1]+dp2[i-2];
    }

    for(int i=1;i<=n;i++)
        cout<<dp2[i]<<endl;

    return 0;
}