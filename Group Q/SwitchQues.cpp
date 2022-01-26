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
    cout<<"Amithab Bacchhan: Aapke options hai ye aapki computer screen par"<<endl;
    cout<<"option a - desarium"<<endl;
    cout<<"option b - digit divisible"<<endl;
    cout<<"option c - daba ke dekhiye"<<endl;
    cout<<"option d - vo bhi daba ke dekhiye"<<endl;

    char button;
    cout<<"Enter you Character"<<endl;
    cin>>button;

    switch(button){

        case 'a':
            {int m,n;
            cout<<"Enter the limits"<<endl;
            cin>>m>>n;
            while (m!=n){
            int y = desarium(m);
            if(y == m){cout<<m<<" ";}
            m++;
            }}
            break;

        case 'b':
            {int p;
            cout<<"Enter the number"<<endl;
            cin>>p;
            int x = p;
            int count = 0;
            while(x!=0){
                int r=(x%10);
                if(r!=0){
                    if((p%r)==0){count++;}
                }
                x/=10;
            }
            cout<<count;}
            break;
            
        case 'c':
            cout<<"Namashkaar aadab swagat hai aap sabka is adbhut khel me"<<endl;
            break;

        case 'd':
            cout<<"Samay aa gaya hai aapse vida lene ka"<<endl;
            break;

    }
    return 0;
}