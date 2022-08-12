// You are given an array with n elements
// Calculate the minimum sum of k consecutive elements
// Sliding window is optimal solution

#include<iostream>
#include<vector>
#include<map>
using namespace std;

typedef vector<int> vi;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second

int main(){
    int n,k;
    cin>>n;
    cin>>k;

    vi v(n);

    rep(i,0,n)cin>>v[i];

    int i=0,j=k-1,sum=v[0];

    rep(a,1,k)
        sum += v[a];

    int ans = sum;

    while(j<n-1){
        sum = (sum - v[i]) + v[j+1];
        ans = min(ans,sum);
        ++i;
        ++j;
    }

    cout<<sum<<endl;

    return 0;
}