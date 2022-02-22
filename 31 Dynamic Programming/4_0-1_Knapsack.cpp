#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int,int> > vpi;
#define rep(i,a,b) for(int i=a ;i<b; i++)
#define ff first
#define ss second
#define N (int)1e3+2

int dp1[N][N];

int knapsack(vpi &a, int n, int w){
    if(w<=0 || n<=0)
        return 0;

    if(dp1[n][w] != -1)
        return dp1[n][w];

    if(w<a[n-1].ff)
        dp1[n][w] = knapsack(a,n-1,w);
    else
        dp1[n][w]= max((a[n-1].ss) + knapsack(a,n-1,w-(a[n-1].ff)),
                knapsack(a,n-1,w));

    return dp1[n][w];
}

int main(){
    rep(i,0,N){
        rep(j,0,N)
            dp1[i][j] = -1;
    }

    int n;cin>>n;
    vpi a(n);
    // first -> weight
    // second -> value
    rep(i,0,n) cin>>a[i].ff>>a[i].second;
    int w;cin>>w;

    cout<<knapsack(a,n,w)<<endl;

    vvi dp2(n+1,vi (w+1,0));

    sort(a.begin(),a.end());

    // i -> weight iteration
    // j -> knapsack iteration

    dp2[0][0] = 1;

    rep(i,1,n+1){
        rep(j,0,w+1){
            if(j < a[i-1].ff)
                dp2[i][j] = dp2[i-1][j];
            else{
                dp2[i][j] = max(dp2[i-1][j] , 
                                a[i-1].ss + dp2[i-1][j-a[i-1].ff]);
            }
        }
    }

    cout<<dp2[n][w];
    return 0;
}

/*
3
15 60
30 100
45 150
50
*/