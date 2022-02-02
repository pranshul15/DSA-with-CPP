//to do a task given by user

#include<iostream>
using namespace std;

int main(){
    char button;
    cout<<"Please enter the button"<<endl;
    cin>>button;

    if(button=='a'){
        cout<<"Hello"<<endl;
    }

    else if (button=='b'){
        cout<<"Namaste"<<endl;
    }

    else if (button=='c'){
        cout<<"good morning"<<endl;
    }

    else if (button=='d'){
        cout<<"bon jour"<<endl;
    }

    else{
        cout<<"you are learning well"<<endl;
    }

    
    return 0;
}