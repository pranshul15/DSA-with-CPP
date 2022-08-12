#include<bits/stdc++.h>
using namespace std;

int catalan(int n){
    if(n==0){
        return 1;
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        ans += catalan(i) * catalan(n-i-1);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cout<<catalan(i)<<" ";
    }
    return 0;
}