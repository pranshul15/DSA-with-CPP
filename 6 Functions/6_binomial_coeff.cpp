//program to find binary coefficient
#include<iostream>
using namespace std;

int factorial(int n){
    int x=1;
    for(int i=1;i<=n;i++){
        x=x*i;
    }
    return x;
}

int main(){
    int n,r;
    cin>>n>>r;
    cout<<"value of binomial coefficient nCr"<<endl;
    cout<<factorial(n)/(factorial(r)*factorial(n-r))<<endl;

    return 0;
}