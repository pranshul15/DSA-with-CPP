//Write a program to print Fibonacci series upto n
#include<iostream>
using namespace std;
int main(){
    int n;cin>>n;
    int x=0;
    for(int i=0;i<=n;i++){
        x+=i;
        cout<<x<<" ";
    }
    return 0;
}