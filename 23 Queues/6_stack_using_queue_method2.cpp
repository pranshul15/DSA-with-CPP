#include <iostream>
#include <queue>
using namespace std;

// when pop function is costly

class stack
{
private:
    int N;
    queue<int> q1;
    queue<int> q2;
public:
    stack() {
        N=0;
    }
    
    void push(int x){
        q1.push(x);
        N++;
        return;
    }

    void pop(){
        if(q1.empty()){
            return;
        }
        
        while(q1.size() != 1){
            q2.push(q1.front());
            q1.pop();
        }

        q1.pop();

        queue<int> temp = q2;
        q2 = q1;
        q1 = temp;
        N--;
        return;
    }

    int top(){
        if(q1.empty()){
            return -1;
        }

        while(q1.size() != 1){
            q2.push(q1.front());
            q1.pop();
        }
        int ans = q1.front();
        q2.push(q1.front());
        q1.pop();

        queue<int> temp = q2;
        q2 = q1;
        q1 = temp;
        return ans;
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