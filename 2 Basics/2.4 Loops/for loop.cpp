//To find the sum of n natural numbers

#include<iostream>
using namespace std;

int main(){

    int n;
    cin>>n;

    int sum=0;

    for(int counter=1;counter<=n;counter++){
        //(initialization;condition;updation)

        sum=sum+counter;//body
    }

    cout<<sum<<endl;


    return 0;
}