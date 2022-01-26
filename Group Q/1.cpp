#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cout<<"lower value ";
    cin>>a;
    int b;
    cout<<"upper value ";
    cin>>b;
    float s=sqrt(a);
    float e=sqrt(b);
    int x=s;int y=e;
    if((s/x)==1){cout<<"The required output "<<y-x+1;}
    else{cout<<"The required output "<<y-x;}

    return 0;
}