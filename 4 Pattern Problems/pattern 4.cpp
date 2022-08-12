//to print half pyramid using stars for given number of rows
#include<iostream>
using namespace std;
int main(){
    int n;
    cout <<"Enter no. of rows"<<endl;
    cin>>n;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<" *";
        }
        cout<<endl;
    }
    
    return 0;
}