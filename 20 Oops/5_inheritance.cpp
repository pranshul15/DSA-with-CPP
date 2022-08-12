//inherit attributes from one class to another
//DERIVED CLASS = class that inherits = child
//BASE CLASS = class being inherited from = parent
#include<iostream>
using namespace std;

//single inheritence

class a{
    public:
    void func_a(){
        cout<<"Inherited"<<endl;
    }
};
class b : public a{
    };

//multiple inheritance

class one{
    public:
    void func_1(){
        cout<<"function one"<<endl;
    }
};
class two{
    public:
    void func_2(){
        cout<<"function two"<<endl;
    }
};
class three : public one, public two {
    public:
};

//Multi level Inheritance
class ml_1{
    public:
    void multiL1(){
        cout<<"multi level 1"<<endl;
    }
};
class ml_2 : public ml_1{
    public:
    void multiL2(){
        cout<<"multi level 2"<<endl;
    }
};
class ml_3 : public ml_2{
    public:
};

//Hybrid Inheritance

class hyb_1{
    public:
    void hybI1(){
        cout<<"hybrid inheritance 1"<<endl;
    }
};
class hyb_1_a : public hyb_1{
    public:
    void hybI1a(){
        cout<<"hybrid inheritance 1-a"<<endl;
    }
};
class hyb_1_b : public hyb_1_a{
    public:
    void hybI1b(){
        cout<<"hybrid inheritance 1-b"<<endl;
    }
};
class hyb_2{
    public:
    void hybI2(){
        cout<<"hybrid inheritance 2"<<endl;
    }
};
class hyb : public hyb_1_b,public hyb_2{
    public:
};

//Hirarchical Inheritance
class hir_1_a
{
private:
    /* data */
public:
    void hirf1a(){
        cout<<"hirarchical inheritance 1"<<endl;
    }
    hir_1_a(/* args */) {}
    ~hir_1_a() {}
};
class hir_2_a : public hir_1_a
{
private:
    /* data */
public:
    void hirf2a(){
        cout<<"hirarchical inheritance 2-a"<<endl;
    }
    hir_2_a(/* args */) {}
    ~hir_2_a() {}
};
class hir_2_b : public hir_1_a
{
private:
    /* data */
public:
    void hirf2b(){
        cout<<"hirarchical inheritance 2-b"<<endl;
    }
    hir_2_b(/* args */) {}
    ~hir_2_b() {}
};
class hir_3_a : public hir_2_a
{
private:
    /* data */
public:
    void hirf3a(){
        cout<<"hirarchical inheritance 3-a"<<endl;
    }
    hir_3_a(/* args */) {}
    ~hir_3_a() {}
};
class hir_3_b : public hir_2_a
{
private:
    /* data */
public:
    void hirf3b(){
        cout<<"hirarchical inheritance 3-b"<<endl;
    }
    hir_3_b(/* args */) {}
    ~hir_3_b() {}
};
class hir_3_c : public hir_2_b
{
private:
    /* data */
public:
    void hirf3c(){
        cout<<"hirarchical inheritance 3-c"<<endl;
    }
    hir_3_c(/* args */) {}
    ~hir_3_c() {}
};
class hir_3_d : public hir_2_b
{
private:
    /* data */
public:
    void hirf3d(){
        cout<<"hirarchical inheritance 3-d"<<endl;
    }
    hir_3_d(/* args */) {}
    ~hir_3_d() {}
};


int main(){
    cout<<"Single Inheritance"<<endl;
    b gasie;
    gasie.func_a();

    cout<<endl<<"Multiple inheritance"<<endl;
    three panew;
    panew.func_1();
    panew.func_2();

    cout<<endl<<"Multi Level Inheritance"<<endl;
    ml_3 rayutz;
    rayutz.multiL1();
    rayutz.multiL2();

    cout<<endl<<"Hybrid Inheritance"<<endl;
    hyb rusty;
    rusty.hybI1();
    rusty.hybI1a();
    rusty.hybI1b();
    rusty.hybI2();

    cout<<endl<<"Hirarchical Inheritance"<<endl;
    hir_3_a dree1;
    hir_3_b dree2;
    hir_3_c dree3;
    hir_3_d dree4;
    dree1.hirf1a();
    dree1.hirf2a();
    dree1.hirf3a();
    dree2.hirf1a();
    dree2.hirf2a();
    dree2.hirf3b();
    dree3.hirf2b();
    dree3.hirf2b();
    dree3.hirf3c();
    dree4.hirf1a();
    dree4.hirf2b();
    dree4.hirf3d();
    return 0;
}