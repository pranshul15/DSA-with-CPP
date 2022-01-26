//to find sum of n natural numers using functions
#include<iostream>
using namespace std;

int sum(int num){
    int x=0;
    for(int i=1;i<=num;i++){
        x+=i;
    }
    return x;
}

int main(){
    int n;
    cin>>n;
    cout<<sum(n)<<endl;
    return 0;
}