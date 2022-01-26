//Write a Program to sort a list of N students alphabetically using bubble sort.
#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    string a[n+1];
    for(int i=0; i<n+1; i++){
        getline(cin,a[i]);
    }

    int counter = 1;
    while (counter < n){
        for(int i=0;i<n-counter+1;i++){
            if( a[i].compare(a[i+1]) > 0 ){
                string var=a[i+1];
                a[i+1]=a[i];
                a[i]=var;
            }
        }
        counter++;
    }
    cout<<endl;
    cout<<"Ee le tera answer"<<endl;
    for(int i=0;i<n+1;i++){
        cout<<a[i]<<endl;
    }


    return 0;
}