/*
Given an array of items with their weight and value.
Find the maximum value of the items that can be stolen using knapsack of capacity W.
Note: You can choose infinite items of each type
*/ 
#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<pair<int,int> > vpi;
#define rep(i,a,b) for(int i=a ; i<b ; i++)
#define ff first
#define ss second
#define N (int)1e3+2
#define INF (int)1e9

int dp1[N][N];

int knapSack(vpi &a,int n,int w){
    if(w<=0 || n<=0){
        return 0;
    }

    if(dp1[n][w] != -1)
        return dp1[n][w];
        
    if(w<a[n-1].ff)
        dp1[n][w]= knapSack(a,n-1,w);
    
    else
        dp1[n][w]= max(a[n-1].ss + knapSack(a,n,w-a[n-1].ff),
                knapSack(a,n-1,w));

    return dp1[n][w];
}

int main(){
    rep(i,0,N){
        rep(j,0,N)
            dp1[i][j] = -1;
    }

    int n;cin>>n;
    vpi a(n);

    rep(i,0,n)
        cin>>a[i].ff>>a[i].ss;
    
    int w;cin>>w;
    // ff -> weight
    // ss -> value
    cout<<knapSack(a,n,w)<<endl;

    sort(a.begin(),a.end());


    vi dp2(w+1,0);

    rep(i,1,w+1){
        rep(j,0,n){
            if((i-(a[j].ff)) >= 0){
                dp2[i] = max(dp2[i],a[j].ss+dp2[i-(a[j].ff)]);
            }
        }
    }

    cout<<dp2[w]<<endl;
    return 0;
}

/*
3
15 60
30 100
45 150
50
*/ 