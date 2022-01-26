#include<bits/stdc++.h>
using namespace std;

int main(){
    int x,y;
    cin>>x>>y;
    while(1){
        if(x>y){
            if(x%y!=0)
            x = x%y;
            else
            break;
        }
        else{
            if(y%x!=0)
            y = y%x;
            else
            break;
        }
    }
    cout<<min(x,y)<<endl;
    return 0;
}