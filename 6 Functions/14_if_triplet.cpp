//program to check pythagorian triplet
#include<bits/stdc++.h>
#include<cmath>
using namespace std;

bool triplet(int x,int y,int z){
    if(x>max(y,z)){
        if(pow(x,2)==pow(y,2)+pow(z,2)){return true;}
        else{return false;}
        }
    else if(y>max(x,z)){
        if(pow(y,2)==pow(x,2)+pow(z,2)){return true;}
        else{return false;}
        }
    else{
        if(pow(z,2)==pow(x,2)+pow(y,2)){return true;}
        else{return false;}
        }
}

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    if(triplet(a,b,c)){cout<<"given numbers are in triplet"<<endl;}
    else{cout<<"given numbers are not in a triplet"<<endl;}

    return 0;
}