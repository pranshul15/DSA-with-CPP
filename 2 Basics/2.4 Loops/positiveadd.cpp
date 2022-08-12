#include<iostream>
using namespace std;

int main(){

    int n;
    cout<<"Enter your number"<<endl;
    cin>>n;
    int sum=0;

    while(n>=0){

        sum=sum+n;
        cout<<"enter your number"<<endl;
        cin>>n;

    }

    cout<<"\nsum of numbers is"<<sum;


    return 0;
}