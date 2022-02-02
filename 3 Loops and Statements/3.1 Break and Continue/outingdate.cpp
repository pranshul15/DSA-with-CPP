#include<iostream>
using namespace std;

int main(){
    int pocketmoney=5000;
    for(int date=1;date<=30;date++){

        if(date%2==0){
            continue;
        }
        if(pocketmoney<=0){
            break;
        }
        cout<<date<<" "<<pocketmoney<<" Go outside"<<endl;
        pocketmoney=pocketmoney-700;
    }


    return 0;
}