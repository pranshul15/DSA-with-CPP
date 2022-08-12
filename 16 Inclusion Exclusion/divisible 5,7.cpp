#include<bits/stdc++.h>
using namespace std;

/*int DivisibleOne(int n1,int n2,int a){
    int count = 0;
    for(int i=n1; i<=n2; i++){
        if((i%a) == 0){
            count++;
        }
    }
    return count;
}

int DivisibleTwo(int n1,int n2,int a,int b){
    int count = 0;
    for(int i=n1; i<=n2; i++){
        if(((i%a) == 0) && ((i%b) == 0)){
            count ++;
        }
    }
    return count;
}

int main(){
    int n1,n2;
    cin>>n1>>n2;
    //total number of numbers divisible by 5 and 7 is equal to
    cout<<DivisibleOne(n1,n2,5) + DivisibleOne(n1,n2,7) - DivisibleTwo(n1,n2,5,7);
    return 0;
}*/

int Divisible(int n,int a,int b){
    int c1 = n/a;
    int c2 = n/b;

    int c3 = n/(a*b);
    return c1+c2-c3;
    
}

int main(){
    int n,a,b;
    cin>>n>>a>>b;
    cout<<Divisible(n,a,b);
    return 0;
}