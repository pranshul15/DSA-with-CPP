#include<bits/stdc++.h>
using namespace std;

int main(){
    int x,y;
    cin>>x>>y;
    while(x!=y){
        if(x>y){
            x-=y;
        }
        else{
            y-=x;
        }
    }
    cout<<x<<endl;
    return 0;
}