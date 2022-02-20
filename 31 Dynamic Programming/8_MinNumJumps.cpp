/*
Given an array of integers where each element represents
the max number of steps that can be made forward from that 
element
WAP to return the minimum number of jumps to reach the 
end of the array(starting from the first element).
If an element is 0, they cannot move through that element

can be done with greedy approach also
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

// Memoization
int dp1[N];

int MinJumps(vi &a, int i){
    if(i>=a.size())
        return 0;
    
    if(dp1[i] < INF-1000)
        return dp1[i];

    rep(j,i+1,i+a[i]+1){
        dp1[i] = min(dp1[i],1+MinJumps(a,j));
    }

    return dp1[i];
}

int main(){
    rep(i,0,N)
        dp1[i] = INF;

    int n;cin>>n;
    vi a(n);
    rep(i,0,n) cin>>a[i];

    cout<<MinJumps(a,0)<<endl;

    // Tabulation
    vi dp2(n,INF);

    dp2[0] = 0;
    rep(i,0,n){
        rep(j,i+1,i+1+a[i]){
            if(j==n) break;
            dp2[j] = min(dp2[j],1+dp2[i]);
        }
    }

    cout<<dp2[n-1];
    return 0;
}

/*
11
1 3 5 8 9 2 6 7 6 8 9
*/ 