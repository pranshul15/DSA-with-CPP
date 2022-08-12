//to write a program to find whether it is alphabet or not
#include<iostream>
using namespace std;

bool alphabet(char chr){
    if(chr>'A' && chr<'Z'){return true;}
    else if(chr>'a' && chr<'z'){return true;}
    return false;
}

int main(){
    char ch;
    cout<<"Enter your character"<<endl;
    cin>>ch;
    if(alphabet(ch)){cout<<"It is alphabet";}
    else{cout<<"It is not an alphabet";}
    return 0;
}