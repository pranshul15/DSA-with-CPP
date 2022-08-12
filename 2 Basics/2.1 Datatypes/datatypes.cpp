//Datatypes file

#include<iostream>
using namespace std;

int main()

{
    int a;
    a=235;

    cout<<"size of int is "<<sizeof(a)<<endl;

    float b;
    b=1.356;

    cout<<"size of float is "<<sizeof(b)<<endl;

    char c;
    cout<<"size of char is "<<sizeof(c)<<endl;

    bool d;
    cout<<"size of bool is "<<sizeof(d)<<endl;

    short int si;
    long int li;

    cout<<"size of short int is "<<sizeof(si)<<endl;
    cout<<"size of long int is "<<sizeof(li)<<endl;

    wchar_t w;
    cout<<"size of wide character is "<<sizeof(w)<<endl;

    long long int f;
    cout<<"size of long long int is "<<sizeof(f)<<endl; 

    signed int g;
    cout<<"size of signed int is "<<sizeof(g)<<endl;
    cout<<"signed int is same as int.\n";

    unsigned int h;
    cout<<"size of unsigned int is "<<sizeof(h)<<endl;
    cout<<"unsigned int has positive integers \n";

    unsigned long int i;
    cout<<"size of unsigned long int is "<<sizeof(i)<<endl;
    cout<<"unsigned long integer can store large positive integers \n";

    long double j;
    cout<<"size of long double is "<<sizeof(j)<<endl;
    cout<<"long double can store large floating point numbers \n";



    return 0;
}