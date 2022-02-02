#include<iostream>
using namespace std;
int main(){
    int a,b;
    a=10;b=5;
    cout<<bool(a==b)<<endl;     //equal
    cout<<bool(a!=b)<<endl;     //not equal
    cout<<bool(a<b)<<endl;      //less than
    cout<<bool(a>b)<<endl;      //greater than
    cout<<bool(a<=b)<<endl;     //less than equal to
    cout<<bool(a>=b)<<endl;     //greater than equal to

    int n;
    cin>>n;
    if(n==10){cout<<"given number is 10"<<endl;}
    else if(n<10){cout<<"given number is less than 10"<<endl;}
    else{cout<<"given number is greater than 10"<<endl;}



    return 0;
}