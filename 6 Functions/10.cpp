//To write a program to print maximum and minimum of the three numbers given
#include <iostream>
using namespace std;

int maximum(int x,int y,int z){
    if(x>y){
        if(x>z){return x;}
        else{return z;}
        }
    else{
        if(y>z){return y;}
        else{return z;}
        }
}

int minimum(int x,int y,int z){
    if(x<y){
        if(x<z){return x;}
        else{return z;}
        }
    else{
        if(y<z){return y;}
        else{return z;}
        }
}

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    cout<<maximum(a,b,c)<<minimum(a,b,c)<<endl;

    int p,q,r;
    cin>>p>>q>>r;
    cout<<maximum(p,q,r)<<endl;
    cout<<minimum(p,q,r)<<endl;

    return 0;
}