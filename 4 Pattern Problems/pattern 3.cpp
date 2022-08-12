//to print a hollow rectangle of stars with gives numbers of rows and columns
#include<iostream>
using namespace std;
int main(){
    int a,b; 
    //a=rows b=columns
    cin>>a>>b;

    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(i==1 || i==a){
                cout<<" *";
            }
            else if((j==1 || j==b) && (1<i<a)){
                cout<<" *";
            }
            else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }


    return 0;
}
