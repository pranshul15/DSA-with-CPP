/*
Create a data structure kStacks that represents k stacks. 
Implementation of kStacks should use only one array, i.e., 
k stacks should use the same array for storing elements. 

The following functions must be supported by k Stacks. 
push(int x, int sn) –> pushes x to stack number ‘sn’ where 
sn is from 0 to k-1 
pop(int sn) –> pops an element from stack number ‘sn’ where 
sn is from 0 to k-1 
*/
#include<iostream>
using namespace std;

class kStacks{
private:
    enum {
        EMPTY = -1,
        FULL = -2
    };
    int *arr;
    int *top;
    int *aux;
    int N;
    int k;
    int pointer;
public:
    kStacks(int k);
    void push(int x, int sn);
    int pop(int sn);

    void print();
};

int main() {
    kStacks st = kStacks(3);
    st.print();

    st.push(5,0);
    st.print();

    st.push(7,0);
    st.print();

    st.push(3,1);
    st.print();

    st.push(8,2);
    st.print();

    st.push(1,1);
    st.print();

    st.pop(0);
    st.print();
    return 0;
}

kStacks::kStacks(int m) {
    N = 10;
    k=m;
    arr = new int[N];
    top = new int[k];
    aux = new int[N];
    pointer = 0;
    
    for(int i=0 ; i<N ; ++i) {
        arr[i] = EMPTY;
    }
    
    for(int i=0 ; i<N-1 ; ++i) {
        aux[i] = i+1;
    }
    aux[N-1] = -1;
    
    for(int j=0 ; j<k ; ++j) {
        top[j] = EMPTY;
    }
}

void kStacks::push(int x, int sn) {
    if(pointer == FULL) {
        cout<<"Error: Stack Overflow\n";
        return;
    }
    
    // Place the element in the storage arr
    arr[pointer] = x;
    
    // Save the position for next pointer
    int next_aux_pointer = (aux[pointer]==-1)? FULL : aux[pointer];
    
    // Get the position for previous pointer
    int prev_top_pointer = top[sn];
    
    // Save the poistion for previous pointer in aux array
    aux[pointer] = prev_top_pointer;
    
    // Save the top of the stack (pointing position)
    top[sn] = pointer;
    
    // store the value for next pointer
    pointer = next_aux_pointer;
}

int kStacks::pop(int sn) {
    if(top[sn]==EMPTY) {
        cout<<"Error: Stack Underflow\n";
        return -1;
    }

    // Save the initial pointer
    int next_pointer = pointer;

    // set the pointer
    pointer = top[sn];

    // Empty the element from arr
    arr[pointer] = EMPTY;

    // get the previous element of stack
    int top_pointer = aux[pointer];

    // set the top of stack
    top[sn] = top_pointer;

    // set the aux
    aux[pointer] = next_pointer;
}

void kStacks::print() {
    cout<<"arr : ";
    for(int i=0 ; i<N ; ++i) {
        cout<<arr[i]<<" ";
    }
    cout<<"\ntop : ";
    for(int i=0 ; i<k ; ++i) {
        cout<<top[i]<<" ";
    }
    cout<<"\naux : ";
    for(int i=0 ; i<N ; ++i) {
        cout<<aux[i]<<" ";
    }
    cout<<"\n\n";
}