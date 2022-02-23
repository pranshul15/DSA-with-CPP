/*
Given n friends, each one can remain singel or can  be paired up with some other friend.
Each friend can be paired only once.
Find out the total number of ways in which friends can remain single or can be paired up
*/ 
#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi > vvi;
#define rep(i,a,b) for(int i=a ; i<b ; i++)
#define ff first
#define ss second
#define N (int)1e5+2
#define INF (int)1e9

int dp1[N];

int FriendPairing(int n){
    if(n==1 || n==2)
        return n;
    
    if(dp1[n] != -1)
        return dp1[n];

    dp1[n] = FriendPairing(n-1) + (n-1)*FriendPairing(n-2);

    return dp1[n];
}

int main(){
    rep(i,0,N)
        dp1[i] = -1;

    int n;cin>>n;

    cout<<FriendPairing(n)<<endl;

    vi dp2(n+1,0);

    dp2[1] = 1;
    dp2[2] = 2;

    rep(i,3,n+1)
        dp2[i] = dp2[i-1] + ((i-1)*dp2[i-2]);

    cout<<dp2[n]<<endl;
    return 0;
}