#include<iostream>
using namespace std;

int main(){
    string Sentence,temp="",ans="";
    cout << "Type your full Sentence: ";
    getline (cin, Sentence);
    Sentence +=" ";
    for(unsigned int i=0;i<Sentence.length();i++){
        char ch = Sentence.at(i);
        if(ch!=32){
            temp+=ch;
        }
        else{
            swap(temp[0],temp[temp.length()-1]);
            ans +=temp+" ";
            temp="";
        }
    }
    cout<<ans<<endl;
    return 0;
}