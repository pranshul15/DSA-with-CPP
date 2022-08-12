//write a program to print all prime numbers between two numbers
#include<iostream>
#include<math.h>
using namespace std;

bool Prime(int num){
    for(int i=2;i<sqrt(num);i++){
        if(num%i==0){return false;}
    }
    return true;
}

int main(){
    int a,b;
    cin>>a>>b;
    for(int i=a;i<=b;i++){
        if(Prime(i)==true){
            cout<<i<<endl;
        }
    }
    
    return 0;
}