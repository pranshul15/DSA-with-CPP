//write a program to find factorial of given number
#include<iostream>
using namespace std;

int factorial(int num){
    int x=1;
    for(int i=1;i<=num;i++){
        x=x*i;
    }
    return x;
}

int main(){
    int n;
    cin>>n;
    cout<<factorial(n)<<endl;
    return 0;
}