#include <iostream>
using namespace std;

//class is a user defined data type

class student{
    string name;
    public:

    //data memebers
    
    int age;
    bool gender;

    //default constructor
    student(){
        cout<<"default constructor"<<endl;
    }

        //patameterized constructor
    student(string s,int a,bool g){
        cout<<"parameterized constructor"<<endl;
        name =s;
        age =a;
        gender =g;
    }

    student(student &a){
        cout<<"copy constructor"<<endl;
        name = a.name;
        age = a.age;
        gender = a.gender;
    }

    ~student(){
        cout<<"destructor called"<<endl;
    }

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

    //operator overload
    bool operator ==(student &a){
        if(name == a.name and age == a.age and gender == a.gender){
            return true;
        }
        return false;
    }
};

int main(){
    student a("pranshul",20,true);
    //a.printinfo();
    student b;
    student c = a;

    if(c==a){
        cout<<"same"<<endl;
    }
    else{
        cout<<"not same"<<endl;
    }
    return 0;
}