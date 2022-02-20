/*
Rahul and Neha are playing a coin game.
They are given n coins with values x1,x2,....xn where 'n' is always even.
They take alternate terms. In each turn, a player picks either the first
coin or from the last coin from the rows and removes it from the row.
The value of coin is received by that player.
Determine the maximum value that Rahul can win if he moves first.
Both the players play optimally.
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

int OptimalGame(vi &a,int i,int j){
    if(i>j) return 0;

    // If there is one element
    if(i==j) return a[i];
    
    // If there are two elements
    if((j-i)==1) return max(a[i],a[j]);

    if(dp1[i][j] != -1)
        return dp1[i][j];

    // Neha will make sure that Rahul gets the minimum in his next chance
    
    // if Rahul selects the i
    int val1 = a[i]+min(OptimalGame(a,i+2,j),OptimalGame(a,i+1,j-1));
    
    // if Rahul selects the j
    int val2 = a[j]+min(OptimalGame(a,i+1,j-1),OptimalGame(a,i,j-2));

    // Since Rahul has to win, he will select maximum value
    dp1[i][j] = max(val1,val2);

    return dp1[i][j];
}

int main(){
    rep(i,0,N){
        rep(j,0,N)
            dp1[i][j] = -1;
    }
    
    int n;cin>>n;
    vi a(n);
    rep(i,0,n) cin>>a[i];

    cout<<OptimalGame(a,0,n-1)<<endl;
    return 0;
}

/*
6
20 30 2 2 2 10
*/