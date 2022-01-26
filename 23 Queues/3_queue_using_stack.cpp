#include<iostream>
#include<stack>
using namespace std;

class queue
{
private:

public:
    stack <int> s1;
    stack <int> s2;
    queue() {
    }

    void enqueue(int x){
        s1.push(x);
    }

    void dequeue(){
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    int peek(){
        if(s1.empty()){
            cout<<"queue is empty"<<endl;
            return -1;
        }

        if(!s1.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int topval = s2.top();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return topval;
        
    }

    bool empty(){
        if(s1.empty()){
            return true;
        }
        return false;
    }

    // ~queue() {}
};

int main(){
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    for(int i=1;i<=5;i++){
        cout<<q.peek()<<" ";
        q.dequeue();
        if(q.empty()){
            cout<<"queue is empty now"<<endl;
        }
    }
    return 0;
}