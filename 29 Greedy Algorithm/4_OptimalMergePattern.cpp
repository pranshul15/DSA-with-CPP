// Given n files with computation time in array
// take two files and add their computation times till we got only one element in array
#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define rep(i,a,b) for(int i=a;i<b;i++)

int main(){
    int n;
    cin>>n;
    vi a(n);

    rep(i,0,n) cin>>a[i];

    priority_queue<int,vector<int>,greater<int>> pq;

    rep(i,0,n) pq.push(a[i]);

    int ans = 0;

    while(pq.size() != 1){
        int p1 = pq.top();
        pq.pop();
        int p2 = pq.top();
        pq.pop();
        pq.push(p1+p2);
        ans += (p1+p2);
    }

    cout<<ans<<endl;
    return 0;
}

// Test Case
// 4 5 7 2 4