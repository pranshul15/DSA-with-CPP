//write a program to swap the values of two given integers
#include <iostream>
using namespace std;

void swap(int n1,int n2){
    int term;
    term=n2;
    n2=n1;
    n1=term;
    cout<<n1<<" "<<n2<<endl;
    return;
}

int main(){
    int a,b;
    a=5;b=7;
    cout<<a<<" "<<b<<endl;
    swap(a,b);
    return 0;
}