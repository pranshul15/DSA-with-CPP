// Given an array 
// Remove n/2 elements from array and put it in another
// Find maximum and minimum values of differences b/w these two arrays
#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define rep(i,a,b) for(int i=a;i<b;i++)

int MaximumDifference(int n,vi a){
    int s = 0,e = n-1;

    int ans = 0;

    while((e-s)>1){
        ans+= abs(a[s]-a[e]);
        e++;
        s--;
    }

    return ans;
}

int MinimumDifference(int n,vi a){
    int p=0,q=1;

    int ans = 0;

    while(q<n){
        ans += abs(a[q]-a[p]);
        p+=2;
        q+=2;
    }

    return ans;
}

int main(){
    int n; // even
    cin>>n;
    vi a(n);
    rep(i,0,n)cin>>a[i];

    cout<<MaximumDifference(n,a)<<endl;
    cout<<MinimumDifference(n,a)<<endl;
    return 0;
}