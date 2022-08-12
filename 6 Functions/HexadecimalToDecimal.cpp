//to convert a hexadecimal to its decimal form
#include<bits/stdc++.h>
using namespace std;

int HexadecimalToDecimal(string n){
    int x=1;
    int ans=0;
    int s=n.size();
    for(int i=s-1;i>=0;i--){
        if(n[i]>='0' && n[i]<='9'){ans=ans+x*(n[i]-'0');}
        else if(n[i]>='A' && n[i]<='F'){ans=ans+(n[i]-'A'+10);}
        x*=16;
    }
    return ans;
}

int main(){
    string n;cin>>n;
    cout<<HexadecimalToDecimal(n);
    return 0;
}
