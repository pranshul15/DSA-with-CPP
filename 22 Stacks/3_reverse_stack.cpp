#include<iostream>
#include<stack>
using namespace std;

void insert_at_bottom(stack<int> &st,int element){
    if(st.empty()){
        st.push(element);
        return;
    }
    int element1 = st.top();
    st.pop();
    insert_at_bottom(st,element);
    st.push(element1);
}

void reverse(stack<int> &st){
    
    if(st.empty()){
        return;
    }

    int element = st.top();
    st.pop();
    reverse(st);
    insert_at_bottom(st,element);
}

void display(stack<int> st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    return;
}

int main(){
    stack <int> st;
    for(int i=1;i<=5;i++){
        st.push(i);
    }
    display(st);
    reverse(st);
    display(st);
    return 0;
}