//to print a simple array
#include<bits/stdc++.h>
using namespace std;

int main(){
    int array[4];
    array[0]=10;
    array[1]=20;
    array[2]=30;
    array[3]=40;

    int array1[3]={23,33,43};

    for(int i=0;i<4;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<3;i++){
        cout<<array1[i]<<" ";
    }
    return 0;
}