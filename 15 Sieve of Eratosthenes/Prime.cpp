#include<iostream>
using namespace std;

void PrimeSieve(int n){
    bool array[n+1];
    for(int i=0; i<n+1; i++){
        array[i] = true;
    }

    for(int i=2; i<=n; i++){
        if(array[i]==true){
            for(int j=i*i; j<=n; j++){
                if((j%i)==0){
                    array[j] = false;
                }
            }
        }
    }

    for(int i=2; i<=n; i++){
        if(array[i]){
            cout<<i<<" ";
        }
    }


}

int main(){
    int n;cin>>n;
    PrimeSieve(n);
    return 0;
}