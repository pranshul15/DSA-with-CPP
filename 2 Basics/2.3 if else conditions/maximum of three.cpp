#include<iostream>
using namespace std;

int main(){
    cout<<"enter your first number"<<endl;
    int a;
    cin>>a;
    cout<<"enter yout second number"<<endl;
    int b;
    cin>>b;
    cout<<"enter your third number"<<endl;
    int c;
    cin>>c;

    if(a>b){
        if(a>c){
            cout<<a<<" is the largest number.\n";
        }
        else{
            cout<<c<<" is the largest number.\n";
        }
    }
    else{
        if(b>c){
            cout<<b<<" is the largest number.\n";
        }
        else{
            cout<<c<<" is the largest number.\n";
        }
    }




    return 0;
}