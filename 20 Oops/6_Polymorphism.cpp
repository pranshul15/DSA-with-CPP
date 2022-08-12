//Polymorphism => many forms
//two types - compile time and runtime
#include<iostream>
using namespace std;

//function overloading
class funo
{
private:
    /* data */
public:
    void dull(){
        cout<<"this is a fuction with no arguments"<<endl;
    }
    void dull(int x){
        cout<<"this is a fuction with int argument"<<endl;
    }
    void dull(double x){
        cout<<"this is a fuction with double argument"<<endl;
    }
    funo(/* args */) {}
    ~funo() {}
};

//operator overloading

class opor
{
private:
    /* data */
    int real,imag;
public:
    opor(){}
    opor(int r,int i/* args */) {
        real = r;
        imag = i;
    }
    opor operator+ (opor const &obj){
        opor res;
        res.imag = imag + obj.imag;
        res.real = real + obj.real;
        return res;
    }

    void display(){
        cout<<real<<" + i "<<imag<<endl;
    }
    ~opor() {}
};

//runtime polymorphism
class base
{
private:
    /* data */
public:
    virtual void print(){
        cout<<"this is base class's print function"<<endl;
    }
    void display(){
        cout<<"this is base class's display function"<<endl;
    }
    base(/* args */) {}
    ~base() {}
};
class derived : public base
{
private:
    /* data */
public:
    void print(){
        cout<<"this is derived class's print function"<<endl;
    }
    void display(){
        cout<<"this is derived class's display function"<<endl;
    }
    derived(/* args */) {}
    ~derived() {}
};

int main(){
    funo sear;
    sear.dull();
    sear.dull(4);
    sear.dull(4.53);
    cout<<endl;
    opor guld(12,19),based(13,3);
    opor drod = guld + based;
    drod.display();
    cout<<endl;
    base *baseptr;
    derived d;
    baseptr = &d;
    baseptr -> print();
    baseptr -> display();
    return 0;
}