//print a rectangle when user gives number of rows using stars
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cout<<" *";
            }
        cout<<endl;
    }


    return 0;
}