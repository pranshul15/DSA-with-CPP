//use of switch statement

#include<iostream>
using namespace std;

int main(){

    char button;
    cout<<"Enter your character"<<endl;
    cin>>button;

    switch(button)
    {
    case 'a':
        cout<<"Hello"<<endl;
        break;
    case 'b':
        cout<<"Namaste"<<endl;
        break;
    case 'c':
        cout<<"good morning"<<endl;
        break;
    case 'd':
        cout<<"bon jour"<<endl;
        break;
    
    default:
        cout<<"i am still learning more"<<endl;
        break;
    }

    return 0;
}