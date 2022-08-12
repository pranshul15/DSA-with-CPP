//to print inverted pyramid using numbers
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int i;

    for(i=1;i<=n;i++){
        for(int j=1;j<=n+1-i;j++){
        cout<<i<<" ";
        }
        cout<<endl;
    }

    return 0;
}