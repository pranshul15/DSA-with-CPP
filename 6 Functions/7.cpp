//program to write pascal's triangle
//1
//1 1
//1 2 1
//1 3 3 1
#include<iostream>
using namespace std;

int factorial(int num){
    int x=1;
    for(int i=1;i<=num;i++){
        x=x*i;
    }
    return x;
}

int elementPascal(int n1,int n2){
    int y;
    y=factorial(n1)/(factorial(n2)*factorial(n1-n2));
    return y;
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<elementPascal(i,j)<<" ";
        }
        cout<<endl;
    }
return 0;
}