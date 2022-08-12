//how to find number of ones in binary number
#include<bits/stdc++.h>
using namespace std;

int NumberofOnes(int n){
    int i = 0;
    while(n){
        n = (n & (n-1));
        i++;
    }
    return i;
}

int main(){
    int n;
    cin>>n;
    cout << NumberofOnes(n) << endl;

    return 0;
}