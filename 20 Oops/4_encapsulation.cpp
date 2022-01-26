//hiding sensitive data from the user
//DATA MEMBERS = all the variables within a class
//MEMBER FUNCTIONS = all the functions within a class
//good coding practice useful in interviews
//security of data

#include <iostream>
using namespace std;

class gss
{
private:
    //variables can be used only in the class
    int a;
    void func_a(){
        cout<<"a"<<endl;
    }
public:
    //variables can be used anywhere
    int b;
    void func_b(){
        cout<<"b"<<endl;
    }
protected:
    //variables can be used in class and inherited class
    int c;
    void func_c(){
        cout<<"c"<<endl;
    }
};



int main(){
    gss i;
    i.b = 5;
    i.func_b();
    return 0;
}