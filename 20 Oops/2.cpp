#include <iostream>
using namespace std;

//class is a user defined data type

class student{
    string name;
    public:

    //data memebers
    
    int age;
    bool gender;

    void setName(string s){
        name=s;
    }

    void getName(){
        cout<<name<<endl;
    }

    void printinfo(){
        cout<<"Name = "<<name<<endl;
        cout<<"Age = "<<age<<endl;
        cout<<"Gender = "<<gender<<endl;    
    }
};

int main(){
    student a;
    //object
    string s = "Pranshul";
    a.setName(s);

    a.age = 20;
    a.gender = 1;
    a.printinfo();

    cout<<endl;
    
    student arr[3];
    for(int i=0;i<3;i++){
        string s;
        cout<<"Name = ";
        cin>>s;
        a.setName(s);
        cout<<"Age = ";
        cin>>arr[i].age;
        cout<<"Gender = ";
        cin>>arr[i].gender;
    }

    for(int i=0;i<3;i++){
        arr[i].printinfo();
    }
    return 0;
}