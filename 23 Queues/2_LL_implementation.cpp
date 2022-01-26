#include<iostream>
using namespace std;

class node
{    
public:
    int data;
    node* next;
    node(int val) {
        data = val;
        next = NULL;
    }
    // ~node() {}
};

class queue
{
private:
    node* front;
    node* back;
public:
    queue() {
        front = NULL;
        back = NULL;
    }

    void push(int val){
        node* n = new node(val);

        if(front == NULL){
            back = n;
            front = n;
        }

        back->next = n;
        back = back->next;
    }

    void pop(){
        if(front == NULL){
            cout<<"queue is empty"<<endl;
            return;
        }

        node* todelete = front;
        front = front->next;
        delete todelete;
    }

    int peek(){
        if(front == NULL){
            cout<<"stack underflow"<<endl;
        return -1;
        }
        return front->data;
    }

    bool empty(){
        if(front == NULL){
            return true;
        }
        return false;
    }
    // ~queue() {}
};

int main(){
    queue q;
    for(int i=1 ; i<=5 ; i++){
        q.push(i);
    }
    for(int i=1 ; i<=5 ; i++){
        cout<<q.peek()<<" ";
        q.pop();
        if(q.empty()){
            cout<<"stack underflow"<<endl;
        }
    }
    if(q.empty()){
        cout<<"stack underflow"<<endl;
    }
    
    return 0;
}