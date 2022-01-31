// You are given array of denominations and a value X
// Find minimum number of coins required to make X
#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define rep(i,a,b) for(int i=a;i<b;i++)

int main(){
    int n;
    cin>>n;
    vi denominations(n);

    rep(i,0,n)cin>>denominations[i];

    int X;
    cin>>X;

    // reverse sort
    sort(denominations.begin(),denominations.end(),greater<int>());

    int ans = 0;
    int i = 0;

    while(i<n){
        if(denominations[i] <= X){
            X -= denominations[i];
            ans++;
        }
        else{
            i++;
        }
        if(X == 0)break;
    }

    if(X==0){
        cout<<ans<<endl;
    }
    else{
        cout<<"not possible"<<endl;
    }
    return 0;
}