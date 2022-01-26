//to print a a hollow diamond inside rectangle with stars
#include<iostream>
using namespace std;
int main(){
    int n,i,j;
    cin>>n;
    for(i=1;i<=n;i++){
        for(j=1;j<=n+1-i;j++){
            cout<<" *";
        }
        for(j=1;j<=2*i-3;j++){
            cout<<"  ";
        }
        if(i==1){
            for(j=1;j<=n-1;j++){
                cout<<" *";
            }
        }
        else{
            for(j=n;j>=i;j--){
                cout<<" *";
            }
        } 
        cout<<endl; 
        }

    for(i=n;i>=1;i--){
        for(j=1;j<=n+1-i;j++){
            cout<<" *";
        }
        for(j=1;j<=2*i-3;j++){
            cout<<"  ";
        }
        if(i==1){
            for(j=1;j<=n-1;j++){
                cout<<" *";
            }
        }
        else{
            for(j=n;j>=i;j--){
                cout<<" *";
            }
        } 
        cout<<endl; 
        }
    return 0;
}
