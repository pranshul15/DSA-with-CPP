#include<iostream>
using namespace std;

#define n 20

class q
{
private:
    int* arr;
    int front = -1;
    int back = -1;
public:
    q(){
        arr = new int[n];
    }

    void enqueue(int x){
        if(back == n-1){
            cout<<"stack overflow"<<endl;
            return;
        }
        
        back ++;
        arr[back] = x;
        if(front == -1){
            front ++;
        }
    }

    void dequeue(){
        if(front == -1 || front>back){
            cout<<"queue is empty"<<endl;
            return;
        }
        
        front ++;
        
    }

    int peek(){
        if(front == -1 || front>back){
            cout<<"queue is empty"<<endl;
            return -1;
        }
        return arr[front];
    }

    bool empty(){
        if(front == -1 || front > back){
            return true;
        }
        return false;
    }
};

int main(){
    q queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);

    cout<<queue.peek()<<endl;
    queue.dequeue();
    cout<<queue.peek()<<endl;
    queue.dequeue();
    cout<<queue.peek()<<endl;
    if(queue.empty()){
        cout<<"Empty queue"<<endl;
    }
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    if(queue.empty()){
        cout<<"Empty queue"<<endl;
    }


    return 0;
}