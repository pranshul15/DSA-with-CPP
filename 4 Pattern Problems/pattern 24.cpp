//to print hollow butterfly pattern
#include<iostream>
using namespace std;
int main(){
    int n,i,j;
    cin>>n;
    for(i=1;i<=n;i++){
        cout<<" *";                             //first star
        for(j=3;j<=i;j++){cout<<"  ";}
        if(i<=n && i>=2){cout<<" *";}         //second star
        for(j=1;j<=2*(n-i);j++){cout<<"  ";}
        cout<<" *";                             //third star
        for(j=3;j<=i;j++){cout<<"  ";}
        if(i<=n && i>=2){cout<<" *";}         //fourth star
        cout<<endl;
    }

    for(i=n;i>=1;i--){
        cout<<" *";
        for(j=3;j<=i;j++){cout<<"  ";}
        if(i<=n && i>=2){cout<<" *";}
        for(j=1;j<=2*(n-i);j++){cout<<"  ";}
        cout<<" *";
        for(j=3;j<=i;j++){cout<<"  ";}
        if(i<=n && i>=2){cout<<" *";}
        cout<<endl;
    }
    return 0;
}