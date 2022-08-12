#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    vector<int> v;
    //push_back functions is used to insert values in the vector
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    //printing vector using simple calling 
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    //printing vector using iterator
    vector<int>::iterator it;
    for(it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    //printing vector using "auto" keyword
    for(auto element:v){
        cout<<element<<" ";
    }
    cout<<endl;

    //popback fuction removes the last element
    v.pop_back();
    for(auto element:v){
        cout<<element<<" ";
    }
    cout<<endl;    

    //to define vector with constant
    vector<int> v2(3,50);
    for(auto element:v2){
        cout<<element<<" ";
    }
    cout<<"swap"<<endl;

    //to swap the values of two given vectors
    swap(v,v2);
    for(auto element:v){
        cout<<element<<" ";
    }
    cout<<endl;
    for(auto element:v2){
        cout<<element<<" ";
    }
    cout<<endl;

    //to sort the vector
    sort(v.begin(),v.end());  

    //pair is used to store two values
    pair<int,char> p;
    p.first=1;
    p.second='e';

    cout<<"\nto insert value into vector\n";
    vector<int> new_vector(5,4);
    for(auto i:new_vector) cout<<i<<" ";
    cout<<endl;
    new_vector.insert(new_vector.begin()+2,7);
    for(auto i:new_vector) cout<<i<<" ";
    cout<<endl;

    cout<<"\nto erase value from vector\n";
    vector<int> v4(6);
    for(int i=0;i<6;i++){
        v4[i] = i+1;
    }
    for(auto i:v4) cout<<i<<" ";
    cout<<endl;
    v4.erase(v4.begin()+1);
    for(auto i:v4) cout<<i<<" ";
    cout<<endl;
    return 0;
}