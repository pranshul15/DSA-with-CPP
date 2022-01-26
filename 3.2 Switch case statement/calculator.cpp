//calculator

#include<iostream>
using namespace std;

int main(){

    int n1,n2;
    cout<<"enter your numbers"<<endl;
    cin>>n1>>n2;

    char op;
    cout<<"input your operator"<<endl;
    cin>>op;

    switch (op)
    {
        case '+':
        cout<<n1+n2<<endl;
        break;

        case '-':
        cout<<n1-n2<<endl;
        break;

        case '*':
        cout<<n1*n2<<endl;
        break;

        case '/':
        cout<<n1/n2<<endl;
        break;

        default:
        cout<<"Enter another operator"<<endl;
        
    }




    return 0;
}
