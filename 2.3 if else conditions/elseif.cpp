#include<iostream>
using namespace std;
int main(){
    int x,y;
    cin>>x>>y;

    if(x==y){
        cout<<"both numbers are equal"<<endl;
    }

    else if(x>y){
        cout<<x<<" is greater number"<<endl;
    }

    else{
        cout<<y<<" is greater number"<<endl;
    }




    return 0;
}