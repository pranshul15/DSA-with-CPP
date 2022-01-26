//To terminate when user input is negative

#include<iostream>
using namespace std;

int main(){

    int n;
    cin>>n;

    while(n>0){ //condition

        cout<<n<<endl; //body
        cin>>n;
    }


    return 0;
}