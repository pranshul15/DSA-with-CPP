#include<iostream>
#include<stack>
#include<string>
using namespace std;

void reverse_string(string s){
    stack<string> st;
    int ptr1 = 0;
    while(ptr1 < s.length()){
        string word="";
        int ptr2 = ptr1;
        while(s[ptr2] != ' ' && ptr2 < s.length()){
            word = word + s[ptr2];
            ptr2++;
        }
        st.push(word);
        ptr1 = ptr2 + 1;
    }
    while (!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    return;
}

int main(){
    string s = "hey, how are you doing?";
    cout<<s<<endl;
    reverse_string(s);   
    return 0;
}