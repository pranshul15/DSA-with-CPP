#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1 = "fam";
    string s2 = "ily";
    cout<<s1+s2<<endl;
    s1.append(s2);
    cout<<s1<<endl;
    
    s1.assign("nincompoop");
    cout<<s1<<endl;

    cout<<s1.at(4)<<endl;
    cout<<s1[4]<<endl;

    s1.clear();
    cout<<s1<<endl;

    string s3 = "ab";
    string s4 = "abc";
    cout<<"comaprision "<<s4.compare(s3)<<endl;

    string s = "nincompoop";
    s.erase(3,4);
    cout<<s<<endl;

    string s5 = "nincompoop";
    cout<<s5.find("poop")<<endl;

    s.insert(3,"com");
    cout<<s<<endl;

    cout<<s.length()<<endl;

    s5.resize(6);
    cout<<s5<<endl;
    cout<<s5.size()<<endl;

    string s6 = "784";
    int x = stoi(s6);
    cout<<x+2<<endl;

    cout<<to_string(x)+"2" <<endl;

    string s7 = "sanvodphnwzcnvi";
    sort(s7.begin(),s7.end());
    cout<<s7<<endl;
    
    return 0;
}