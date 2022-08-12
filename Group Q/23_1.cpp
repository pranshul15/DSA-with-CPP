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
};
class linked_list
{
private:
node* head;

node* reverse_k(node* &head,int k){
    int count=0;
    node* temp = head;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    if(count<k){
        return head;
    }

    node* prevptr = NULL;
    node* currptr = head;
    node* tempptr;
    int d=0;
    while(d<k){
        tempptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = tempptr;
        d++;
    }
    head->next = reverse_k(currptr,k);
    return prevptr;
}

public:
    linked_list() {
        head = NULL;
    }
    void add(int val){
        node* n = new node(val);
        
        if(head == NULL){
            head = n;
            return;
        }

        node* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = n;
    }

    void reverse_k(int k){
        head = reverse_k(head,k);
        return;
    }

    void print(){
        node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main(){
    linked_list ll;
    ll.add(11);
    ll.add(2);
    ll.add(32);
    ll.add(4);
    ll.add(10);
    ll.print();
    ll.reverse_k(3);

    ll.print();

    return 0;
}