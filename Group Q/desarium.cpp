#include<bits/stdc++.h>
using namespace std;

int desarium(int n){
    int counter = 0;
    int t = n;
    while(t>0){                 
        counter++;
        t/=10;
    }
    int sum =0;
    
    while (counter!=0){
        int x = pow((n%10),counter) + 0.1;
        sum = sum + x;
        n = (n/10);
        counter--;
    }
    
    return sum;
}

int main(){
    int m;
    //cout<<"enter value of m ";
    cin>>m;
    int n;
    //cout<<"enter value of n ";
    cin>>n;
    while (m!=n){
        int y = desarium(m);
        if(y == m){cout<<m<<" ";}
        m++;
    }   
    return 0;
}