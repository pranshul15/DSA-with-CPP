#include<iostream>
#include<stack>
using namespace std;

bool balanced_parantheses(string s){
    bool ans = true;
    stack <char> st;

    for(int i=0 ; i<s.length() ; i++){
        if(s[i] == '(' or s[i] == '[' or s[i] == '{'){
            st.push(s[i]);
        }
        else if(!st.empty() and s[i] == ')'){
            if(st.top() != '('){
                ans = false;
                break;
            }
            else{
                st.pop();
            }
        }
        else if(!st.empty() and s[i] == ']'){
            if(st.top() != '['){
                ans = false;
                break;
            }
            else{
                st.pop();
            }
        }
        else if(!st.empty() and s[i] == '}'){
            if(st.top() != '{'){
                ans = false;
                break;
            }
            else{
                st.pop();
            }
        }
    }

    if(!st.empty()){return false;}
    return ans;
}

int main(){
    string s;
    cin>>s;
    if(balanced_parantheses(s)){
        cout<<"balanced parantheses"<<endl;
    }
    else{
        cout<<"unbalanced parantheses"<<endl;
    }
    return 0;
}