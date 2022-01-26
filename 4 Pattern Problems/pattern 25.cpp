//to print pascal's triangle
#include <iostream>
using namespace std;
int main(){
    int n,i,j;
    cin>>n;
    int coef=1;
    for(i=0;i<n;i++){
        for(int space=1;space<=n-i;space++){cout<<"  ";}
        for(j=0;j<i;j++){
            if(i==0 || j==0){coef =1;}
            else{coef = (i-j+1)/j;}
            cout<<coef<<"   ";
        }
        cout<<endl;
    }

    
    return 0;
}