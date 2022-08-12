//Program to calculate factorial of a given number
#include<iostream>
using namespace std;
int main(){
    unsigned long long int n,x=1;
    cin>>n;
    for(int i=1;i<=n;i++){
        x*=i;
    }
    cout<<x<<endl;
    return 0;
}