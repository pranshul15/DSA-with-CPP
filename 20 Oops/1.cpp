#include <iostream>
using namespace std;

//class is a user defined data type

class student{
    
    public:

    //data memebers
    //name age gender are attributes
    string name; 
    int age;
    bool gender;

    void printinfo(){
        cout<<"Name = "<<name<<endl;
        cout<<"Age = "<<age<<endl;
        cout<<"Gender = "<<gender<<endl;    
    }
};

int main(){
    student a;
    //object
    a.name = "Pranshul";
    a.age = 20;
    a.gender = 1;
    a.printinfo();

    cout<<endl;

    student arr[3];
    for(int i=0;i<3;i++){
        cout<<"Name = ";
        cin>>arr[i].name;
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