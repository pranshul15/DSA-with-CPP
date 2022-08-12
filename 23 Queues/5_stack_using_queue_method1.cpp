#include <iostream>
#include <queue>
using namespace std;

// when push function is costly

class stack
{
private:
    int N;
    queue<int> q1;
    queue<int> q2;
public:
    stack() {}
    
    void push(int x){
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> temp = q2;
        q2 = q1;
        q1 = temp;
        N++;
        return;
    }

    void pop(){
        if(q1.empty()){
            return;
        }
        q1.pop();
        N--;
        return;
    }

    int top(){
        return q1.front(); 
    }

    bool empty(){
        if(q1.empty()){
            return true;
        }
        return false;
    }
};

int main(){
    stack st;
    st.push(1);        
    st.push(2);        
    st.push(3);        
    st.push(4);

    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;        
    return 0;
}
