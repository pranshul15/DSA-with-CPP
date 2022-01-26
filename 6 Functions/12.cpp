//write a program to find whether age is eligible for voting or not
#include<iostream>
using namespace std;

bool eligibleAge(int x){
    if(x<=18){return false;}
    return true;
}

int main(){
    cout<<"Enter your age"<<endl;
    int n;cin>>n;
    if(eligibleAge(n)){cout<<"Yes eligible for voting";}
    else{cout<<"Not eligible for voting";}
    return 0;
}