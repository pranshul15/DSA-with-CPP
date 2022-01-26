/*to convert given octal into decimal
octal has base as 8*/
#include<iostream>
using namespace std;

int OctalToDecimal(int n){
    int x=1;
    int ans=0;
    while(n>0){
        int y=n%10;
        ans=ans+x*y;
        x*=8;
        n/=10;
    }
    return ans;
}

int main(){
    int n;cin>>n;
    cout<<OctalToDecimal(n);
    return 0;
}