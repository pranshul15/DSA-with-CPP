#include<iostream>
#include<climits>
using namespace std;

void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

class MinHeap
{
private:
    int *harr;
    int capacity;
    int heap_size;
public:
    MinHeap(int capacity);
    int parent(int i){return (i-1)/2;}
    int left(int i){return (2*i)+1;}
    int right(int i){return (2*i)+2;}
    int getMin(){return harr[0];}
    void MinHeapify(int i);
    int extractMin();
    void decreaseKey(int i,int new_val);
    void insertKey(int i);
    void deleteKey(int i);
    ~MinHeap();
};

MinHeap::MinHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}

void MinHeap::insertKey(int key){
    if(heap_size == capacity){
        cout<<"\nOverflow: Could not insert Key\n";
        return;
    }

    // first insert new key at the end
    heap_size++;
    int i = heap_size-1;
    harr[i]=key;

    // fix if the minHeap property is violated
    while(i!=0 && harr[parent(i)]>harr[i]){
        swap(&harr[i],&harr[parent(i)]);
        i = parent(i);
    }
}

void MinHeap::decreaseKey(int i,int new_val){
    harr[i] = new_val;
    while(i!=0 && harr[parent(i)]>harr[i]){
        swap(&harr[parent(i)],&harr[i]);
        i = parent(i);
    }
}

void MinHeap::MinHeapify(int i){
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if(l<heap_size && harr[l]<harr[i]){
        smallest = l;
    }
    if(r<heap_size && harr[r]<harr[smallest]){
        smallest = r;
    }
    if(smallest != i){
        swap(&harr[i],&harr[smallest]);
        MinHeapify(smallest);
    }
}

int MinHeap::extractMin(){
    if(heap_size <= 0){
        cout<<"\nUnderflow: Cannot delete element\n";
        return INT_MAX;
    }
    if(heap_size == 1){
        heap_size--;
        return harr[0];
    }
    int root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    MinHeapify(0);

    return root;
}

void MinHeap::deleteKey(int i){
    decreaseKey(i,INT_MIN);
    extractMin();
}

MinHeap::~MinHeap()
{
}

int main(){
    MinHeap m(10);
    m.insertKey(3);
    m.insertKey(2);
    m.deleteKey(1);
    m.insertKey(15);
    m.insertKey(5);
    m.insertKey(4);
    m.insertKey(45);
    cout<< m.extractMin() << " ";
    cout << m.getMin() << " ";
    m.decreaseKey(2,1);
    cout<< m.getMin();
    return 0;
}