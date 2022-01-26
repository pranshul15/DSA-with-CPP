#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the value of N ";
    cin>>n;
    for(int i=1;i<=(n/2);i++){  
        for(int j=1;j<i;j++){cout<<"# ";}
        cout<<"* ";
        for(int j=1;j<=(n-(2*i));j++){cout<<"$ ";}
        cout<<"* ";
        for(int j=1;j<i;j++){cout<<"# ";}
        cout<<endl;
    }
    for(int i=(n/2)+1;i>=1;i--){
        if(i==(n/2)+1 and n%2==0){continue;}
        for(int j=1;j<i;j++){cout<<"# ";}
        cout<<"* ";
        for(int j=1;j<=(n-(2*i));j++){cout<<"$ ";}
        if(i!=((n/2)+1) or n%2==0){cout<<"* ";}
        for(int j=1;j<i;j++){cout<<"# ";}
        cout<<endl;
    }
    return 0;
}