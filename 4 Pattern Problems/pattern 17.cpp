//to print hollow diamond using stars
#include<iostream>
using namespace std;
int main(){
    int n,i,j;
    cin>>n;
    for(i=1;i<=n;i++){
        for(j=1;j<=n-i;j++){
            cout<<"  ";
        }
        cout<<" *";
        for(j=1;j<=2*i-3;j++){
            cout<<"  ";
        }
        if(i!=1){
        cout<<" *";
        }
        cout<<endl;
    }
    for(i=n;i>=1;i--){
        for(j=1;j<=n-i;j++){
            cout<<"  ";
        }
        cout<<" *";
        for(j=1;j<=2*i-3;j++){
            cout<<"  ";
        }
        if(i!=1){
        cout<<" *";
        }
        cout<<endl;
    }
    return 0;
}