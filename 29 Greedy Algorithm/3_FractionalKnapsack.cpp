// Given n items with {weight,value} of each item
// capacity of knapsack is W 
// Keep items such that final value is maximum
#include<bits/stdc++.h>
using namespace std;

typedef vector<pair<int,int>> vpi;
#define ff first
#define ss second
#define rep(i,a,b) for(int i=a;i<b;i++)

int main(){
    int n,w;
    cin>>n>>w;
    vpi a(n);

    rep(i,0,n)cin>>a[i].ff>>a[i].ss;

    sort(a.begin(),a.end(),[&](pair<int,int> &p,pair<int,int> &q){
        return (double)(p.ff/p.ss) >= (double)(q.ff/q.ss);
    });
    rep(i,0,n){
        cout<<a[i].ff<<" "<<a[i].ss<<endl;
    }

    double ans = 0,i = 0;

    while(w && i<n){
        if(a[i].ss <= w){
            ans += a[i].ff;
            w -= a[i].ss;
        }
        else{
            double t = a[i].ff/a[i].ss;
            ans += (t*w);
            w = 0;
        }
        i++;
    }

    cout<<ans<<endl;

    return 0;
}

// Test case
// 3 50 60 10 100 20 120 30