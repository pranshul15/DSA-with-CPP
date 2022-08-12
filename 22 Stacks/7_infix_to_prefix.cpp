#include<iostream>
#include<stack>
using namespace std;

int prec(char c){
    if(c == '^'){
        return 3;
    }
    else if (c == '/' || c == '*')
    {
        return 2;
    }
    else if(c == '+' || c == '-'){
        return 1;
    }
    else{
        return -1;
    }
    
}

string reverse_string(string s){
    stack <char> st;
    for(int i=0;i<s.length();i++){
        st.push(s[i]);
    }
    string ans = "";
    while(!st.empty()){
        ans = ans + st.top();
        st.pop();
    }
    return ans;
}

string brackets_change(string s){
    for(int i=0;i<s.length();i++){
        if(s[i] == '('){
            s[i] = ')';
        }
        else if(s[i] == ')'){
            s[i] = '(';
        }
    }
    return s;
}

string infix_to_prefix(string s){
    string ans;
    stack <char> st;
    s = reverse_string(s);
    cout<<s<<endl;
    s = brackets_change(s);
    cout<<s<<endl;

    for(int i=0 ; i<s.length() ; i++){
        if (s[i] == '(')
        {
            st.push(s[i]);
        }

        else if (s[i] == ')')
        {
            while(st.top() != '('){
                ans = ans + st.top();
                st.pop();
            }
            st.pop();
        }
        else if (s[i] == '+' || s[i] == '-')
        {
            if(!st.empty())
            {
                if (prec(st.top()) <= prec(s[i]))
                {
                    st.push(s[i]);
                }
                else
                {
                    ans = ans + st.top();
                    st.pop();
                    st.push(s[i]);
                }
            }
            else
            {
                st.push(s[i]);
            }
        }
        
        else if (s[i] == '/' || s[i] == '*')
        {
            st.push(s[i]);
        }
        
        else
        {
            ans = ans + s[i];
        }    
    }
    while(!st.empty()){
        ans = ans + st.top();
        st.pop();
    }
    return reverse_string(ans);

}

int main(){
    string s;
    cin>>s;
    cout<<infix_to_prefix(s)<<endl;
    return 0;
}