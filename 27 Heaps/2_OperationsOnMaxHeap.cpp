#include<iostream>
#include<climits>
using namespace std;

void swap(int *x,int *y){
    int temp = *y;
    *y = *x;
    *x = temp;
}

class MaxHeap
{
private:
    int heap_size;
    int capacity;
    int* harr;
public:
    MaxHeap(int cap);
    int parent(int i){return (i-1)/2;}
    int left(int i){return (2*i)+1;}
    int right(int i){return (2*i)+2;}
    int getMax(){return harr[0];}
    int extractMax();
    void insertKey(int k);
    void maxHeapify(int i);
    void increaceKey(int i,int new_key);
    void deleteKey(int i);
    ~MaxHeap();
};

MaxHeap::MaxHeap(int cap)
{
    cap = capacity;
    heap_size = 0;
    harr = new int[cap];
}

void MaxHeap::maxHeapify(int i){
    int l = left(i);
    int r = right(i);
    int largest = i;
    if(l<heap_size && harr[l]>harr[i]){
        largest = l;
    }
    if(r<heap_size && harr[r]>harr[largest]){
        largest = r;
    }
    if(largest != i){
        swap(&harr[largest],&harr[i]);
        maxHeapify(largest);
    }
}

void MaxHeap::insertKey(int key){
    if(heap_size == capacity){
        cout<<"\nOverflow : no key can be added\n";
        return;
    }
    
    heap_size++;
    int i = heap_size -1;
    harr[i] = key;

    while(i!=0 && harr[parent(i)]<harr[i]){
        swap(&harr[parent(i)],&harr[i]);
        i = parent(i);
    }
}

int MaxHeap::extractMax(){
    if(heap_size == 0){
        cout<<"\nUnderflow : no key available\n";
        return INT_MIN;
    }

    int root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    maxHeapify(0);
    return root;
}

void MaxHeap::increaceKey(int i,int new_key){
    harr[i] = new_key;
    while(i!=0 && harr[parent(i)]<harr[i]){
        swap(&harr[parent(i)],&harr[i]);
        i = parent(i);
    }
}

void MaxHeap::deleteKey(int i){
    increaceKey(i,INT_MAX);
    extractMax();
}

MaxHeap::~MaxHeap()
{
}

int main(){
    MaxHeap m(10);
    m.insertKey(5);
    m.insertKey(10);
    cout<< m.getMax() << " ";
    m.deleteKey(0);
    m.insertKey(15);
    m.insertKey(8);
    m.increaceKey(1,20);
    cout<< m.extractMax() << " ";
    return 0;
}