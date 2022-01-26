#include<bits/stdc++.h>
using namespace std;

int main(){

    int arr[]={10,20,30};
    int*arraypointer;

    arraypointer=arr;
    cout<<*arraypointer<<endl;
    cout<<endl;
    for(int i=0;i<3;i++){
        cout<<*(arraypointer+i)<<endl;        //arraypointer+i is the address of arr[i]
    }
    return 0;
}