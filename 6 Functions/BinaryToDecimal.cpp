//to print a number from binary to decimal
#include<bits/stdc++.h>
using namespace std;

int BinaryToDecimal (int n){
    int x=1;
    int ans=0;
    while(n>0){
        int y=n%10;
        ans=ans+x*y;
        x*=2;
        n/=10;
        }
        return ans;
}

int main(){
    int n;cin>>n;
    cout<<BinaryToDecimal(n);
    return 0;
}
    