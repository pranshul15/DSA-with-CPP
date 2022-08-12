//to find whether alphabet is consonant or vowel
#include<iostream>
using namespace std;
int main(){

    char alphabet;
    cout<<"Please enter your alphabet"<<endl;
    cin>>alphabet;

    switch (alphabet)
    {
        case 'a':
        cout<<"it is vowel"<<endl;
        break;
        case 'e':
        cout<<"it is vowel"<<endl;
        break;
        case 'i':
        cout<<"it is vowel"<<endl;
        break;
        case 'o':
        cout<<"it is vowel"<<endl;
        break;
        case 'u':
        cout<<"it is vowel"<<endl;
        break;
        default:
        cout<<"it is consonant"<<endl;
    }



    return 0;
}