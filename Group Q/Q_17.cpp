#include<iostream>
using namespace std;

int main(){
    unsigned int n;
    cin>>n;
    
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

    const int m = 1000000007;
    long long int ans = 1;
    for(int i=2;i<=n;i++){
        if(array[i]==true){
            ans=(ans*i)%m;
        }
    }
    cout<<ans;
    return 0;
}