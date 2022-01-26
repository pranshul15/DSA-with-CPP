//program to check whether the given number is armstrong number
#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n,sum;
    cin>>n;
    sum=0;
    while(n>0){
        int rem=n%10;
        sum+=pow(rem,3);
        n/=10;
    }
    if(n==sum){cout<<"It is an Armstrong Number";}
    else{cout<<"It is not an Armstrong number";}
    return 0;
}