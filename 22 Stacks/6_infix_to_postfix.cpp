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

string infix_to_postfix(string s){
    stack <char> st;
    string ans;

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
    return ans;
}

int main(){
    string s;
    cin>>s;
    cout<<infix_to_postfix(s)<<endl;
    return 0;
}

// (a-b/c)*((d/e-k)/(m-n))
// ((a-b/c)*(d/e-k))/(m-n)