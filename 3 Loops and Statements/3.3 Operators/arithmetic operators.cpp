#include<iostream>
using namespace std;
int main(){
    int a,b;
    a=5;b=10;

    cout<<a+b<<endl;
    cout<<a-b<<endl;
    cout<<a*b<<endl;
    cout<<b/a<<endl;
    cout<<b%a<<endl;
    a++;         //post incrementer
    cout<<a<<endl;
    b--;         //post decrementer
    cout<<b<<endl;
    ++a;         //pre incrementer
    cout<<a<<endl;
    --b;         //pre decrementer
    cout<<b<<endl;



    return 0;
}