#include<iostream>
#include<stack>
using namespace std;

int main(){
    string s;
    cin>>s;
    stack <char> st;
    bool ans = false;
    for(int i=0;i<s.length();i++){
        if(s[i] == '+' or s[i] == '-' or s[i] == '*' or s[i] == '/'){
            st.push(s[i]);
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        
        else if(s[i] == ')'){
            if(st.top() == '+' or st.top() == '-' or st.top() == '*' or st.top() == '/'){
                st.pop();
                st.pop();
            }
            else{
                ans = true;
            }
        }
    }
    if(ans){cout<<"redundant paranthesis"<<endl;}
    else{cout<<"non redundant paranthesis"<<endl;}
    return 0;
}