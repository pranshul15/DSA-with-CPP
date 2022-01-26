//to print a solid rectangle of stars when user gives number of rows and columns
#include<iostream>
using namespace std;
int main(){
    int i,j; //i=rows j=columns
    cin>>i>>j;

    for(int a=1;a<=i;a++){
        for(int b=1;b<=j;b++){
            cout<<" *";
        }
        cout<<endl;
    }

    return 0;
}