#include<bits/stdc++.h>
using namespace std;

bool PowerofTwo(int n){
    if((n & (n-1)) == 0){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    if(PowerofTwo(8)){
        cout << "Number is power of 2";
    }
    else{
        cout << "number is not a power of 2";
    }

    return 0;
}