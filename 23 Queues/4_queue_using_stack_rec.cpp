#include<iostream>
#include<stack>
using namespace std;

class queue
{
private:

public:
    stack <int> st;
    queue() {
    }

    void push(int x){
        st.push(x);
    }

    void pop(){

        int topval = st.top();
        st.pop();

        if(st.empty()){
            return;
        }

        pop();
        st.push(topval);
        return;
    }

    int peek(){
        
        int value = st.top();
        st.pop();

        if(st.empty()){
            st.push(value);
            return value;
        }

        int ans = peek();
        st.push(value);
        return ans;
    }

    bool empty(){
        if(st.empty()){
            return true;
        }
        return false;
    }

};

int main(){
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    
    while(!q.empty()){
        cout<<q.peek()<<endl;
        q.pop();
    }

    if(q.empty()){
        cout<<"queue is empty now"<<endl;
    }
    
    return 0;
}