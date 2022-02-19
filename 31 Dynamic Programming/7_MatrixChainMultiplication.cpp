/*
We are given n matrices, we have to multiply them in 
such a way that number of operations are minimum
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

int dp1[N][N];

int SolveMCM(vi a,int i,int j){
    if(i>=j)
        return 0;

    if(dp1[i][j] != INF)
        return dp1[i][j];

    for(int k=i;k<=j-1;k++){
        int temp_ans = SolveMCM(a,i,k) +
                        SolveMCM(a,k+1,j) +
                        (a[i-1] * a[k] * a[j]);
        dp1[i][j] = min(dp1[i][j],temp_ans);
    }
    return dp1[i][j];
}

int main(){
    rep(i,0,N){
        rep(j,0,N)
            dp1[i][j] = INF;
    }

    int n;cin>>n;
    vi a(n);
    rep(i,0,n) cin>>a[i];

    cout<<SolveMCM(a,1,n-1)<<endl;

    return 0;
}