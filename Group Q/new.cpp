#include<iostream>
#include<cmath>

using namespace std;
int main()
{
        int a = 5;
        //float sum = 0;
        //for(int i=0;i<30;i++){
        //    sum = sum + a;
        //}
        //if(sum == (6.9)){cout<<"1"<<endl;}
        //else if(sum > (6.9)){cout<<"2"<<endl;}
        //else{cout<<"3"<<endl;}
        int x = pow(a,2);
        cout<<pow(5,2)<<endl;
        //int y = x;
        cout<<x<<endl;
        //cout<<y<<endl;
        if(x == 25){cout<<"1";}
        else if(x < 25){cout<<"2";}
        else{cout<<"3";}
        return 0;
}