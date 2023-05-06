/*
Create a data structure kQueues that represents k queues. 
Implementation of kQueues should use only one array, i.e., 
k queues should use the same array for storing elements. 
Following functions must be supported by kQueues.
    enqueue(int x, int qn) –> adds x to queue number ‘qn’ where qn is from 0 to k-1 
    dequeue(int qn) –> deletes an element from queue number ‘qn’ where qn is from 0 to k-1 
*/
#include<iostream>
using namespace std;

class kQueues{
private:
    int N;
    int k;
    int *arr;
    int *front;
    int *rear;
    int *aux;
    int pointer;
    enum {
        EMPTY = -1,
        FULL = -2
    };
public:
    kQueues( int c ) ;
    void enqueue( int x, int qn );
    int dequeue( int qn );
};

kQueues::kQueues(int c) {
    N = 10;
    k = c;
    arr = new int[N];
    front = new int[k];
    rear = new int[k];
    aux = new int[N];
    pointer = 0;

    for( int i=0 ; i<N ; ++i ) {
        arr[i] = EMPTY;
    }
    for( int i=0 ; i<k ; ++i ) {
        front[i] = EMPTY;
        rear[i] = EMPTY;
    }
    for( int i=0 ; i<N-1 ; ++i ) {
        aux[i] = i+1;
    }
    aux[N-1] = FULL;
}

void kQueues::enqueue( int x, int qn ) {
    if( pointer == FULL ) {
        cout<<"Error: Memory Overflow\n";
        return;
    }

    arr[pointer] = x;
    int next = aux[pointer];
    int prev_rear = rear[qn];
    if( front[qn] == EMPTY ) {
        front[qn] = pointer;
    }
    rear[qn] = pointer;
    aux[prev_rear] = pointer;
    pointer = next;
}

int kQueues::dequeue( int qn ) {
    if( front[qn]==EMPTY ) {
        cout<<"Error: Queue Empty\n";
        return -1;
    }
    int f = front[qn];
    int prev_pointer = pointer;
    int next_front = aux[f];
    arr[f] = EMPTY;
    front[qn] = next_front;
    if( next_front==EMPTY ) {
        rear[qn] = EMPTY;
    }
    pointer = f;
    aux[pointer] = prev_pointer;
}

int main() {
    return ;
}