#include<iostream>
using namespace std;
int main(){
    int x,y;
    cin>>x>>y;

    if (x==y){
        cout<<"equal"<<endl;
    }
    else {
        if(x>y){
            cout<<x<<" is greater"<<endl;
        }
        else{
            cout<<y<<" is greater"<<endl;
        }
    }




    return 0;
}