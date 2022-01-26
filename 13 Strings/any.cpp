#include<bits/stdc++.h>
using namespace std;

int main(){

    string name;
    cout<<"Enter your name"<<endl;
    getline(cin,name);

    int age;
    cout<<"Enter your age"<<endl;
    cin>>age;

    float height;
    cout<<"Enter your height in centimeters"<<endl;
    cin>>height;

    cout<<"My height in inches"<< (height / 2.54) << endl;

    return 0;
}