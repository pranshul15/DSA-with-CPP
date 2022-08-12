//write a program to find whether a number is odd or even
#include<iostream>
using namespace std;

bool OddEven(int num){
    if(num%2==0){return false;}     //false implies even
    return true;                    //true implies odd
}

int main(){
    int n;
    cin>>n;
    if(OddEven(n)){cout<<"This is odd number";}
    else{cout<<"This is even number";}
    return 0;
}